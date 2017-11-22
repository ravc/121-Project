# ifndef Print_All_Customer_H
# define Print_All_Customer_H
#include "Print_All_Customer.h"

Print_All_Customer::Print_All_Customer(Point xy, int w, int h, const string& title):

Window(xy,w,h,title),
exit_button(Point(x_max()-70,0), 70, 20, "exit", cb_exit),
next_button(Point(0,0), 70, 20, "next", cb_next)
{
    attach(exit_button);
    attach(next_button);
}

void Print_All_Customer::next(){
    //not sure what next is supposed to do
}
void Print_All_Customer::exit(){
    hide();
}

void Print_All_Customer::cb_exit(Address, Address pw){
    reference_to<Print_All_Customer>(pw).exit();
}
void Print_All_Customer::cb_next(Address, Address pw){
    reference_to<Print_All_Customer>(pw).next();
}

#endif
