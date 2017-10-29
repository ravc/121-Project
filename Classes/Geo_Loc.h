#ifndef Geo_Loc_H
#define Geo_Loc_H
#include "std_lib_facilities_4.h"
//All of the classes
//The Geo_Loc class holds a place in the world based on their geographic coordinates.
class Geo_Loc {
    
public:
    Geo_Loc(double x, double y);
	Geo_Loc();
    double getLatitude();
    
    double getLongitude();
    
    double getDistance(Geo_Loc a, Geo_Loc b);
private:
    double lat;
    double lon;
    
};
#endif
