# ifndef Print_Drivers_H
# define Print_Drivers_H
#include "Print_Drivers.h"
#include "Error_Window.h"

Print_Drivers::Print_Drivers(Point xy, int w, int h, const string& title, vector<Place_Info>& place):

Window(xy,w,h,title),
distance_box(Point(x_max()/2-100,100),70,20,"Distance"),
tag_box(Point(x_max()/2+100,100),70,20,"Tag"),
exit_button(Point(0,0),70,20,"Exit",cb_exit),
next_button(Point(x_max()-70,0),70,20,"Next",cb_next),
places(place)
{
    attach(distance_box);
    attach(tag_box);
    attach(exit_button);
    attach(next_button);
}

int Print_Drivers::distance(){
    string d = distance_box.get_string();
    double dis = atof(d.c_str());
    if(dis >= 0){return dis;}else{
        while(true){
            Error_Window win(Point(200,200),300,200,"Not a valid distance");
            return gui_main();
        }
    }
}
string Print_Drivers::tag(){
    string t = tag_box.get_string();
    return t;
}
void Print_Drivers::exit(){
    hide();
}
void Print_Drivers::next(){
    int dis = distance();
    string t = tag();
}

void Print_Drivers::cb_exit(Address, Address pw){
    reference_to<Print_Drivers>(pw).exit();
}
void Print_Drivers::cb_next(Address, Address pw){
    reference_to<Print_Drivers>(pw).next();
}

#endif
