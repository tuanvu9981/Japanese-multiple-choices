#include <stdio.h>
#include <stdlib.h>
#include "gtk/gtk.h"
#include "interface.h"
#include "main.h"
#include "init.h"
//#include "cvector/cvector.h"

int main(int argc, char *argv[]){
  FILE *kai = fopen("answer.txt","r");
  if(kai == NULL){
    printf("Cannot open answer.txt\n");
    return -1;
  }
  int sample;
  for(int i=0;i<MAX_QUES-1;i++) {
    fscanf(kai,"%d\n",&sample);
    kotae[i] = sample;
  }

  
  gtk_init(&argc,&argv);
  general_gtk_init();

  interface_begin();
  gtk_main();
}

