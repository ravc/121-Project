# ifndef Print_All_Customer_H
# define Print_All_Customer_H
#include "Print_All_Customer.h"

Print_All_Customer::Print_All_Customer(Point xy, int w, int h, const string& title):

Window(xy,w,h,title),
exit_button(Point(x_max()-70,0), 70, 20, "exit", cb_exit),
next_button(Point(0,0), 70, 20, "next", cb_next),

#endif
