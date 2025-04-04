#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metrics.h"

char *apo(int *size, struct order *orders) {
    float totalPizzas = 0;
    int totalOrders = 0;

    for (int i = 0; i < *size; i++) {
        totalPizzas += orders[i].quantity;
        totalOrders++;
    }

    float avg = totalPizzas / totalOrders;

    char *result = malloc(128);
    snprintf(result, 128, "Promedio de pizzas por orden: %.2f", avg);
    return result;
}

metric_func get_metric(const char *name) {
    if (strcmp(name, "apo") == 0) return apo;
    // Agregar más métricas aquí
    return NULL;
}
