#include "Driver.h"
Geo_Loc currentLoc;
string dname;
double currentPaycheck;
drivers::drivers(Geo_Loc location, string inputName, double balance) : currentLoc(location), drivername(inputName), currentPaycheck(balance) {}
drivers::drivers(){}
Geo_Loc drivers::getCurrentLocation() { return currentLoc; }
double drivers::getCurrentPaycheck() { return currentPaycheck; }
void drivers::addMoney(double amount) { currentPaycheck += amount; }
string drivers::getName() { return dname; }
void drivers::changeLocation(Geo_Loc loc) { currentLoc = loc; }
string drivers::image(){return image_name;}
