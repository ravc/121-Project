#include "std_lib_facilities_4.h"
#include "Graphics/GUI.h"
#include "Place_Info.h"
#include "Driver.h"

using namespace Graph_lib;

struct Print_Drivers : Graph_lib::Window{
public:
    Print_Drivers(Point xy, int w, int h, const string& title, vector<Place_Info>& place, vector<drivers>& drive);
private:
    In_box distance_box;
    In_box tag_box;
    
    Button exit_button;
    Button next_button;
    
    int distance();
    string tag();
    
    vector<Place_Info> places;
    vector<drivers> driver;
    
    void exit();
    int next();
    void show_window();
    
    Geo_Loc l;
    
    static void cb_exit(Address, Address pw);
    static void cb_next(Address, Address pw);
};
