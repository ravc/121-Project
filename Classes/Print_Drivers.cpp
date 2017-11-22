# ifndef Print_Drivers_H
# define Print_Drivers_H
#include "Print_Drivers.h"

Print_Drivers::Print_Drivers(Point xy, int w, int h, const string& title):

Window(xy,w,h,title),
distance_box(Point(x_max()/2-100,100),70,20,"Distance"),
tag_box(Point(x_max()/2+100,100),70,20,"Tag"),
exit_button(Point(0,0),70,20,"Exit",cb_exit),
next_button(Point(x_max()-70,0),70,20,"Next",cb_next)
{
    attach(distance_box);
    attach(tag_box);
    attach(exit_button);
    attach(next_button);
}

void Print_Drivers::distance(){
    //figure this out later
}
void Print_Drivers::tag(){
    //figure this out later
}
void Print_Drivers::exit(){
    hide();
}
void Print_Drivers::next(){
    //need to create the next screen. will depend on distance and tag
}

void Print_Drivers::cb_distance(Address, Address pw){
    reference_to<Print_Drivers>(pw).distance();
}
void Print_Drivers::cb_tag(Address, Address pw){
    reference_to<Print_Drivers>(pw).tag();
}
void Print_Drivers::cb_exit(Address, Address pw){
    reference_to<Print_Drivers>(pw).exit();
}
void Print_Drivers::cb_next(Address, Address pw){
    reference_to<Print_Drivers>(pw).next();
}

#endif
