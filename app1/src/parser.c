#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/parser.h"

struct order* read_csv(const char* filename, int* size) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("No se pudo abrir el archivo");
        return NULL;
    }

    int capacity = 1000;
    struct order* orders = malloc(sizeof(struct order) * capacity);
    *size = 0;

    char line[1024];

    // Saltar encabezado
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file)) {
        if (*size >= capacity) {
            capacity *= 2;
            orders = realloc(orders, sizeof(struct order) * capacity);
        }

        struct order o = {0}; // Inicializar la orden
        char* token = strtok(line, ",");
        int field = 0;

        while (token && field < 12) {
            // Quitar salto de línea si existe
            token[strcspn(token, "\r\n")] = 0;

            switch (field) {
                case 0: o.pizza_id = atoi(token); break;
                case 1: o.order_id = atoi(token); break;
                case 2: strncpy(o.pizza_name_id, token, sizeof(o.pizza_name_id)); break;
                case 3: o.quantity = atoi(token); break;
                case 4: strncpy(o.order_date, token, sizeof(o.order_date)); break;
                case 5: strncpy(o.order_time, token, sizeof(o.order_time)); break;
                case 6: o.unit_price = atof(token); break;
                case 7: o.total_price = atof(token); break;
                case 8: strncpy(o.pizza_size, token, sizeof(o.pizza_size)); break;
                case 9: strncpy(o.pizza_category, token, sizeof(o.pizza_category)); break;
                case 10: strncpy(o.pizza_ingredients, token, sizeof(o.pizza_ingredients)); break;
                case 11: strncpy(o.pizza_name, token, sizeof(o.pizza_name)); break;
            }

            token = strtok(NULL, ",");
            field++;
        }

        orders[*size] = o;
        (*size)++;
    }

    fclose(file);
    return orders;
}
