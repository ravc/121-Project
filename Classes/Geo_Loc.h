#ifndef Geo_loc_H
#define Geo_loc_H
#include "std_lib_facilities_4.h"
//All of the classes
//The Geo_loc class holds a place in the world based on their geographic coordinates.
class Geo_loc {

public:
	Geo_loc(double x, double y);

	double getLatitude();

	double getLongitude();

	double getDistance(Geo_loc a, Geo_loc b);
private:
	double lat;
	double lon;

};
#endif
