#ifndef drivers_H
#define drivers_H
#include "std_lib_facilities_4.h"
#include "Geo_Loc.h"
//The drivers class creates a driver to be used in the myRide problem
//It contains information about the driver such as user number, name, account balance and current location
class drivers {
public:
	drivers(Geo_loc location, string inputName, double balance);
	Geo_loc getCurrentLocation();
	double getCurrentPaycheck();
	void addMoney(double amount);
	string getName();
	void changeLocation(Geo_loc loc);
private:
	Geo_loc currentLocation;
	double currentPaycheck;
	string name;

};
#endif
