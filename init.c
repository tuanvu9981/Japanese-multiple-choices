#include "init.h"

void general_gtk_init(){  
  builder = gtk_builder_new();
  gtk_builder_add_from_file(builder,"glade_file/jap1.glade",NULL);
  gtk_builder_connect_signals(builder,NULL);

  //intro_window
  intro_window = GTK_WIDGET(gtk_builder_get_object(builder,"intro_window"));
  nickname_entry = GTK_ENTRY(gtk_builder_get_object(builder,"nickname_input_entry"));

  //right_annouce_window & //wrong_annouce_window
  right_annouce = GTK_WIDGET(gtk_builder_get_object(builder,"right_annouce"));
  wrong_annouce = GTK_WIDGET(gtk_builder_get_object(builder,"wrong_annouce"));

  //ranking_window
  rank_window = GTK_WIDGET(gtk_builder_get_object(builder,"rank_window"));

  rank_nickname_buff = gtk_text_buffer_new(NULL);
  nickname_text_view = GTK_TEXT_VIEW(gtk_builder_get_object(builder,"nickname_text_view"));
  gtk_text_view_set_buffer(nickname_text_view,rank_nickname_buff);

  final_score_buff = gtk_text_buffer_new(NULL);
  score_text_view = GTK_TEXT_VIEW(gtk_builder_get_object(builder,"score_text_view"));
  gtk_text_view_set_buffer(score_text_view,final_score_buff);
  
  final_score_label = GTK_LABEL(gtk_builder_get_object(builder,"final_score_label"));

  //lack nickname window
  lack_nickname_wd = GTK_WIDGET(gtk_builder_get_object(builder,"lack_nickname_wd"));

  //general_window_bamboo
  general_wdn_bamboo = GTK_WIDGET(gtk_builder_get_object(builder,"general_wdn_bamboo"));

  qa_bamboo_label = GTK_LABEL(gtk_builder_get_object(builder,"qa_bamboo_label"));
  junban_bamboo_label = GTK_LABEL(gtk_builder_get_object(builder,"junban_bamboo_label"));
  score_now_bamboo_label = GTK_LABEL(gtk_builder_get_object(builder,"score_now_bamboo_label"));

  //general_window_lotus
  general_wdn_lotus = GTK_WIDGET(gtk_builder_get_object(builder,"general_wdn_lotus"));
  
  qa_lotus_label = GTK_LABEL(gtk_builder_get_object(builder,"qa_lotus_label"));
  junban_lotus_label = GTK_LABEL(gtk_builder_get_object(builder,"junban_lotus_label"));
  score_now_lotus_label = GTK_LABEL(gtk_builder_get_object(builder,"score_now_lotus_label"));

  //confirm destroy window
  delete_all_confirm_wdn = GTK_WIDGET(gtk_builder_get_object(builder,"delete_all_confirm_wdn"));
}
