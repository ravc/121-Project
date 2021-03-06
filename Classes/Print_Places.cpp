#ifndef Print_Places_H
#define Print_Places_H
#include "Print_Places.h"
#include "Display_Images.h"
#include "Error_Window.h"

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

void Print_Places::show_window(){
    show();
}
void Print_Places::exit(){
    hide();
}
int Print_Places::next(){
    vector<Place_Info> match;
    string looking = tag();
    for(int i = 0; i < places.size(); i++){//looks for places that match a tag
        for(int j = 0; j < places[i].getTags().size(); j++){
            if(looking == places[i].getTags()[j]){
                match.push_back(places[i]);
                break;
            }
        }
    }
    hide();
    if(match.size() == 0){//error window if no matches are found
        while(true){
            Error_Window win(Point(200,200),300,200,"No Locations Found");
            return gui_main();
        }
    }
    while(true){//starts new window for displaying images
        Display_Images win(Point(100,100),600,400,"My Ride",match);
        return gui_main();
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
    reference_to<Print_Places>(pw).show_window();
}

#endif
