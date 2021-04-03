#pragma once

#include <iostream>
#include <string>
using namespace std;

class Plant {
private:
    string plantName_,      // The name of your plant
            AMOrPM_;        // Time being AM or PM
    int waterFlow_,         // How much water to give at certain time (Capacity will be determined)
        hour_,              // 1 - 12
        minute_;            // 0 - 59
    bool hasWater_;         // False by default until water is detected by sensors 
    
public:
    // Constructors
    Plant(string, int, int, int, string);
    Plant();    // Default

    // Getters
    string getPlantName();
    string getAMOrPM();
    int getWaterFlow();
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
    bool outOfWater();
};


// ========================================== FUNCTION BODIES ==========================================

// --------------- CONSTRUCTORS ---------------
Plant::Plant(string plantName, int waterFlow, int hour, int minute, string AM_PM): 
        plantName_(plantName), waterFlow_(waterFlow), hour_(hour), minute_(minute), AMOrPM_(AM_PM), hasWater_(false) {}; 

Plant::Plant(): // Default value: UNIDENTIFIED name pouring 30 units of water at 12:00 PM
    plantName_("UNIDENTIFIED"), waterFlow_(30), hour_(12), minute_(0), AMOrPM_("PM"), hasWater_(false) {};


// --------------- GETTERS ---------------
string Plant::getPlantName() { return plantName_; }

string Plant::getAMOrPM() {return AMOrPM_; }

int Plant::getWaterFlow() { return waterFlow_; }

int Plant::getHour() { return hour_; }

int Plant::getMinute() { return minute_; }


// --------------- SETTERS ---------------

void Plant::setPlantName(string plantName) { plantName_ = plantName; }

void Plant::setAMOrPM(string AMOrPM) { AMOrPM_ = AMOrPM; }

void Plant::setWaterFlow(int waterFlow) { waterFlow_ = waterFlow; }

void Plant::setHour(int hour) { hour_ = hour; }

void Plant::setMinute(int minute) { minute_ = minute; }

// --------------- OTHERS ---------------
void Plant::activate() {
    cout << "Activating the machine" << endl;
}

bool Plant::outOfWater() {
    if (hasWater_) return false;
    else return true;
}