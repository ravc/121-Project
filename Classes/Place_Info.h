# ifndef Place_info_H
# define Place_info_H
# include "Geo_Loc.h"


//The Place_info class holds all of the information about a certain place. 
//This consists of the geo_loc of their coordinates as well as the name of the place and certain keys that could be used to describe it

class Place_info {
    
public:
    Place_info(string inputName, string inputAddress, vector<string> inputTags, Geo_loc inputLocation);
    string getName();
    string getAddress();
    vector<string> getTags();
    Geo_loc getLocation();
    
    
private:
    string name;
    string address;
    vector<string> tags;
    Geo_loc location;
};

#endif
