#include "std_lib_facilities_4.h"
#include "Graphics/GUI.h"

using namespace Graph_lib;

struct Print_Customer : Graph_lib::Window{
public:
    Print_Customer(Point xy, int w, int h, const string& title);
private:
    Button back_button;
    Button exit_button;
    Button print_all_button;
    Button print_neg_button;
    Button next_button;
    
    void exit();
    void back();
    void print_all();
    void print_neg();
    void next();
    
    static void cb_exit(Address, Address pw);
    static void cb_back(Address, Address pw);
    static void cb_print_all(Address, Address pw);
    static void cb_print_neg(Address, Address pw);
    static void cb_next(Address, Address pw);
};
