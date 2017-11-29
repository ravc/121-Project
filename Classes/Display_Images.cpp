# ifndef Display_Images_H
# define Display_Images_H
#include "Display_Images.h"

Display_Images::Display_Images(Point xy, int w, int h, const string& title, vector<customers>& c):
Window(xy,w,h,title),
exit_button(Point(x_max()-70,0), 70, 20, "exit", cb_exit),
custs(c)
{
    attach(exit_button);
    for(int i = 0; i < c.size(); i++){
        boxes.push_back(new Fl_Box((c.size()/x_max())+(i*100/c.size()), 30, 100/c.size(), 100/c.size()));
    }
    for(int i = 0; i < boxes.size(); i++){
        boxes[i]->image(new Fl_JPEG_Image(c[i].image().c_str()));
        boxes[i]->redraw();
    }
}

Display_Images::Display_Images(Point xy, int w, int h, const string& title, vector<drivers>& d):
Window(xy,w,h,title),
exit_button(Point(x_max()-70,0), 70, 20, "exit", cb_exit),
driver(d)
{
    attach(exit_button);
    for(int i = 0; i < d.size(); i++){
        boxes.push_back(new Fl_Box((d.size()/x_max())+(i*100/d.size()), 30, 100/d.size(), 100/d.size()));
    }
    for(int i = 0; i < boxes.size(); i++){
        boxes[i]->image(new Fl_JPEG_Image(d[i].image().c_str()));
        boxes[i]->redraw();
    }
}

Display_Images::Display_Images(Point xy, int w, int h, const string& title, vector<Place_Info>& p):
Window(xy,w,h,title),
exit_button(Point(x_max()-70,0), 70, 20, "exit", cb_exit),
places(p)
{
    attach(exit_button);
    for(int i = 0; i < p.size(); i++){
        boxes.push_back(new Fl_Box((p.size()/x_max())+(i*100/p.size()), 30, 100/p.size(), 100/p.size()));
    }
    for(int i = 0; i < boxes.size(); i++){
        boxes[i]->image(new Fl_JPEG_Image(p[i].image().c_str()));
        boxes[i]->redraw();
    }
}

void Display_Images::exit(){
    hide();
}

void Display_Images::cb_exit(Address, Address pw){
    reference_to<Display_Images>(pw).exit();
}

#endif
