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
    for(int i = 0; i < custs.size(); i++){ //gets all the basic info ready to display
        images.push_back(new Image(Point(((i+1)*x_max()/3)-155,50),custs[i].image()));
        images[i]->resize(100,100);
        info.push_back({"Name: " + custs[i].getName(), "Balance: " + to_string(custs[i].getAccountBalance())});
    }
    attach(*images[0]);
    for(int i = 0; i < 3; i++){//gets the outboxes ready
        outbox.push_back(new Out_box(Point(i*x_max()/3,170),x_max()/3-5,20,""));
        outbox.push_back(new Out_box(Point(i*x_max()/3,190),x_max()/3-5,20,""));
    }
    
    //attach all outboxes and set base info
    for(int i = 0; i < outbox.size(); i++){attach(*outbox[i]);}
    outbox[0]->put(info[0][0]);
    outbox[1]->put(info[0][1]);
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
    for(int i = 0; i < driver.size(); i++){//gets all the basic info ready to display
        images.push_back(new Image(Point(((i+1)*x_max()/3)-155,50),driver[i].image()));
        images[i]->resize(100,100);
        info.push_back({"Name: " + driver[i].getName(), "Lat: " + to_string(driver[i].getCurrentLocation().getLatitude()) + " Lon: " + to_string(driver[i].getCurrentLocation().getLongitude()), "Balance: " + to_string(driver[i].getCurrentPaycheck())});
    }
    attach(*images[0]);
    for(int i = 0; i < 3; i++){//gets the outboxes ready
        outbox.push_back(new Out_box(Point(i*x_max()/3,170),x_max()/3-5,20,""));
        outbox.push_back(new Out_box(Point(i*x_max()/3,190),x_max()/3-5,20,""));
        outbox.push_back(new Out_box(Point(i*x_max()/3,210),x_max()/3-5,20,""));
    }
    
    //attach all outboxes and set base info
    for(int i = 0; i < outbox.size(); i++){attach(*outbox[i]);}
    outbox[0]->put(info[0][0]);
    outbox[1]->put(info[0][1]);
    outbox[2]->put(info[0][2]);
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
    for(int i = 0; i < places.size(); i++){//gets all the basic info ready to display
        images.push_back(new Image(Point(((i+1)*x_max()/3)-155,50),places[i].image()));
        images[i]->resize(100,100);
        string t;
        for(int j = 0; j < places[i].getTags().size(); j++){
            t += places[i].getTags()[j] + ", ";
        }
        info.push_back({"Name: " + places[0].getName(), "Location: " + places[0].getAddress(), "Tags: " + t});
    }
    attach(*images[0]);
    for(int i = 0; i < 3; i++){//gets the outboxes ready
        outbox.push_back(new Out_box(Point(i*x_max()/3,170),x_max()/3-5,20,""));
        outbox.push_back(new Out_box(Point(i*x_max()/3,190),x_max()/3-5,20,""));
        outbox.push_back(new Out_box(Point(i*x_max()/3,210),x_max()/3-5,20,""));
    }
    
    //attach all outboxes and set base info
    for(int i = 0; i < outbox.size(); i++){attach(*outbox[i]);}
    outbox[0]->put(info[0][0]);
    outbox[1]->put(info[0][1]);
    outbox[2]->put(info[0][2]);
}

void Display_Images::exit(){
    hide();
}

//all the number functions set the number of images to show and clear any starts from beginning
void Display_Images::one(){
    number = 1;
    pos = 0;
    for(int i = 0; i < images.size(); i++){
        try{detach(*images[i]);}catch(...){}
    }
    for(int i = 0; i < outbox.size(); i++){outbox[i]->put("");}
    next();
}
void Display_Images::two(){
    number = 2;
    pos = 0;
    for(int i = 0; i < images.size(); i++){
        try{detach(*images[i]);}catch(...){}
    }
    for(int i = 0; i < outbox.size(); i++){outbox[i]->put("");}
    next();
}
void Display_Images::three(){
    number = 3;
    pos = 0;
    for(int i = 0; i < images.size(); i++){
        try{detach(*images[i]);}catch(...){}
    }
    for(int i = 0; i < outbox.size(); i++){outbox[i]->put("");}
    next();
}

void Display_Images::next(){//removes the old picture and adds the new ones
    if(pos != images.size()){for(int i = 0; i < outbox.size(); i++){outbox[i]->put("");}}
    try{
        for(int i = 0; i < number; i++){
            try{detach(*images[pos-i]);}catch(...){}
            try{images[pos+i]->reposition(Point(((i+1)*x_max()/3)-155,50));}catch(...){}
            try{attach(*images[pos+i]);}catch(...){}
        }
        if(outbox.size() == 9){
            for(int i = 0; i < number; i++){
                try{outbox[i*3]->put(info[pos+i][0]);}catch(...){}
                try{outbox[1+(i*3)]->put(info[pos+i][1]);}catch(...){}
                try{outbox[2+(i*3)]->put(info[pos+i][2]);}catch(...){}
            }
        }else{
            for(int i = 0; i < number; i++){
                try{outbox[i*2]->put(info[pos+i][0]);}catch(...){}
                try{outbox[1+(i*2)]->put(info[pos+i][1]);}catch(...){}
            }
        }
        if(pos+number >= images.size()){pos = images.size();}else{pos += number;}
        redraw();
    }catch(...){}
}
void Display_Images::prev(){//same as next but in reverse
    if(pos == 0){for(int i = 0; i < outbox.size(); i++){outbox[i]->put("");}}
    try{
        for(int i = 0; i < number; i++){
            try{detach(*images[pos+i]);}catch(...){}
            try{images[pos-i]->reposition(Point(((i+1)*x_max()/3)-155,50));}catch(...){}
            try{attach(*images[pos-i]);}catch(...){}
        }
        if(outbox.size() == 9){
            for(int i = 0; i < number; i++){
                try{outbox[i*3]->put(info[pos-i][0]);}catch(...){}
                try{outbox[1+(i*3)]->put(info[pos-i][1]);}catch(...){}
                try{outbox[2+(i*3)]->put(info[pos-i][2]);}catch(...){}
            }
        }else{
            for(int i = 0; i < number; i++){
                try{outbox[i*2]->put(info[pos-i][0]);}catch(...){}
                try{outbox[1+(i*2)]->put(info[pos-i][1]);}catch(...){}
            }
        }
        if(pos-number <= 0){pos = 0;}else{pos -= number;}
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
