#include "Graphics\std_lib_facilities_4.h"
#include "Place_info.h"
//The Place_info class holds all of the information about a certain place. 
//This consists of the geo_loc of their coordinates as well as the name of the place and certain keys that could be used to describe it

	Place_info::Place_info(string inputName, string inputAddress, vector<string> inputTags, Geo_loc inputLocation) :
	name(inputName), address(inputAddress), tags(inputTags), location(inputLocation) {}
	string Place_info::getName() { return name; }
	string Place_info::getAddress() { return address; }
	vector<string> Place_info::getTags() { return tags; }
	Geo_loc Place_info::getLocation() { return location; }
};
