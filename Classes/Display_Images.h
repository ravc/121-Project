#include <FL/Fl.H>
#include "std_lib_facilities_4.h"
#include "Graphics/GUI.h"
#include "Customer.h"
#include "Driver.h"
#include "Place_Info.h"
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Box.H>

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
    vector<Fl_JPEG_Image*> images;
    vector<Fl_Box*> boxes;
    
    int number = 1;
    int pos = 0;
    
    Button exit_button;
    Button one_button;
    Button two_button;
    Button three_button;
    Button next_button;
    Button prev_button;
    
    Fl_Box* image_box;
    Fl_JPEG_Image* image;
    
    void exit();
    
    void one();
    void two();
    void three();
    void next();
    void prev();
    
    static void cb_exit(Address, Address pw);
    static void cb_one(Address, Address pw);
    static void cb_two(Address, Address pw);
    static void cb_three(Address, Address pw);
    static void cb_next(Address, Address pw);
    static void cb_prev(Address, Address pw);
};
