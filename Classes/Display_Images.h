#include <FL/Fl.H>
#include "std_lib_facilities_4.h"
#include "Graphics/GUI.h"
#include "Customer.h"
#include "Driver.h"
#include "Place_Info.h"
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Box.h>

using namespace Graph_lib;

struct Display_Images : Graph_lib::Window{
public:
    Display_Images(Point xy, int w, int h, const string& title, vector<customers>& c);
    Display_Images(Point xy, int w, int h, const string& title, vector<drivers>& d);
    Display_Images(Point xy, int w, int h, const string& title, vector<Place_Info>& p);
private:
    vector<customers> custs;
    vector<drivers> driver;
    vector<Place_Info> places;
    
    Button back_button;
    Button exit_button;
    
    Fl_Box* image_box;
    Fl_JPEG_Image* image;
    
    void exit();
    void back();
    
    static void cb_exit(Address, Address pw);
    static void cb_back(Address, Address pw);\
};
