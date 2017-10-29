#include "std_lib_facilities_4.h"
#include "Geo_loc.h"

Geo_loc::Geo_loc(double x, double y) : lat(x), lon(y) {}

double Geo_loc::getLatitude() { return lat; }

double Geo_loc::getLongitude() { return lon; }

double Geo_loc::getDistance(Geo_loc a, Geo_loc b) {
	return geoDistanceCalculator(a.getLatitude(), a.getLongitude(), b.getLatitude(), b.getLongitude());
}