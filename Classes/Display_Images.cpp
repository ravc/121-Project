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
    if(custs.size() > 0){
        try{
            for(int i = 0; i < number; i++){
                boxes.push_back(new Fl_Box(50*i, 30, 50, 50));
                ++pos;
            }
            for(int i = pos-number; i < pos; i++){
                boxes[i]->image(new Fl_JPEG_Image(custs[i].image().c_str()));
                boxes[i]->redraw();
            }
        }catch(...){}
    }else if(driver.size() > 0){
        try{
            for(int i = 0; i < number; i++){
                boxes.push_back(new Fl_Box(50*i, 30, 50, 50));
                ++pos;
            }
            for(int i = pos-number; i < pos; i++){
                boxes[i]->image(new Fl_JPEG_Image(driver[i].image().c_str()));
                boxes[i]->redraw();
            }
        }catch(...){}
    }else if(places.size() > 0){
        try{
            for(int i = 0; i < number; i++){
                boxes.push_back(new Fl_Box(50*i, 30, 50, 50));
                ++pos;
            }
            for(int i = pos-number; i < pos; i++){
                boxes[i]->image(new Fl_JPEG_Image(places[i].image().c_str()));
                boxes[i]->redraw();
            }
        }catch(...){}
    }
}
void Display_Images::prev(){}

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
