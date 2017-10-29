#include "std_lib_facilities_4.h"
#include "Geo_loc.h"

double lat;
double lon;

Geo_Loc::Geo_Loc(double x, double y) : lat(x), lon(y) {}

double Geo_Loc::getLatitude() { return lat; }

double Geo_Loc::getLongitude() { return lon; }

double Geo_Loc::getDistance(Geo_Loc a, Geo_Loc b) {
    return geoDistanceCalculator(a.getLatitude(), a.getLongitude(), b.getLatitude(), b.getLongitude());
}
