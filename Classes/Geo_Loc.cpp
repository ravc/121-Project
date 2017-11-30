#include "std_lib_facilities_4.h"
#include "Geo_Loc.h"

double lat;
double lon;
double deg2rads(double deg)
{
	return deg / 180.0 * 3.1415926;
}
double geoDistanceCalculator(double lat1, double lon1, double lat2, double lon2)
{

	//Setting up all of the variables prior to the calculation
	lat1 = deg2rads(lat1);
	lat2 = deg2rads(lat2);
	lon1 = deg2rads(lon1);
	lon2 = deg2rads(lon2);
	double earthRadius = 3963.1676;

	//Plugging everything into the equation
	double distance = acos(sin(lat1)*sin(lat2) + cos(lat1)*cos(lat2)*cos(lon1 - lon2))*earthRadius;
	return distance;
}
Geo_Loc::Geo_Loc(double x, double y) : lat(x), lon(y) {}
Geo_Loc::Geo_Loc() {}

double Geo_Loc::getLatitude() { return lat; }

double Geo_Loc::getLongitude() { return lon; }

double Geo_Loc::getDistance(Geo_Loc a, Geo_Loc b) {
    return geoDistanceCalculator(a.getLatitude(), a.getLongitude(), b.getLatitude(), b.getLongitude());
}
