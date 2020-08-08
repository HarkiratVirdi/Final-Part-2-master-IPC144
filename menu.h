#ifdef MENU_H
#define MENU_H

#include "file_helper.h"


int menu(struct SkierInfo* skiers, int size);
void printTop3(struct SkierInfo* skiers, int size);
void printAll(struct SkierInfo* skiers, int size);
void printLast3(struct SkierInfo* skiers, int size);
void printWinners(struct SkierInfo* skiers, int size);


int getMenuOption();
int getInt();
int getIntInRange(int min, int max);
char getCategory();
void clearKeyboard(void);

void displayAgeGroup(const int age,char ageGroup);
void displayTime(double startTime, double finishTime,int withdrawn);






#endif
