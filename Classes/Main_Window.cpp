# ifndef Main_Window_H
# define Main_Window_H
#include "Main_Window.h"

main_window::main_window(Point xy, int w, int h, const string& title): //setting up the window and buttons
    Window(xy,w,h,title),
    quit_button(Point(x_max()-70,0), 70, 20, "Quit", cb_quit),
    {
        attach(quit_button);
    }

void Main_Window::quit(){
    hide()
}

void Main_Window::cb_quit(Address, Address pw){
    reference_to<main_window>(pw).quit();
}
