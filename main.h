#ifndef MAIN_H
#define MAIN_H

#include "gtk/gtk.h"
#include <stdio.h>

#define MAX_QUES 31
int kotae[MAX_QUES];

FILE *rank;
FILE *opn;
FILE *human_txt;

typedef struct{
  char name[20];
  int score;
}node;

GtkBuilder *builder;

//right_annouce & //wrong_annouce
GtkWidget *right_annouce;
GtkWidget *wrong_annouce;

//intro_window
GtkWidget *intro_window;
GtkEntry *nickname_entry;

//rank_window
GtkWidget *rank_window;
GtkLabel *final_score_label;
GtkTextView *nickname_text_view;
GtkTextBuffer *rank_nickname_buff;

GtkTextView *score_text_view;
GtkTextBuffer *final_score_buff;

//lack-nickname window
GtkWidget *lack_nickname_wd;

//general_wdn_bamboo
GtkWidget *general_wdn_bamboo;

GtkLabel *qa_bamboo_label;
GtkLabel *junban_bamboo_label;
GtkLabel *score_now_bamboo_label;

//general_wdn_lotus
GtkWidget *general_wdn_lotus;

GtkLabel *qa_lotus_label;
GtkLabel *junban_lotus_label;
GtkLabel *score_now_lotus_label;

//confirm destroy window
GtkWidget *delete_all_confirm_wdn;
#endif
