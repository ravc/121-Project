#include "std_lib_facilities_4.h"
#include "Graphics/GUI.h"
#include "Place_Info.h"

using namespace Graph_lib;

struct Print_Places : Graph_lib::Window{
public:
    Print_Places(Point xy, int w, int h, const string& title, vector<Place_Info>& p);
private:
    Button exit_button;
    Button next_button;
    
    In_box tag_box;
    
    vector<Place_Info> places;
    
    void exit();
    void next();
    string tag();
    
    static void cb_exit(Address, Address pw);
    static void cb_next(Address, Address pw);
};
