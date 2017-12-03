# ifndef Display_Images_H
# define Display_Images_H
#include "Display_Images.h"

Display_Images::Display_Images(Point xy, int w, int h, const string& title, vector<customers>& c):
Window(xy,w,h,title),
exit_button(Point(x_max()-70,0), 70, 20, "exit", cb_exit),
prev_button(Point(x_max()/2-70,y_max()-20),70,20,"<<",cb_prev),
next_button(Point(x_max()/2,y_max()-20),70,20,">>",cb_next),
one_button(Point(x_max()/2-105,y_max()-60),70,20,"1",cb_one),
two_button(Point(x_max()/2-35,y_max()-60),70,20,"2",cb_two),
three_button(Point(x_max()/2+35,y_max()-60),70,20,"3",cb_three),
custs(c)
{
    attach(exit_button);
    attach(prev_button);
    attach(next_button);
    attach(one_button);
    attach(two_button);
    attach(three_button);
    for(int i = 0; i < custs.size(); i++){
        images.push_back(new Image(Point(150*i,50),custs[i].image()));
        images[i]->resize(100,100);
    }
    attach(*images[0]);
    Out_box name = Out_box(Point(0,170),170,20,"");
    Out_box bal = Out_box(Point(0,190),170,20,"");
    attach(name);
    attach(bal);
    bal.put("Balance: " + to_string(custs[0].getAccountBalance()));
    name.put("Name: " + custs[0].getName());
}

Display_Images::Display_Images(Point xy, int w, int h, const string& title, vector<drivers>& d):
Window(xy,w,h,title),
exit_button(Point(x_max()-70,0), 70, 20, "exit", cb_exit),
prev_button(Point(x_max()/2-70,y_max()-20),70,20,"<<",cb_prev),
next_button(Point(x_max()/2,y_max()-20),70,20,">>",cb_next),
one_button(Point(x_max()/2-105,y_max()-60),70,20,"1",cb_one),
two_button(Point(x_max()/2-35,y_max()-60),70,20,"2",cb_two),
three_button(Point(x_max()/2+35,y_max()-60),70,20,"3",cb_three),
driver(d)
{
    attach(exit_button);
    attach(prev_button);
    attach(next_button);
    attach(one_button);
    attach(two_button);
    attach(three_button);
    for(int i = 0; i < driver.size(); i++){
        images.push_back(new Image(Point(150*i,50),driver[i].image()));
        images[i]->resize(100,100);
    }
    attach(*images[0]);
    Out_box name = Out_box(Point(0,170),170,20,"");
    Out_box loc = Out_box(Point(0,190),170,20,"");
    Out_box bal = Out_box(Point(0,210),170,20,"");
    attach(name);
    attach(loc);
    attach(bal);
    name.put("Name: " + driver[0].getName());
    loc.put("Lat: " + to_string(driver[0].getCurrentLocation().getLatitude()) + " Lon: " + to_string(driver[0].getCurrentLocation().getLongitude()));
    bal.put("Balance: " + to_string(driver[0].getCurrentPaycheck()));
}

Display_Images::Display_Images(Point xy, int w, int h, const string& title, vector<Place_Info>& p):
Window(xy,w,h,title),
exit_button(Point(x_max()-70,0), 70, 20, "exit", cb_exit),
prev_button(Point(x_max()/2-70,y_max()-20),70,20,"<<",cb_prev),
next_button(Point(x_max()/2,y_max()-20),70,20,">>",cb_next),
one_button(Point(x_max()/2-105,y_max()-60),70,20,"1",cb_one),
two_button(Point(x_max()/2-35,y_max()-60),70,20,"2",cb_two),
three_button(Point(x_max()/2+35,y_max()-60),70,20,"3",cb_three),
places(p)
{
    attach(exit_button);
    attach(prev_button);
    attach(next_button);
    attach(one_button);
    attach(two_button);
    attach(three_button);
    for(int i = 0; i < places.size(); i++){
        images.push_back(new Image(Point(150*i,50),places[i].image()));
        images[i]->resize(100,100);
    }
    attach(*images[0]);
    Out_box name = Out_box(Point(0,170),170,20,"");
    Out_box tag = Out_box(Point(0,190),170,20,"");
    Out_box loc = Out_box(Point(0,210),170,20,"");
    attach(name);
    attach(tag);
    attach(loc);
    name.put("Name: " + places[0].getName());
    loc.put("Location: " + places[0].getAddress());
    string t;
    for(int i = 0; i < places[0].getTags().size(); i++){
        t += places[0].getTags()[i] + ", ";
    }
    tag.put("Tags: " + t);
}

void Display_Images::exit(){
    hide();
}
void Display_Images::one(){
    number = 1;
    next();
}
void Display_Images::two(){
    number = 2;
    next();
}
void Display_Images::three(){
    number = 3;
    next();
}
void Display_Images::next(){
    try{
        for(int i = 0; i < number; i++){
            images[pos+i+1]->reposition(Point(150*i,50));
            try{detach(*images[pos-i]);}catch(...){}
            attach(*images[pos+i+1]);
        }
        pos += number;
        redraw();
    }catch(...){}
}
void Display_Images::prev(){
    try{
        for(int i = 0; i < number; i++){
            images[pos-i-1]->reposition(Point(150*i,50));
            try{detach(*images[pos+i]);}catch(...){}
            attach(*images[pos-i-1]);
        }
        pos -= number;
        redraw();
    }catch(...){}
}

void Display_Images::cb_exit(Address, Address pw){
    reference_to<Display_Images>(pw).exit();
}
void Display_Images::cb_one(Address, Address pw){
    reference_to<Display_Images>(pw).one();
}
void Display_Images::cb_two(Address, Address pw){
    reference_to<Display_Images>(pw).two();
}
void Display_Images::cb_three(Address, Address pw){
    reference_to<Display_Images>(pw).three();
}
void Display_Images::cb_next(Address, Address pw){
    reference_to<Display_Images>(pw).next();
}
void Display_Images::cb_prev(Address, Address pw){
    reference_to<Display_Images>(pw).prev();
}

#endif
