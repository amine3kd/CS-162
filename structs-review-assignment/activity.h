#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <iostream>
#include <fstream>
#include <cstring>

const int MAX_ACTIVITIES = 100;
const int MAX_NAME_LENGTH = 50;
const int MAX_LOCATION_LENGTH = 50;
const int MAX_TYPE_LENGTH = 20;

struct Activity {
    char name[MAX_NAME_LENGTH];
    char location[MAX_LOCATION_LENGTH];
    char type[MAX_TYPE_LENGTH];
    int distance; // in minutes
};

// Function prototypes
void loadActivities(Activity activities[], int &size);
void saveActivities(const Activity activities[], int size);
void insertActivity(Activity activities[], int &size, const Activity &newActivity);
void removeActivity(Activity activities[], int &size, const char name[]);
void displayActivities(const Activity activities[], int size);
void searchByType(const Activity activities[], int size, const char type[]);

#endif
