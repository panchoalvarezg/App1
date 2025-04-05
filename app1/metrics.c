#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metrics.h"

char* total_sales(int *size, struct order *orders) {
    float total = 0.0f;
    for (int i = 0; i < *size; ++i) {
        total += orders[i].total_price;
    }
    char *result = malloc(64);
    snprintf(result, 64, "Total de ventas: %.2f", total);
    return result;
}

char* total_orders(int *size, struct order *orders) {
    char *result = malloc(64);
    snprintf(result, 64, "Total de órdenes: %d", *size);
    return result;
}

metric_func get_metric(const char *name) {
    if (strcmp(name, "total_sales") == 0) {
        return total_sales;
    } else if (strcmp(name, "total_orders") == 0) {
        return total_orders;
    } else {
        return NULL;
    }
}
