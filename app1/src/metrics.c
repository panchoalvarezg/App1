#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> // Para INT_MAX
#include <float.h>  // Para FLT_MAX
#include "include/metrics.h"
#include "include/parser.h"


// Función de utilidad para encontrar la pizza más vendida
char* pms(int *size, struct order *orders) {
    // Contar la frecuencia de cada tipo de pizza
    int max_count = 0;
    char* most_sold_pizza = NULL;
    for (int i = 0; i < *size; ++i) {
        int count = 0;
        for (int j = 0; j < *size; ++j) {
            if (strcmp(orders[i].pizza_name, orders[j].pizza_name) == 0) {
                count += orders[j].quantity;
            }
        }
        if (count > max_count) {
            max_count = count;
            most_sold_pizza = orders[i].pizza_name;
        }
    }
    char *result = malloc(64);
    snprintf(result, 64, "Pizza más vendida: %s", most_sold_pizza);
    return result;
}



char* pls(int *size, struct order *orders) {
    int min_count = INT_MAX;
    char* least_sold_pizza = NULL;

    for (int i = 0; i < *size; ++i) {
        // Evitar contar dos veces la misma pizza
        int ya_contada = 0;
        for (int k = 0; k < i; ++k) {
            if (strcmp(orders[i].pizza_name, orders[k].pizza_name) == 0) {
                ya_contada = 1;
                break;
            }
        }
        if (ya_contada) continue;

        // Contar cuántas veces se vendió esta pizza
        int count = 0;
        for (int j = 0; j < *size; ++j) {
            if (strcmp(orders[i].pizza_name, orders[j].pizza_name) == 0) {
                count += orders[j].quantity;
            }
        }

        if (count < min_count) {
            min_count = count;
            least_sold_pizza = orders[i].pizza_name;
        }
    }

    char *result = malloc(128);
    snprintf(result, 128, "Pizza menos vendida: %s (%d ventas)", least_sold_pizza, min_count);
    return result;
}




char* dms(int *size, struct order *orders) {
    // Sumar las ventas por fecha
    float max_sales = 0.0f;
    char* max_sales_date = NULL;
    for (int i = 0; i < *size; ++i) {
        float sales = 0.0f;
        for (int j = 0; j < *size; ++j) {
            // Comparar las fechas de las órdenes
            if (strcmp(orders[i].order_date, orders[j].order_date) == 0) {
                // Sumar el precio total de las órdenes con la misma fecha
                sales += orders[j].total_price;
            }
        }
        // Actualizar la fecha con más ventas si las ventas actuales son mayores que el máximo registrado
        if (sales > max_sales) {
            max_sales = sales;
            max_sales_date = orders[i].order_date;
        }
    }

    // Verificar si se encontró alguna fecha con ventas
    if (max_sales_date == NULL) {
        return strdup("No se encontraron ventas.");
    }

    // Reservar memoria para el resultado y formatear la cadena de salida
    char *result = malloc(64);
    if (result == NULL) {
        // Manejar el error de asignación de memoria
        return NULL;
    }
    snprintf(result, 64, "Fecha con más ventas: %s", max_sales_date);
    return result;
}



// Función de utilidad para encontrar la fecha con menos ventas
char* dls(int *size, struct order *orders) {
    if (*size <= 0 || orders == NULL) {
        return strdup("No se encontraron ventas.");
    }

    float min_sales = FLT_MAX;
    char* min_sales_date = NULL;

    for (int i = 0; i < *size; ++i) {
        float sales = 0.0f;

        for (int j = 0; j < *size; ++j) {
            if (strcmp(orders[i].order_date, orders[j].order_date) == 0) {
                sales += orders[j].total_price;
            }
        }

        // Imprimir ventas y fecha actual para depuración
        printf("Fecha: %s, Ventas: %.2f\n", orders[i].order_date, sales);

        if (sales < min_sales) {
            min_sales = sales;
            free(min_sales_date);
            min_sales_date = strdup(orders[i].order_date);
            if (min_sales_date == NULL) {
                fprintf(stderr, "Error duplicating date string\n");
                return NULL;
            }
        }
    }

    if (min_sales_date == NULL) {
        return strdup("No se encontraron ventas.");
    }

    char *result = malloc(64);
    if (result == NULL) {
        free(min_sales_date);
        return NULL;
    }
    snprintf(result, 64, "Fecha con menos ventas: %s", min_sales_date);
    free(min_sales_date);
    return result;
}


// Función de utilidad para encontrar la fecha con más ventas en términos de cantidad de pizzas
char* dmsp(int *size, struct order *orders) {
    // Contar la cantidad total de pizzas vendidas por fecha
    int max_pizzas = 0;
    char* max_pizzas_date = NULL;
    for (int i = 0; i < *size; ++i) {
        int pizzas = 0;
        for (int j = 0; j < *size; ++j) {
            if (strcmp(orders[i].order_date, orders[j].order_date) == 0) {
                pizzas += orders[j].quantity;
            }
        }
        if (pizzas > max_pizzas) {
            max_pizzas = pizzas;
            max_pizzas_date = orders[i].order_date;
        }
    }
    char *result = malloc(64);
    snprintf(result, 64, "Fecha con más pizzas vendidas: %s", max_pizzas_date);
    return result;
}



