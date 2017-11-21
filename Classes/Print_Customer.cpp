# ifndef Print_Customer_H
# define Print_Customer_H
#include "Print_Customer.h"

Print_Customer::Print_Customer(Point xy, int w, int h, const string& title):

Windows(xy,w,h,title),
exit_button(Point(x_max()-70,0), 70, 20, "exit", cb_exit),
back_button(Point(0,0), 70, 20, "back", cb_back),
print_all_button(Point((x_max()/2-45), 70), 70, 20, "Print All", cb_print_all),
print_neg_button(Point((x_max()/2+45), 70), 70, 20, "Print Negative", cb_print_neg),
next_button((Point((x_max()/2-35), 70), 70, 20, "Continue", cb_next)
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
    //not sure how to go back to previous window yet
}
void Print_Customer::print_all(){
    //will create next window soon
}
void Print_Customer::print_neg(){
    //coming to a program near you
}
void Print_Customer::next(){
    //not sure what this button is supposed to do
}

void Print_Customer::cb_exit(Address, Address pw){
    reference_to<Print_Customer>(pw).exit_button();
}
void Print_Customer::cb_back(Address, Address pw){
    reference_to<Print_Customer>(pw).back_button();
}
void Print_Customer::cb_print_all(Address, Address pw){
    reference_to<Print_Customer>(pw).print_all_button();
}
void Print_Customer::cb_print_neg(Address, Address pw){
    reference_to<Print_Customer>(pw).print_neg_button();
}
void Print_Customer::cb_next(Address, Address pw){
    reference_to<Print_Customer>(pw).next_button();
}

#endif
