#ifndef ACCESSORIES
#define ACCESSORIES

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

#include "plant.hpp"

using namespace std;

// the following are UBUNTU/LINUX, and MacOS ONLY terminal color codes.
// Reference: https://stackoverflow.com/questions/9158150/colored-output-in-c/9158263
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
// --------------------------------------------------------------------------

string menu[3] = {
    "[1] Start Watering My Plants",
    "[2] View Saved Plants",
    "[3] Power Off Machine"
};

string degreetMsgList[5] = {
    "Have a beautiful day!",
    "Cheers!",
    "See you next time!",
    "Good bye!",
    "Thank you for your time!"
};


// Prompts the user to press the enter key 
// to move on to the next screen
void moveOn(){
    cout << YELLOW << "[Press the enter key to continue]" << RESET << endl;
    string empty;
    getline(cin, empty);
    system("clear");
}

// Feature in choice 2 (See below)
void printPlantStatus(Plant& currentPlant, int plantNumber) {

    // User inputs for plant options
    int newHour;
    char yesOrNo;
    string newName;
    double newWaterFlow;


    // Title to specify which plant it is
    cout << BOLDBLUE << endl << endl
        << "-------------------------------------------" << endl;
    cout << "               PLANT #" << plantNumber << endl;
    cout << "-------------------------------------------" << RESET << endl << endl;


    // Printing all info of the plants
    cout << BOLDGREEN << "[1] PLANT NAME = " << RESET << currentPlant.getPlantName() << endl;
    cout << BOLDGREEN << "[2] TIME TO WATER = " << RESET << 
        currentPlant.getHour() << " : 00" << endl;
    cout << BOLDGREEN << "[3] AMOUNT OF WATER DISTRIBUTED = " << RESET << 
        currentPlant.getWaterFlow() << " milliliters" << endl;

    cout << YELLOW << "Do you want to edit these settings? [y/n]" << RESET << endl; 
    cin >> yesOrNo;

    if (tolower(yesOrNo) == 'y') {
        cout << YELLOW << "What will be your new plant name? " << RESET;
        cin.ignore();
        getline(cin, newName);
        currentPlant.setPlantName(newName);

        cout << YELLOW << "At what hour of the day do you want to water your plant? (1-24) " << RESET;
        cin >> newHour;
        
        // Input validation
        while (newHour > 24 || newHour < 1) {
            cout << RED <<"Invalid input. Please re-enter your hours (1-24) " << RESET;
            cin >> newHour;
        }
        currentPlant.setHour(newHour);

        cout << YELLOW << "How much water do you want this plant to flow? " << RESET;
        cin >> newWaterFlow;
        currentPlant.setWaterFlow(newWaterFlow);
    }
    else if(tolower(yesOrNo) == 'n') {
        system("clear");
    }
}

// Choice 2 of main menu
void view(vector<Plant>& myPlants) {
    int choice;

    do {

        // Printing menu
        cout << BOLDBLUE << "Plant Options:" << RESET << endl << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "[" << i + 1 << "] " << myPlants[i].getPlantName() << endl;
        }

        // Taking user input
        cout<< YELLOW << "[Enter a number 1-3. Enter 0 to go back]" << RESET << endl;
        cin >> choice;
        cin.ignore();
        system("clear");

        if (choice == 1 || choice == 2 || choice == 3) {
            printPlantStatus(myPlants[choice - 1], choice);
        }
        else if (choice != 0) {
            cout<< "Wrong input. Please enter a number 1-3" << endl;
            moveOn();
        }
    } while (choice != 0);
}


// Choice 3 of main menu
bool powerOff() {
    return true;
}

#endif // ACCESSORIES