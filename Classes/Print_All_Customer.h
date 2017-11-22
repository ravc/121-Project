#include "std_lib_facilities_4.h"
#include "Graphics/GUI.h"

using namespace Graph_lib;

struct Print_All_Customer : Graph_lib::Window{
public:
    Print_Customer(Point xy, int w, int h, const string& title);
private:
    Button next_button;
    Button exit_button;
    Box image_box_button;
    Scroll scroll_bar;
    Image image_display;
};
