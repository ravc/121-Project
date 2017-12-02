#include "std_lib_facilities_4.h"
#include "Graphics/GUI.h"
#include "Customer.h"

using namespace Graph_lib;

struct Print_Customer : Graph_lib::Window{
public:
    Print_Customer(Point xy, int w, int h, const string& title, vector<customers>& c);
private:
    vector<customers> custs;
    
    Button back_button;
    Button exit_button;
    Button print_all_button;
    Button print_neg_button;
    
    void exit();
    void back();
    int print_all();
    int print_neg();
    void show_all();
    
    static void cb_exit(Address, Address pw);
    static void cb_back(Address, Address pw);
    static void cb_print_all(Address, Address pw);
    static void cb_print_neg(Address, Address pw);
};
