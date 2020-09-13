#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "string_deal.h"
#include "main.h" //contain definition of struct "node"

void convert_int_into_str(int a, char *s){
  int count = 0, juu = a/10;
  if(juu == 0) s[count++] = a+48;
  else{
    while(juu >0){
      if(juu != 0) s[count++] = juu+48;
      
      a = a - juu*10;
      s[count++] = a+48;
      juu = a/10;
    }//while
    s[count] = '\0';
  }//else juu != 0
}

void fix_str_bug(char *s){
  for(int i=0;i<strlen(s);i++){
    if(!isdigit(s[i])){
	s[i] = '\0';
	break;
      }
  }
}
      
void strcat_strcpy(char *first, char *tail, const char *color){
  strcpy(first,"<span foreground='");
  strcat(first,color);
  strcat(first,"' weight='bold' font='14.5'> ");
  strcat(first,tail);
  strcat(first," </span>");
}

void swap(node *x, node *y){
  node temp = *x;
  *x = *y;
  *y = temp;
}

int partition(node *a, int begin, int end){
  int pivot = a[begin].score;
  int i = begin, j = end+1; //NOTE "j = end+1", not "end"

  while(1){
    i++; //right after a[begin] = pivot
    //find the first number which is smaller than pivot
    while(i<=end && a[i].score > pivot)i++;

    j--; //right before a[end]
    //find the first number which is bigger than pivot
    while(j>=begin && a[j].score < pivot)j--;
    if(i>=j) break;
    swap(&a[i],&a[j]);
  }
  swap(&a[begin],&a[j]);
  return j;
}

void quick_sort(node *a, int begin, int end){
  if(begin < end){
    int pivot = partition(a,begin,end);
    quick_sort(a,begin,pivot-1);
    quick_sort(a,pivot+1,end);
  }
}



