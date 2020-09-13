#include <stdio.h>
#include "interface.h"
#include "init.h"
#include "string_deal.h"
#include "main.h"

#define RIGHT_WDN 1
#define WRONG_WDN 0
gchar *nickname;
int score = 0, where = -1, count = 0, thutu = 0, human;

//intro_window
void interface_begin(){
  gtk_widget_show(GTK_WIDGET(intro_window));
}

void on_hajime_btn_clicked(){
   nickname = (gchar*) gtk_entry_get_text(GTK_ENTRY(nickname_entry));
  if(strlen(nickname) <=0) {
    gtk_widget_show(GTK_WIDGET(lack_nickname_wd));
  }
  else{
    human_txt = fopen("human.txt","r");
    if(human_txt == NULL) return;
    fscanf(human_txt,"%d\n",&human);
    fclose(human_txt);
    human++;

    human_txt = fopen("human.txt","w");
    if(human_txt == NULL) return;
    fprintf(human_txt,"%d\n",human);
    fclose(human_txt);
    
    gtk_widget_hide(GTK_WIDGET(intro_window));
    opn = fopen("question.txt","r");

    gchar show[100]; char str[500];
    gchar score_new[5];char score_c[5];
    gchar order[5]; char junban[5];

    (thutu)++;
    strcpy(order,"");
    convert_int_into_str(thutu,order);
    strcat_strcpy(junban,order,"blue");
    gtk_label_set_markup(GTK_LABEL(junban_lotus_label), junban);

    strcpy(score_new,"");
    convert_int_into_str(score,score_new);
    fix_str_bug(score_new);//REMEMBER THIS FATAL ERROR LINE
    strcat_strcpy(score_c,score_new,"red");
    gtk_label_set_markup(GTK_LABEL(score_now_lotus_label), score_c);

    strcpy(str,"");
    fscanf(opn,"%[^#]%*c",str);
    strcat_strcpy(show,str,"black");
    gtk_label_set_markup(GTK_LABEL(qa_lotus_label), show);
    
    gtk_widget_show(GTK_WIDGET(general_wdn_lotus));
  }
}

//lack nickname window
void on_back_intro_btn_clicked(){
  gtk_widget_hide(GTK_WIDGET(lack_nickname_wd));
}

//general_question_window
void on_btnA_clicked(){
  if(kotae[thutu-1] == 1) {
    gtk_widget_show(GTK_WIDGET(right_annouce));
    where = RIGHT_WDN;
    score++;
  }
  else{
    gtk_widget_show(GTK_WIDGET(wrong_annouce));
    where = WRONG_WDN;
  }
}
void on_btnB_clicked(){
  if(kotae[thutu-1] == 2) {
    gtk_widget_show(GTK_WIDGET(right_annouce));
    where = RIGHT_WDN;
    score++;
  }
  else{
    gtk_widget_show(GTK_WIDGET(wrong_annouce));
    where = WRONG_WDN;
  }
}
void on_btnC_clicked(){
  if(kotae[thutu-1] == 3) {
    gtk_widget_show(GTK_WIDGET(right_annouce));
    where = RIGHT_WDN;
    score++;
  }
  else{
    gtk_widget_show(GTK_WIDGET(wrong_annouce));
    where = WRONG_WDN;
  }
}
void on_btnD_clicked(){
  if(kotae[thutu-1] == 4) {
    gtk_widget_show(GTK_WIDGET(right_annouce));
    where = RIGHT_WDN;
    score++;
  }
  else{
    gtk_widget_show(GTK_WIDGET(wrong_annouce));
    where = WRONG_WDN;
  }
}

