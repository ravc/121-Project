#ifndef drivers_H
#define drivers_H
#include "std_lib_facilities_4.h"
#include "Geo_Loc.h"
//The drivers class creates a driver to be used in the myRide problem
//It contains information about the driver such as user number, name, account balance and current location
class drivers {
public:
    drivers(Geo_Loc location, string inputName, double balance, string img);
	drivers();
	Geo_Loc getCurrentLocation();
    double getCurrentPaycheck();
    void addMoney(double amount);
    string getName();
    void changeLocation(Geo_Loc loc);
    string image();
private:
    Geo_Loc currentLoc;
    double currentPaycheck;
    string drivername;
    string image_name;
};
#endif
