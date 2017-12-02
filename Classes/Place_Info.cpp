#include "std_lib_facilities_4.h"
#include "Place_Info.h"
//The Place_Info class holds all of the information about a certain place. 
//This consists of the Geo_Loc of their coordinates as well as the name of the place and certain keys that could be used to describe it

vector<string> tags;
string name;
string address;
Geo_Loc location;
Place_Info::Place_Info() {}
Place_Info::Place_Info(string inputName, string inputAddress, vector<string> inputTags, Geo_Loc inputLocation, string img) :
placename(inputName), address(inputAddress), tags(inputTags), location(inputLocation), image_name(img) {}
string Place_Info::getName() { return name; }
string Place_Info::getAddress() { return address; }
vector<string> Place_Info::getTags() { return tags; }
Geo_Loc Place_Info::getLocation() { return location; }
string Place_Info::image(){return image_name;}
