#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/parser.h"

#define MAX_LINE 512
#define MAX_ORDERS 10000

struct order *read_csv(const char *filename, int *numOrders) {
    FILE *file = fopen(filename, "r");
    if (!file) return NULL;

    struct order *orders = malloc(sizeof(struct order) * MAX_ORDERS);
    char line[MAX_LINE];
    *numOrders = 0;

    fgets(line, MAX_LINE, file); // skip header

    while (fgets(line, MAX_LINE, file)) {
        if (*numOrders >= MAX_ORDERS) break;

        struct order o;
        char *token = strtok(line, ",");

        int col = 0;
        while (token) {
            switch (col) {
                case 2: strncpy(o.pizza_name, token, 63); break;
                case 4: strncpy(o.date, token, 15); break;
                case 6: o.total_price = atof(token); break;
                case 7: o.total_price = atof(token); break;
                case 8: // tamaño pizza (ignorado)
                    break;
                case 9: strncpy(o.pizza_category, token, 31); break;
                case 10: strncpy(o.ingredients, token, 255); break;
                case 3: o.quantity = atoi(token); break;
            }
            token = strtok(NULL, ",");
            col++;
        }

        orders[*numOrders] = o;
        (*numOrders)++;
    }

    fclose(file);
    return orders;
}
