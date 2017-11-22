# ifndef Print_Customer_H
# define Print_Customer_H
#include "Print_Customer.h"
#include "Print_All_Customer.h"

Print_Customer::Print_Customer(Point xy, int w, int h, const string& title):

Window(xy,w,h,title),
exit_button(Point(x_max()-70,0), 70, 20, "exit", cb_exit),
back_button(Point(0,0), 70, 20, "back", cb_back),
print_all_button(Point((x_max()/2-200), 70), 100, 20, "Print All", cb_print_all),
print_neg_button(Point((x_max()/2+100), 70), 100, 20, "Print Negative", cb_print_neg),
next_button(Point((x_max()/2-50), 200), 100, 20, "Continue", cb_next)
{
    attach(exit_button);
    attach(back_button);
    attach(print_all_button);
    attach(print_neg_button);
    attach(next_button);
}

void Print_Customer::exit(){
    hide();
}
void Print_Customer::back(){
    hide();
}
int Print_Customer::print_all(){
    while(true){
        Print_All_Customer win(Point(100,100),600,400,"My Ride");
        return gui_main();
    }
}
void Print_Customer::print_neg(){
    //coming to a program near you
}
void Print_Customer::next(){
    //not sure what this button is supposed to do
}

void Print_Customer::cb_exit(Address, Address pw){
    reference_to<Print_Customer>(pw).exit();
}
void Print_Customer::cb_back(Address, Address pw){
    reference_to<Print_Customer>(pw).back();
}
void Print_Customer::cb_print_all(Address, Address pw){
    reference_to<Print_Customer>(pw).print_all();
}
void Print_Customer::cb_print_neg(Address, Address pw){
    reference_to<Print_Customer>(pw).print_neg();
}
void Print_Customer::cb_next(Address, Address pw){
    reference_to<Print_Customer>(pw).next();
}

#endif
