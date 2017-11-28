#include "std_lib_facilities_4.h"
#include "Graphics/GUI.h"

using namespace Graph_lib;

struct Error_Window : Graph_lib::Window{
public:
    Error_Window(Point xy, int w, int h, const string& error);
private:   
    Button ok_button;
    Out_box err;
    
    void ok();
    
    static void cb_ok(Address, Address pw);
};