//right and wrong annoucement
void on_next_btn_clicked(){
  if(where == RIGHT_WDN) gtk_widget_hide(GTK_WIDGET(right_annouce));
  else if (where == WRONG_WDN) gtk_widget_hide(GTK_WIDGET(wrong_annouce));

  if((thutu-1)%2 == 1) gtk_widget_hide(GTK_WIDGET(general_wdn_bamboo));
  else if((thutu-1)%2 == 0) gtk_widget_hide(GTK_WIDGET(general_wdn_lotus));

  gchar show1[100]; char str1[500];
  gchar score_new1[5];char score_c1[40];
  gchar order1[5]; char junban1[40];
  if(thutu == MAX_QUES - 1){
    fclose(opn);
    rank = fopen("ranking.txt","a");
    if(rank == NULL) {
      printf("Cannot open \"ranking.txt\" in next_btn \n");
      return;
    }
    fprintf(rank,"%s\t%d\n",nickname,score);
    fclose(rank);
    
    node node[human];
    char name1[20], final_score[5];
    
    convert_int_into_str(score,final_score);
    fix_str_bug(final_score);
    strcat_strcpy(score_c1,final_score,"black");
    gtk_label_set_markup(GTK_LABEL(final_score_label),score_c1);

    rank = fopen("ranking.txt","r");
    for(int i=0;i<human;i++){
      fscanf(rank,"%s\t%d\n",name1,&node[i].score);
      strcpy(node[i].name,name1);
    }
    fclose(rank);
    quick_sort(node,0,human-1);

    for(int k=0;k<human;k++){
      gtk_text_buffer_insert_at_cursor(rank_nickname_buff,node[k].name,-1);
      gtk_text_buffer_insert_at_cursor(rank_nickname_buff,"\n",-1);
      strcpy(final_score,"");
      convert_int_into_str(node[k].score,final_score);
      fix_str_bug(final_score);//REMEMBER THIS FATAL ERROR LINE    
      gtk_text_buffer_insert_at_cursor(final_score_buff,final_score,-1);
      gtk_text_buffer_insert_at_cursor(final_score_buff,"\n",-1);
    }

    gtk_widget_show(GTK_WIDGET(rank_window));
  }
  else if (thutu < MAX_QUES-1){
    if(thutu %2 == 0){
      (thutu)++;
      strcpy(order1,"");
      convert_int_into_str(thutu,order1);
      strcat_strcpy(junban1,order1,"blue");
      gtk_label_set_markup(GTK_LABEL(junban_lotus_label), junban1);

      strcpy(score_new1,"");
      convert_int_into_str(score,score_new1);
      fix_str_bug(score_new1);//REMEMBER THIS FATAL ERROR LINE
      strcat_strcpy(score_c1,score_new1,"red");
      gtk_label_set_markup(GTK_LABEL(score_now_lotus_label), score_c1);

      strcpy(str1,"");
      fscanf(opn,"%[^#]%*c",str1);
      strcat_strcpy(show1,str1,"black");
      gtk_label_set_markup(GTK_LABEL(qa_lotus_label), show1);
    
      gtk_widget_show(GTK_WIDGET(general_wdn_lotus));
    }
    else if (thutu %2 == 1){
      (thutu)++;
      strcpy(order1,"");
      convert_int_into_str(thutu,order1);
      strcat_strcpy(junban1,order1,"blue");
      gtk_label_set_markup(GTK_LABEL(junban_bamboo_label), junban1);

      strcpy(score_new1,"");
      convert_int_into_str(score,score_new1);
      fix_str_bug(score_new1);//REMEMBER THIS FATAL ERROR LINE
      strcat_strcpy(score_c1,score_new1,"red");
      gtk_label_set_markup(GTK_LABEL(score_now_bamboo_label), score_c1);

      strcpy(str1,"");
      fscanf(opn,"%[^#]%*c",str1);
      strcat_strcpy(show1,str1,"black");
      gtk_label_set_markup(GTK_LABEL(qa_bamboo_label), show1);
    
      gtk_widget_show(GTK_WIDGET(general_wdn_bamboo));
    }
  }//thu tu <MAX_QUES
}

//Quit right annoucement window
void on_right_annouce_destroy(){
  gtk_widget_hide(GTK_WIDGET(right_annouce));
}

//Quit wrong annoucement window
void on_wrong_annouce_destroy(){
  gtk_widget_hide(GTK_WIDGET(wrong_annouce));
}

//ALL
void turn_off_all(){
  gtk_main_quit();
}

//confirm destroy window
void on_agree_clear_all_btn_clicked(){
  rank = fopen("ranking.txt","w");
  if(rank == NULL) {
    printf("Cannot open \"ranking.txt\" in agree_clear_all \n");
    return;
  }
  fclose(rank);

  human_txt = fopen("human.txt","w");
  if(human_txt == NULL) return;
  fprintf(human_txt,"%d\n",WRONG_WDN);
  fclose(human_txt);
  gtk_main_quit();
}

void on_dont_agree_clear_btn_clicked(){
  gtk_widget_hide(GTK_WIDGET(delete_all_confirm_wdn));
}

//ranking window
void on_destroy_data_btn_clicked(){
  gtk_widget_show(GTK_WIDGET(delete_all_confirm_wdn));
}
