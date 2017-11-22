#include "std_lib_facilities_4.h"
#include "Graphics/GUI.h"

using namespace Graph_lib;

struct Print_All_Customer : Graph_lib::Window{
public:
    Print_Customer(Point xy, int w, int h, const string& title);
private:
    Button next_button;
    Button exit_button;
    Box* image_box;
    Scroll scroll_bar;
    Image* image_display;
    
    void next;
    void exit;
    
    static void cb_next(Address, Address pw);
    static void cb_exit(Address, Address pw);
};
