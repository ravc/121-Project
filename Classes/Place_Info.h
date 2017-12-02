# ifndef Place_Info_H
# define Place_Info_H
# include "Geo_Loc.h"


//The Place_Info class holds all of the information about a certain place. 
//This consists of the Geo_Loc of their coordinates as well as the name of the place and certain keys that could be used to describe it

class Place_Info {
    
public:
    Place_Info(string inputName, string inputAddress, vector<string> inputTags, Geo_Loc inputLocation, string img);
	Place_Info();
	string getName();
    string getAddress();
    vector<string> getTags();
    Geo_Loc getLocation();
    string image();
private:
    string placename;
    string address;
    vector<string> tags;
    Geo_Loc location;
    string image_name;
};

#endif
