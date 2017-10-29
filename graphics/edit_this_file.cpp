#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"

int main()
try {
  Simple_window win1(Point(100,200),600,400,"two lines");
  Line horizontal(Point(100,100),Point(200,100));  // make a horizontal line
  Line vertical(Point(150,50),Point(150,150));     // make a vertical line
  win1.attach(horizontal);
  win1.attach(vertical);
  vertical.set_color(Color::magenta);
  win1.wait_for_button();
  return 0;
}
catch(exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
}
