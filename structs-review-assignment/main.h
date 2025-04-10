#ifndef MAIN_H
#define MAIN_H

#include "activity.h"

// Menu functions
void displayMenu();
int getChoice();
void addActivity(Activity activities[], int &size);
void removeActivityMenu(Activity activities[], int &size);
void searchActivityMenu(const Activity activities[], int size);

#endif