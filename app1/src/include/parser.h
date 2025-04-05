#ifndef PARSER_H
#define PARSER_H

struct order {
    int pizza_id;
    int order_id;
    char pizza_name_id[50];
    int quantity;
    char order_date[20];
    char order_time[20];
    float unit_price;
    float total_price;
    char pizza_size[10];           // antes 5
    char pizza_category[50];
    char pizza_ingredients[300];   // antes 200
    char pizza_name[100];
};

struct order* read_csv(const char* filename, int* size);

#endif
