#include "Driver.h"
drivers::drivers(Geo_loc location, string inputName, double balance) : currentLocation(location), name(inputName), currentPaycheck(balance) {}
Geo_loc drivers::getCurrentLocation() { return currentLocation; }
double drivers::getCurrentPaycheck() { return currentPaycheck; }
void drivers::addMoney(double amount) { currentPaycheck += amount; }
string drivers::getName() { return name; }
void drivers::changeLocation(Geo_loc loc) { currentLocation = loc; }