#include "std_lib_facilities_4.h"
#include "Graphics/GUI.h"

using namespace Graph_lib;

struct Main_Window : Graph_lib::Window{
public:
    Main_Window(Point xy, int w, int h, const string& title);
    
private:
	Button quit_button;
	Button cust_menu_button;
	Button driver_menu_button;
	Button place_menu_button;
	Button ride_menu_button;
	Button display_menu_button;
	menu customerMenu;
	menu driverMenu;
	menu placeMenu;
	menu rideMenu;
	menu displayMenu;
	
	void quit();
    static void cb_quit(Address, Address);
	void custMenubutton();
	void cb_custMenubutton(Address, Address pw);

	void driverMenubutton();
	void cb_driverMenubutton(Address, Address pw);

	void placeMenubutton();
	void cb_placeMenubutton(Address, Address pw);

	void rideMenubutton();
	void cb_rideMenubutton(Address, Address pw);

	void displayMenubutton();
	void cb_displayMenubutton(Address, Address pw);

	void addCustomer();
	void cb_addCustomer(Address, Address pw);

	void removeCustomer();
	void cb_removeCustomer(Address, Address pw);

	void addDriver();
	void cb_addDriver(Address, Address pw);

	void removeDriver();
	void cb_removeDriver(Address, Address pw);

	void addPlace();
	void cb_addPlace(Address, Address pw);

	void removePlace();
	void cb_removePlace(Address, Address pw);

	void payBalance();
	void cb_payBalance(Address, Address pw);

	void requestRide();
	void cb_requestRide(Address, Address pw);

	void displayCustomers();
	void cb_displayCustomers(Address, Address pw);

	void displayDrivers();
	void cb_displayDrivers(Address, Address pw);

	void displayPlaces();
	void cb_displayPlaces(Address, Address pw);
};
