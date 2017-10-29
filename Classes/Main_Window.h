#include "std_lib_facilities_4.h"
#include "Graphics/GUI.h"

using namespace Graph_lib;

struct main_window : Graph_lib::Window{
public:
    Main_Window(Point xy, int w, int h, const string& title);
    
private:
    void quit();
    
    static void cb_quit(Address, Address);
};
