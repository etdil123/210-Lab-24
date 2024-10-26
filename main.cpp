// COMSC 210 | Lab 23 Goat Manager 3001 | Ethan Dilk
#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    // intializing empty goat list
    list<Goat> trip;

    bool program = true;
    int userSelection;

    // while program variable is true keep running menu
    while (program != false){

        userSelection = main_menu();

        // switch statement on the user selection from menu
        switch(userSelection)
        {
            case 1:
                add_goat(trip, names, colors);
                break;
            case 2:
                delete_goat(trip);
                break;
            case 3:
                display_trip(trip);
                break;
            case 4:
                // exit menu loop
                program = false;
                cout << "Thank you for using the Goat Manager 3001!" << endl;
                break;
        };
    }

    return 0;
}

// main_menu returns an integer indicating what menu option the user picked
int main_menu(){
    // userOption stores which option is picked
    int userOption = 0;
    string menu =  "\n*** GOAT MANAGER 3001 ***\n[1] Add a goat\n[2] Delete a goat\n[3] List goats\n[4] Quit\n";

    cout << menu;
    cin >> userOption;

    // input validation - make sure the user picks between 1 and 4
    while (userOption < 1 || userOption > 4) {
        cout << "Please make a selection between 1 and 4" << endl;
        cout << menu;
        cin >> userOption;
    }

    cout << "Choice --> " << userOption << endl;
    // returns the integer the user picks 
    return userOption;
}

// select_goat returns an integer which is the index of which goat they picked
int select_goat(list<Goat> trip) {

    int userSelection, goatIndex = 1;
    cout << "Select a goat from below: " << endl;

    // use a range-based for loop to iterate through the trip list
    for (Goat g : trip) {
        cout << "   [" << goatIndex << "] " << g.get_name() << " (" << g.get_age() << ", " << g.get_color() << ")" << endl;
        goatIndex++;
    }
    // store which option the user picked
    cin >> userSelection;

    // input validation - making sure the user picked a valid index in the trip list 
    while (userSelection < 1 || userSelection > trip.size()) {
        cout << "\nPlease make a valid goat selection: ";
        cin >> userSelection;
    }

    return userSelection;
}

// delete_goat returns nothing - user selects goat they want to delete 
void delete_goat(list<Goat> &trip) {

    int goatDelete;
    // if there are no goats in list - exit function
    if (trip.size() < 1){
        cout << "No goats to delete!" << endl;
        return;
    }

    // use select_goat to pick an goat (index) they want to delete from trip list
    goatDelete = select_goat(trip) - 1;

    // create an iterator to go to index that the user wants to delete
    auto it = trip.begin();
    // advance and erase the goat at the delete index in trip list
    advance(it, goatDelete);
    trip.erase(it);

    cout << "Goat has been deleted!" << endl;

}

// add_goat returns nothing - a random goat is added to the trip list 
void add_goat(list<Goat> &trip, string names[], string color[]) {

    // select random index in names and in color arrays
    int randNameIndex = (rand() % SZ_NAMES);
    string randName = names[randNameIndex];

    int randColorIndex = (rand() % SZ_COLORS);
    string randColor = color[randColorIndex];

    // get random int between 0 and MAX_AGE
    int randAge = (rand() % MAX_AGE);

    // Use parameter constructor to create a new Goat object
    Goat newGoat(randName, randAge, randColor);

    // push back the new goat object into the trip list
    trip.push_back(newGoat);
    cout << "Goat has been added!" << endl;

}

// display_trip returns nothing - iterates through trip list and displays each goat and corresponsing information
void display_trip(list<Goat> trip) {

    int goatIndex = 1;

    // input validation - if there's no goats get out the function
    if (trip.size() < 1) {
        cout << "No goats to display!" << endl;
        return;
    }

    cout << "Listing goats on trip: " << endl;

    // use range-based for loop to iterate trip list and display information about each goat
    for (Goat g : trip) {
        cout << "   [" << goatIndex << "] " << g.get_name() << " (" << g.get_age() << ", " << g.get_color() << ")" << endl;
        goatIndex++;
    }
    
}