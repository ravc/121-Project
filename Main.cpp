#include "Classes/std_lib_facilities_4.h"
#include "Classes/Customer.h"
#include "Classes/Driver.h"
#include "Classes/Place_Info.h"
#include "Classes/Geo_Loc.h"
#include "Classes/Main_Window.h"

ifstream& loadDrivers(ifstream& ist,vector<drivers>& listOfDrivers) {
    int n;
    double balance, lat, lon;
    string name, pic;
    ist >> n;
    for (int i = 0; i < n; i++) {
        ist >> name >> balance >> lat >> lon >> pic;
        listOfDrivers.push_back(drivers(Geo_Loc(lat, lon), name, balance, pic));
    }
    return ist;
}
ifstream& loadCustomers(ifstream& ist, vector<customers>& listOfCustomers) {
    int n;
    ist >> n;
    for (int i = 0; i<n; i++) {
        string name;
        double balance;
        string picName;
        ist >> name >> balance >> picName;
        listOfCustomers.push_back(customers(name, balance, picName));
    }
    return ist;
}
ifstream&  loadPlaces(ifstream& ist, vector<Place_Info>& listOfPlaces) {
    int n;
    ist >> n;
    for (int i = 0; i < n; i++) {
        string name, address, tag,pic;
        vector<string> tags;
        double lat, lon;
        int numTags;
        ist >> name >> address >> lat >> lon >> numTags;
        for (int j = 0; j < numTags; j++) {
            ist >> tag;
            tags.push_back(tag);
        }
        ist >> pic;
        listOfPlaces.push_back(Place_Info(name, address, tags, Geo_Loc(lat, lon), pic));
    }
}
int main(){
    vector<customers> listOfCustomers;
    vector<drivers> listOfDrivers;
    vector<Place_Info> listOfPlaces;
    ifstream ist{ "t.txt" };
    if (!ist) error("Can't open input file ");
    loadDrivers(ist, listOfDrivers);
    loadCustomers(ist, listOfCustomers);
    loadPlaces(ist, listOfPlaces);
    while(true){
        Main_Window win(Point(100,100),800,200,"My Ride",listOfCustomers,listOfDrivers,listOfPlaces);
        return gui_main();
    }
}
