#ifndef STRING_DEAL_H
#define STRING_DEAL_H
#include "main.h"
void convert_int_into_str(int a,char *s);
void strcat_strcpy(char *first, char *tail, const char *color);
void fix_str_bug(char *s);

//sorting
void swap(node *x, node *y);
int partition(node *a, int begin, int end);
void quick_sort(node *a, int begin, int end);

#endif
