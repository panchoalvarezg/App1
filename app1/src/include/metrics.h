#ifndef METRICS_H
#define METRICS_H
#include "src/parser.h"

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

#endif
