# ifndef Error_Window_H
# define Error_Window_H
#include "Error_Window.h"

//basic window to use for giving errors to the user

Error_Window::Error_Window(Point xy, int w, int h, const string& error):

Window(xy,w,h,"Error"),
ok_button(Point(x_max()/2-35,y_max()/2+20),70,20,"OK",cb_ok),
err(Point(0,y_max()/2),x_max(),20,"Error")
{
    attach(ok_button);
    attach(err);
    err.put(error);
}

void Error_Window::ok(){
    hide();
}
void Error_Window::cb_ok(Address, Address pw){
    reference_to<Error_Window>(pw).ok();
}

#endif
