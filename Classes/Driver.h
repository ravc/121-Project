#ifndef drivers_H
#define drivers_H
#include "std_lib_facilities_4.h"
#include "Geo_Loc.h"
//The drivers class creates a driver to be used in the myRide problem
//It contains information about the driver such as user number, name, account balance and current location
class drivers {
public:
    drivers(Geo_Loc location, string inputName, double balance);
	drivers();
	Geo_Loc getCurrentLocation();
    double getCurrentPaycheck();
    void addMoney(double amount);
    string getName();
    void changeLocation(Geo_Loc loc);
private:
    Geo_Loc currentLocation;
    double currentPaycheck;
    string name;
    
};
#endif
