# ifndef Error_Window_H
# define Error_Window_H
#include "Error_Window.h"

Error_Window::Error_Window(Point xy, int w, int h, const string& error):

Window(xy,w,h,"Error"),
ok_button(Point(x_max()/2-35,y_max()/2+20),70,20,"OK",cb_ok),
err(Point(x_max()/2-50,y_max()/2),100,20,"Error")
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
