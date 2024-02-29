#ifndef __MINISET_H

#define __MINISET_H

#define MAX_SET 20
#define FALSE 0
#define TRUE 1

// API for manipulating simple arithmetic (int, int) sets

void init_set(int set[]);

int in_set(int set[], int a, int b);

int add_to_set(int set[], int a, int b);

int remove_from_set(int set[], int a, int b);

int num_elements(int set[]);

void print_set(int set[]);

#endif