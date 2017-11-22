#include "std_lib_facilities_4.h"
#include "Graphics/GUI.h"

using namespace Graph_lib;

struct Print_Places : Graph_lib::Window{
public:
    Print_Places(Point xy, int w, int h, const string& title);
private:
    Button exit_button;
    Button next_button;
    
    In_box tag_box;
    
    void exit();
    void next();
    void tag();
    
    static void cb_exit(Address, Address pw);
    static void cb_next(Address, Address pw);
    static void cb_tag(Address, Address pw);
};
