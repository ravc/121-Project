# ifndef Display_Images_H
# define Display_Images_H
#include "Display_Images.h"

Display_Images::Display_Images(Point xy, int w, int h, const string& title, vector<customers>& c):
Window(xy,w,h,title),
exit_button(Point(x_max()-70,0), 70, 20, "exit", cb_exit),
back_button(Point(0,0), 70, 20, "back", cb_back),
custs(c)
{
    attach(exit_button);
    attach(back_button);
    back_button.hide();
}

Display_Images::Display_Images(Point xy, int w, int h, const string& title, vector<drivers>& d):
Window(xy,w,h,title),
exit_button(Point(x_max()-70,0), 70, 20, "exit", cb_exit),
back_button(Point(0,0), 70, 20, "back", cb_back),
driver(d)
{
    attach(exit_button);
    attach(back_button);
    back_button.hide();
}

Display_Images::Display_Images(Point xy, int w, int h, const string& title, vector<Place_Info>& p):
Window(xy,w,h,title),
exit_button(Point(x_max()-70,0), 70, 20, "exit", cb_exit),
back_button(Point(0,0), 70, 20, "back", cb_back),
places(p)
{
    attach(exit_button);
    attach(back_button);
    back_button.hide();
}

void Display_Images::exit(){
    hide();
}
void Display_Images::back(){
}

void Display_Images::cb_exit(Address, Address pw){
    reference_to<Display_Images>(pw).exit();
}
void Display_Images::cb_back(Address, Address pw){
    reference_to<Display_Images>(pw).back();
}

#endif
