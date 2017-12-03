# ifndef Print_Drivers_H
# define Print_Drivers_H
#include "Print_Drivers.h"
#include "Error_Window.h"
#include "Geo_Loc.h"
#include "Display_Images.h"

Print_Drivers::Print_Drivers(Point xy, int w, int h, const string& title, vector<Place_Info>& place, vector<drivers>& drive):

Window(xy,w,h,title),
distance_box(Point(x_max()/2-100,100),70,20,"Distance"),
tag_box(Point(x_max()/2+100,100),70,20,"Tag"),
exit_button(Point(0,0),70,20,"Exit",cb_exit),
next_button(Point(x_max()-70,0),70,20,"Next",cb_next),
places(place),
driver(drive)
{
    attach(distance_box);
    attach(tag_box);
    attach(exit_button);
    attach(next_button);
}

void Print_Drivers::show_window(){
    show();
}
int Print_Drivers::distance(){
    string d = distance_box.get_string();
    double dis = atof(d.c_str());
    if(dis >= 0){return dis;}else{//error if there is a negative number or a string is used
        while(true){
            Error_Window win(Point(200,200),300,200,"Not a valid distance");
            return gui_main();
        }
    }
}
string Print_Drivers::tag(){
    return tag_box.get_string();;
}
void Print_Drivers::exit(){
    hide();
}
int Print_Drivers::next(){
    int dis = distance();
    string t = tag();
    vector<Place_Info> p;
    vector<drivers> d;
    for(int i = 0; i < places.size(); i++){//finds all places with the same tag
        for(int j = 0; j < places[i].getTags().size(); j++){
            if(places[i].getTags()[j] == t){
                p.push_back(places[i]);
            }
        }
    }
    for(int i = 0; i < driver.size(); i++){
        for(int j = 0; j < p.size(); j++){//find all drivers within the distance given
          if(l.getDistance(driver[i].getCurrentLocation(), p[j].getLocation())<=dis){
                d.push_back(driver[i]);
                break;
            }
        }
    }
    hide();
    while(true){
        if(d.size() == 0){//error window if there are no drivers
            Error_Window win(Point(200,200),300,200,"No Drivers found");
            return gui_main();
        }else{
            Display_Images win(Point(100,100),600,400,"My Ride",d);
            return gui_main();
        }
    }
}

void Print_Drivers::cb_exit(Address, Address pw){
    reference_to<Print_Drivers>(pw).exit();
}
void Print_Drivers::cb_next(Address, Address pw){
    reference_to<Print_Drivers>(pw).next();
    reference_to<Print_Drivers>(pw).show_window();
}

#endif