// Función para encontrar la fecha con menos ventas en términos de cantidad de pizzas
char* dlsp(int *size, struct order *orders) {
    int min_pizzas = INT_MAX;
    char** min_pizzas_dates = NULL;
    int min_dates_count = 0;

    for (int i = 0; i < *size; ++i) {
        int pizzas = 0;
        for (int j = 0; j < *size; ++j) {
            if (strcmp(orders[i].order_date, orders[j].order_date) == 0) {
                pizzas += orders[j].quantity;
            }
        }

        // Imprimir cantidad de pizzas y fecha actual para depuración
        printf("Fecha: %s, Pizzas: %d\n", orders[i].order_date, pizzas);

        if (pizzas < min_pizzas) {
            min_pizzas = pizzas;

            // Liberar memoria anterior y actualizar la lista de fechas
            if (min_pizzas_dates != NULL) {
                for (int k = 0; k < min_dates_count; ++k) {
                    free(min_pizzas_dates[k]);
                }
                free(min_pizzas_dates);
            }

            min_pizzas_dates = malloc(sizeof(char*));
            min_pizzas_dates[0] = strdup(orders[i].order_date);
            min_dates_count = 1;
        } else if (pizzas == min_pizzas) {
            // Agregar la fecha a la lista en caso de empate
            min_pizzas_dates = realloc(min_pizzas_dates, (min_dates_count + 1) * sizeof(char*));
            min_pizzas_dates[min_dates_count] = strdup(orders[i].order_date);
            min_dates_count++;
        }
    }

    if (min_dates_count == 0) {
        return strdup("No se encontraron ventas.");
    }

    // Crear el resultado
    size_t result_size = 64 + (min_dates_count * 20);
    char *result = malloc(result_size);
    if (result == NULL) {
        for (int k = 0; k < min_dates_count; ++k) {
            free(min_pizzas_dates[k]);
        }
        free(min_pizzas_dates);
        return NULL;
    }

    snprintf(result, result_size, "Fecha(s) con menos pizzas vendidas: ");
    for (int k = 0; k < min_dates_count; ++k) {
        strncat(result, min_pizzas_dates[k], 20);
        if (k < min_dates_count - 1) {
            strncat(result, ", ", 2);
        }
    }

    // Liberar memoria
    for (int k = 0; k < min_dates_count; ++k) {
        free(min_pizzas_dates[k]);
    }
    free(min_pizzas_dates);

    return result;
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
    // Contar la cantidad total de pizzas vendidas por día
    int total_pizzas = 0;
    int total_days = 0;
    for (int i = 0; i < *size; ++i) {
        int pizzas = 0;
        for (int j = 0; j < *size; ++j) {
            if (strcmp(orders[i].order_date, orders[j].order_date) == 0) {
                pizzas += orders[j].quantity;
            }
        }
        total_pizzas += pizzas;
        total_days++;
    }
    float avg = (float) total_pizzas / total_days;
    char *result = malloc(64);
    snprintf(result, 64, "Promedio de pizzas por día: %.2f", avg);
    return result;
}



// Función de utilidad para encontrar el ingrediente más vendido
char* ims(int *size, struct order *orders) {
    // Contar la frecuencia de cada ingrediente
    int max_count = 0;
    char* most_sold_ingredient = NULL;
    for (int i = 0; i < *size; ++i) {
        char* ingredients = strtok(orders[i].pizza_ingredients, ",");
        while (ingredients != NULL) {
            int count = 0;
            for (int j = 0; j < *size; ++j) {
                if (strstr(orders[j].pizza_ingredients, ingredients) != NULL) {
                    count += orders[j].quantity;
                }
            }
            if (count > max_count) {
                max_count = count;
                most_sold_ingredient = ingredients;
            }
            ingredients = strtok(NULL, ",");
        }
    }
    char *result = malloc(64);
    snprintf(result, 64, "Ingrediente más vendido: %s", most_sold_ingredient);
    return result;
}



// Función de utilidad para calcular la cantidad de pizzas por categoría vendidas
char* hp(int *size, struct order *orders) {
    // Contar la cantidad total de pizzas vendidas por categoría
    int classic_count = 0;
    int veggie_count = 0;
    for (int i = 0; i < *size; ++i) {
        if (strcmp(orders[i].pizza_category, "Classic") == 0) {
            classic_count += orders[i].quantity;
        } else if (strcmp(orders[i].pizza_category, "Veggie") == 0) {
            veggie_count += orders[i].quantity;
        }
    }
    char *result = malloc(128);
    snprintf(result, 128, "Cantidad de pizzas vendidas por categoría:\nClassic: %d\nVeggie: %d", classic_count, veggie_count);
    return result;
}



// Función para obtener la métrica correspondiente
metric_func get_metric(const char *name) {
    if (strcmp(name, "pms") == 0) {
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
