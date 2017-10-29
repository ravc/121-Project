#include "Driver.h"
Geo_Loc currentLocation;
string name;
double currentPaycheck;
drivers::drivers(Geo_Loc location, string inputName, double balance) : currentLocation(location), name(inputName), currentPaycheck(balance) {}
Geo_Loc drivers::getCurrentLocation() { return currentLocation; }
double drivers::getCurrentPaycheck() { return currentPaycheck; }
void drivers::addMoney(double amount) { currentPaycheck += amount; }
string drivers::getName() { return name; }
void drivers::changeLocation(Geo_Loc loc) { currentLocation = loc; }