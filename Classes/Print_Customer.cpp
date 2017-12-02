# ifndef Print_Customer_H
# define Print_Customer_H
#include "Print_Customer.h"
#include "Display_Images.h"

Print_Customer::Print_Customer(Point xy, int w, int h, const string& title, vector<customers>& c):

Window(xy,w,h,title),
exit_button(Point(x_max()-70,0), 70, 20, "exit", cb_exit),
back_button(Point(0,0), 70, 20, "back", cb_back),
print_all_button(Point((x_max()/2-200), 70), 100, 20, "Print All", cb_print_all),
print_neg_button(Point((x_max()/2+100), 70), 100, 20, "Print Negative", cb_print_neg),
custs(c)
{
    attach(exit_button);
    attach(back_button);
    attach(print_all_button);
    attach(print_neg_button);
    back_button.hide();
}

void Print_Customer::show_all(){
    show();
    print_all_button.show();
    print_neg_button.show();
}
void Print_Customer::exit(){
    hide();
}
void Print_Customer::back(){
    print_all_button.show();
    print_neg_button.show();
    back_button.hide();
}
int Print_Customer::print_all(){
    back_button.show();
    print_all_button.hide();
    print_neg_button.hide();
    hide();
    while(true){
        Display_Images win(Point(100,100),600,400,"My Ride",custs);
        return gui_main();
    }
}
int Print_Customer::print_neg(){
    back_button.show();
    print_all_button.hide();
    print_neg_button.hide();
    hide();
    vector<customers> cu;
    for(int i = 0; i < custs.size(); i++){
        if(custs[i].getAccountBalance() < 0){
            cu.push_back(custs[i]);
        }
    }
    while(true){
        Display_Images win(Point(100,100),600,400,"My Ride",cu);
        return gui_main();
    }
}

void Print_Customer::cb_exit(Address, Address pw){
    reference_to<Print_Customer>(pw).exit();
}
void Print_Customer::cb_back(Address, Address pw){
    reference_to<Print_Customer>(pw).back();
}
void Print_Customer::cb_print_all(Address, Address pw){
    reference_to<Print_Customer>(pw).print_all();
    reference_to<Print_Customer>(pw).show_all();
}
void Print_Customer::cb_print_neg(Address, Address pw){
    reference_to<Print_Customer>(pw).print_neg();
    reference_to<Print_Customer>(pw).show_all();
}

#endif
