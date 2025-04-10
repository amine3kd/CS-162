#include "activity.h"

void loadActivities(Activity activities[], int &size) {
    std::ifstream inFile("activities.txt");
    size = 0;

    if (!inFile) return;

    while (inFile.getline(activities[size].name, MAX_NAME_LENGTH, '|')) {
        inFile.getline(activities[size].location, MAX_LOCATION_LENGTH, '|');
        inFile.getline(activities[size].type, MAX_TYPE_LENGTH, '|');
        inFile >> activities[size].distance;
        inFile.ignore(); // skip newline
        size++;
    }
    inFile.close();
}

void saveActivities(const Activity activities[], int size) {
    std::ofstream outFile("activities.txt");

    for (int i = 0; i < size; ++i) {
        outFile << activities[i].name << '|'
                << activities[i].location << '|'
                << activities[i].type << '|'
                << activities[i].distance << '\n';
    }
    outFile.close();
}

void insertActivity(Activity activities[], int &size, const Activity &newActivity) {
    int pos = 0;
    while (pos < size && strcmp(activities[pos].name, newActivity.name) < 0) {
        ++pos;
    }
    for (int i = size; i > pos; --i) {
        activities[i] = activities[i - 1];
    }
    activities[pos] = newActivity;
    ++size;
}

void removeActivity(Activity activities[], int &size, const char name[]) {
    int pos = -1;
    for (int i = 0; i < size; ++i) {
        if (strcmp(activities[i].name, name) == 0) {
            pos = i;
            break;
        }
    }
    if (pos != -1) {
        for (int i = pos; i < size - 1; ++i) {
            activities[i] = activities[i + 1];
        }
        --size;
    }
}

void displayActivities(const Activity activities[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << activities[i].name << " | "
                  << activities[i].location << " | "
                  << activities[i].type << " | "
                  << activities[i].distance << " mins\n";
    }
}

void searchByType(const Activity activities[], int size, const char type[]) {
    for (int i = 0; i < size; ++i) {
        if (strcmp(activities[i].type, type) == 0) {
            std::cout << activities[i].name << " | "
                      << activities[i].location << " | "
                      << activities[i].distance << " mins\n";
        }
    }
}