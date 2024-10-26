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

    list<Goat> trip;

    bool program = true;
    int userSelection;

    while (program != false){

        userSelection = main_menu();

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
                program = false;
                cout << "Thank you for using the Goat Manager 3001!" << endl;
                break;
        };
    }

    return 0;
}


int main_menu(){
    int userOption = 0;
    string menu =  "\n*** GOAT MANAGER 3001 ***\n[1] Add a goat\n[2] Delete a goat\n[3] List goats\n[4] Quit\n";

    cout << menu;
    cin >> userOption;

    while (userOption < 1 || userOption > 4) {
        cout << "Please make a selection between 1 and 4" << endl;
        cout << menu;
        cin >> userOption;
    }

    cout << "Choice --> " << userOption << endl;
    return userOption;
}

int select_goat(list<Goat> trip) {

    int userSelection, goatIndex = 1;
    cout << "Select a goat from below: " << endl;

    for (Goat g : trip) {
        cout << "   [" << goatIndex << "] " << g.get_name() << " (" << g.get_age() << ", " << g.get_color() << ")" << endl;
        goatIndex++;
    }

    cin >> userSelection;

    while (userSelection < 1 || userSelection > trip.size()) {
        cout << "\nPlease make a valid goat selection: ";
        cin >> userSelection;
    }

    return userSelection;
}

void delete_goat(list<Goat> &trip) {

    int goatDelete;

    if (trip.size() < 1){
        cout << "No goats to delete!" << endl;
        return;
    }

    goatDelete = select_goat(trip) - 1;

    auto it = trip.begin();
    advance(it, goatDelete);
    trip.erase(it);

    cout << "Goat has been deleted!" << endl;

}

void add_goat(list<Goat> &trip, string names[], string color[]) {

    int randNameIndex = (rand() % SZ_NAMES);
    string randName = names[randNameIndex];

    int randColorIndex = (rand() % SZ_COLORS);
    string randColor = color[randColorIndex];

    int randAge = (rand() % MAX_AGE);

    Goat newGoat(randName, randAge, randColor);

    trip.push_back(newGoat);
    cout << "Goat has been added!" << endl;

}

void display_trip(list<Goat> trip) {

    int goatIndex = 1;

    if (trip.size() < 1) {
        cout << "No goats to display!" << endl;
        return;
    }

    cout << "Listing goats on trip: " << endl;
    for (Goat g : trip) {
        cout << "   [" << goatIndex << "] " << g.get_name() << " (" << g.get_age() << ", " << g.get_color() << ")" << endl;
        goatIndex++;
    }
    
}