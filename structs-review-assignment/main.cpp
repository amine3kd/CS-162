#include "main.h"

void displayMenu() {
    std::cout << "\nActivity Manager\n";
    std::cout << "1. Display all activities\n";
    std::cout << "2. Add an activity\n";
    std::cout << "3. Remove an activity\n";
    std::cout << "4. Search by type\n";
    std::cout << "5. Exit\n";
}

int getChoice() {
    int choice;
    std::cout << "Enter choice: ";
    std::cin >> choice;
    std::cin.ignore(); // skip newline
    return choice;
}

void addActivity(Activity activities[], int &size) {
    Activity newActivity;
    std::cout << "Enter name: ";
    std::cin.getline(newActivity.name, MAX_NAME_LENGTH);
    std::cout << "Enter location: ";
    std::cin.getline(newActivity.location, MAX_LOCATION_LENGTH);
    std::cout << "Enter type: ";
    std::cin.getline(newActivity.type, MAX_TYPE_LENGTH);
    std::cout << "Enter distance (minutes): ";
    std::cin >> newActivity.distance;
    std::cin.ignore();

    insertActivity(activities, size, newActivity);
    std::cout << "Activity added successfully!\n";
}

void removeActivityMenu(Activity activities[], int &size) {
    char name[MAX_NAME_LENGTH];
    std::cout << "Enter activity name to remove: ";
    std::cin.getline(name, MAX_NAME_LENGTH);

    removeActivity(activities, size, name);
    std::cout << "Activity removed if it existed.\n";
}

void searchActivityMenu(const Activity activities[], int size) {
    char type[MAX_TYPE_LENGTH];
    std::cout << "Enter activity type to search: ";
    std::cin.getline(type, MAX_TYPE_LENGTH);

    searchByType(activities, size, type);
}

int main() {
    Activity activities[MAX_ACTIVITIES];
    int size = 0;

    loadActivities(activities, size);

    int choice;
    do {
        displayMenu();
        choice = getChoice();

        switch (choice) {
            case 1: displayActivities(activities, size); break;
            case 2: addActivity(activities, size); break;
            case 3: removeActivityMenu(activities, size); break;
            case 4: searchActivityMenu(activities, size); break;
            case 5: saveActivities(activities, size); std::cout << "Goodbye!\n"; break;
            default: std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
