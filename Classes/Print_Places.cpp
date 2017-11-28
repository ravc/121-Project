#ifndef Print_Places_H
#define Print_Places_H
#include "Print_Places.h"

Print_Places::Print_Places(Point xy, int w, int h, const string& title, vector<Place_Info>& p):

Window(xy,w,h,title),
exit_button(Point(0,0),70,20,"Exit",cb_exit),
next_button(Point(x_max()-70,0),70,20,"Next",cb_next),
tag_box(Point(x_max()/2-45,90),90,20,"Tag"),
places(p)
{
    attach(exit_button);
    attach(next_button);
    attach(tag_box);
}

void Print_Places::exit(){
    hide();
}
void Print_Places::next(){
    vector<Place_Info> match;
    string looking = tag();
    for(int i = 0; i < places.size(); i++){
        for(int j = 0; j < places[i].getTags().size(); j++){
            if(looking == places[i].getTags()[j]){
                match.push_back(places[i]);
                break;
            }
        }
    }
}
string Print_Places::tag(){
    return tag_box.get_string();
}

void Print_Places::cb_exit(Address, Address pw){
    reference_to<Print_Places>(pw).exit();
}
void Print_Places::cb_next(Address, Address pw){
    reference_to<Print_Places>(pw).next();
}

#endif
