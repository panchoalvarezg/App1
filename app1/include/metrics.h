#ifndef METRICS_H
#define METRICS_H
#include "src/parser.h"

typedef char* (*metric_func)(int *size, struct order *orders);
metric_func get_metric(const char *name);

#endif
