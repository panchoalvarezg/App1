#ifndef PARSER_H
#define PARSER_H

struct order {
    char pizza_name[64];
    char pizza_category[32];
    char date[16];
    char ingredients[256];
    int quantity;
    float total_price;
};

struct order *read_csv(const char *filename, int *numOrders);

#endif
