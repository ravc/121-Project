#include "std_lib_facilities_4.h"
#include "Graphics/GUI.h"

using namespace Graph_lib;

struct Print_Drivers : Graph_lib::Window{
public:
    Print_Drivers(Point xy, int w, int h, const string& title);
private:
    In_box distance_box;
    In_box tag_box;
    Button exit_button;
    Button next_button;
    
    void distance();
    void tag();
    void exit();
    void next();
    
    static void cb_distance(Address, Address pw);
    static void cb_tag(Address, Address pw);
    static void cb_exit(Address, Address pw);
    static void cb_next(Address, Address pw);
};
