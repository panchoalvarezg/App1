#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/metrics.h"

// Función de utilidad para encontrar la pizza más vendida
char* pms(int *size, struct order *orders) {
    // Implementación aquí
}

// Función de utilidad para encontrar la pizza menos vendida
char* pls(int *size, struct order *orders) {
    // Implementación aquí
}

// Función de utilidad para encontrar la fecha con más ventas en términos de dinero
char* dms(int *size, struct order *orders) {
    // Implementación aquí
}

// Función de utilidad para encontrar la fecha con menos ventas en términos de dinero
char* dls(int *size, struct order *orders) {
    // Implementación aquí
}

// Función de utilidad para encontrar la fecha con más ventas en términos de cantidad de pizzas
char* dmsp(int *size, struct order *orders) {
    // Implementación aquí
}

// Función de utilidad para encontrar la fecha con menos ventas en términos de cantidad de pizzas
char* dlsp(int *size, struct order *orders) {
    // Implementación aquí
}

// Función de utilidad para calcular el promedio de pizzas por orden
char* apo(int *size, struct order *orders) {
    float total_pizzas = 0.0f;
    for (int i = 0; i < *size; ++i) {
        total_pizzas += orders[i].quantity;
    }
    float avg = total_pizzas / *size;
    char *result = malloc(64);
    snprintf(result, 64, "Promedio de pizzas por orden: %.2f", avg);
    return result;
}

// Función de utilidad para calcular el promedio de pizzas por día
char* apd(int *size, struct order *orders) {
    // Implementación aquí
}

// Función de utilidad para encontrar el ingrediente más vendido
char* ims(int *size, struct order *orders) {
    // Implementación aquí
}

// Función de utilidad para calcular la cantidad de pizzas por categoría vendidas
char* hp(int *size, struct order *orders) {
    // Implementación aquí
}

// Función para obtener la métrica correspondiente
metric_func get_metric(const char *name) {
    if (strcmp(name, "total_sales") == 0) {
        return total_sales;
    } else if (strcmp(name, "total_orders") == 0) {
        return total_orders;
    } else if (strcmp(name, "pms") == 0) {
        return pms;
    } else if (strcmp(name, "pls") == 0) {
        return pls;
    } else if (strcmp(name, "dms") == 0) {
        return dms;
    } else if (strcmp(name, "dls") == 0) {
        return dls;
    } else if (strcmp(name, "dmsp") == 0) {
        return dmsp;
    } else if (strcmp(name, "dlsp") == 0) {
        return dlsp;
    } else if (strcmp(name, "apo") == 0) {
        return apo;
    } else if (strcmp(name, "apd") == 0) {
        return apd;
    } else if (strcmp(name, "ims") == 0) {
        return ims;
    } else if (strcmp(name, "hp") == 0) {
        return hp;
    } else {
        return NULL;
    }
}
