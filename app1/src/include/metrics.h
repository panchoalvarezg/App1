#ifndef METRICS_H
#define METRICS_H

#include "parser.h"
#include <stdlib.h> // Para malloc y free

int pizza_name_ya_contada(const char *pizza_name, char **nombres_contados, int nombres_guardados);


typedef char* (*metric_func)(int *size, struct order *orders);
metric_func get_metric(const char *name);

// Declaraciones de las nuevas funciones
char* pms(int *size, struct order *orders);
char* pls(int *size, struct order *orders);
char* dms(int *size, struct order *orders);
char* dls(int *size, struct order *orders);
char* dmsp(int *size, struct order *orders);
char* dlsp(int *size, struct order *orders);
char* apo(int *size, struct order *orders);
char* apd(int *size, struct order *orders);
char* ims(int *size, struct order *orders);
char* hp(int *size, struct order *orders);

#endif // METRICS_H
