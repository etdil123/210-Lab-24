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




    return 0;
}

int main_menu(){
    int userOption = 0;
    string menu =  "*** GOAT MANAGER 3001 ***\n[1] Add a goat\n[2] Delete a goat\n[3] List goats\n[4] Quit\n";

    cout << menu;
    cin >> userOption;

    while (userOption < 1 || userOption > 4) {
        cout << "Please make a selection between 1 and 4" << endl;
        cout << menu;
        cin >> userOption;
    }

    cout << "Choice -->" << userOption << endl;
    return userOption;
}

int select_goat(list<Goat> trip) {

    int userSelection, goatIndex = 1;
    cout << "Select a goat from below: " << endl;

    for (Goat g : trip)
        cout << "   [" << goatIndex << "] " << g.get_name() << " (" << g.get_age() << ", " << g.get_color() << ")" << endl;

    cin >> userSelection;

    




}