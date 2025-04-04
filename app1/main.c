#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "metrics.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s archivo.csv metrica1 metrica2 ...\n", argv[0]);
        return 1;
    }

    int numOrders;
    struct order *orders = read_csv(argv[1], &numOrders);
    if (!orders) {
        printf("Error leyendo el archivo.\n");
        return 1;
    }

    for (int i = 2; i < argc; ++i) {
        metric_func func = get_metric(argv[i]);
        if (func) {
            char *result = func(&numOrders, orders);
            printf("%s\n", result);
            free(result);
        } else {
            printf("Métrica '%s' no reconocida.\n", argv[i]);
        }
    }

    free(orders);
    return 0;
}
