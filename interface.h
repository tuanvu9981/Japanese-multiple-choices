#ifndef INTERFACE_H
#define INTERFACE_H

//introduction window
void interface_begin();
void on_hajime_btn_clicked();

//lack nickname window
void on_back_intro_btn_clicked();

//lotus and bamboo
void on_btnA_clicked();
void on_btnB_clicked();
void on_btnC_clicked();
void on_btnD_clicked();

//right and wrong
void on_right_annouce_destroy();
void on_wrong_annouce_destroy();

void on_next_btn_clicked();

//ALL
void turn_off_all();
#endif
