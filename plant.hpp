#pragma once

#include <iostream>
#include <string>

// #include "accessories.hpp"

using namespace std;

class Plant {
private:
    string plantName_,      // The name of your plant
            AMOrPM_;        // Time being AM or PM
    double waterFlow_;      // How much water to give at certain time (Capacity will be determined)
    int hour_,              // 1 - 12
        minute_;            // 0 - 59
    
public:
    // Constructors
    Plant(string, double, int, int, string);
    Plant();    // Default

    // Getters
    string getPlantName();
    string getAMOrPM();
    double getWaterFlow();
    int getHour();
    int getMinute();

    // Setters
    void setPlantName(string);
    void setAMOrPM(string);
    void setWaterFlow(int);
    void setHour(int);
    void setMinute(int);

    // Others
    void activate();
    void printStatus(int);
};


// ========================================== FUNCTION BODIES ==========================================

// --------------- CONSTRUCTORS ---------------
Plant::Plant(string plantName, double waterFlow, int hour, int minute, string AM_PM): 
        plantName_(plantName), waterFlow_(waterFlow), hour_(hour), minute_(minute), AMOrPM_(AM_PM) {}; 

Plant::Plant(): // Default value: UNIDENTIFIED name pouring 30 units of water at 12:00 PM
    plantName_("UNIDENTIFIED"), waterFlow_(30), hour_(12), minute_(0), AMOrPM_("PM") {};


// --------------- GETTERS ---------------
string Plant::getPlantName() { return plantName_; }

string Plant::getAMOrPM() {return AMOrPM_; }

double Plant::getWaterFlow() { return waterFlow_; }

int Plant::getHour() { return hour_; }

int Plant::getMinute() { return minute_; }


// --------------- SETTERS ---------------

void Plant::setPlantName(string plantName) { plantName_ = plantName; }

void Plant::setAMOrPM(string AMOrPM) { AMOrPM_ = AMOrPM; }

void Plant::setWaterFlow(int waterFlow) { waterFlow_ = waterFlow; }

void Plant::setHour(int hour) { hour_ = hour; }

void Plant::setMinute(int minute) { minute_ = minute; }

// --------------- OTHERS ---------------
void Plant::activate() {    // Choice 1 of main menu
    cout << "Activating the machine" << endl;
}

void Plant::printStatus(int plantNumber) {

    // // Title to specify which plant it is
    // cout << BOLDBLUE << endl << endl
    //     << "-------------------------------------------" << endl;
    // cout << "               PLANT #" << plantNumber << endl;
    // cout << "-------------------------------------------" << RESET << endl << endl;


    // // Printing all info of the plants
    // cout << BOLDGREEN << "PLANT NAME" << RESET << getPlantName() << endl;
    // cout << BOLDGREEN << "TIME TO WATER" << RESET << 
    //     getHour() << " : " << getMinute() << "  " << getAMOrPM() << endl;
    // cout << BOLDGREEN << "AMOUNT OF WATER DISTRIBUTED" << RESET << 
    //     getWaterFlow() << "milliliters" << endl; 

    // ------------------------------- WITHOUT COLORS------------------------------------
    // Title to specify which plant it is
    cout << endl << endl
        << "-------------------------------------------" << endl;
    cout << "               PLANT #" << plantNumber << endl;
    cout << "-------------------------------------------" << endl << endl;


    // Printing all info of the plants
    cout << "[1] PLANT NAME = " << getPlantName() << endl;
    cout << "TIME TO WATER = " << 
        getHour() << " : " << getMinute() << "  " << getAMOrPM() << endl;
    cout << "AMOUNT OF WATER DISTRIBUTED = " <<  
        getWaterFlow() << "milliliters" << endl; 
}