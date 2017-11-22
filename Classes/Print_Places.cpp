#ifndef Print_Places_H
#define Print_Places_H
#include "Print_Places.h"

Print_Places::Print_Places(Point xy, int w, int h, const string& title):

Window(xy,w,h,title),
exit_button(Point(0,0),70,20,"Exit",cb_exit),
next_button(Point(x_max()-70,0),70,20,"Next",cb_next),
tag_box(Point(x_max()/2-45,90),90,20,"Tag")
{
    attach(exit_button);
    attach(next_button);
    attach(tag_box);
}

void Print_Places::exit(){
    hide();
}
void Print_Places::next(){
    //put next screen here. depends on tag
}
void Print_Places::tag(){
    //save info somewhere
}

void Print_Places::cb_exit(Address, Address pw){
    reference_to<Print_Places>(pw).exit();
}
void Print_Places::cb_next(Address, Address pw){
    reference_to<Print_Places>(pw).next();
}
void Print_Places::cb_tag(Address, Address pw){
    reference_to<Print_Places>(pw).tag();
}

#endif
