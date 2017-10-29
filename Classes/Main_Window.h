#include "std_lib_facilities_4.h"
#include "Graphics/GUI.h"

using namespace Graph_lib;

struct Main_Window : Graph_lib::Window{
public:
    Main_Window(Point xy, int w, int h, const string& title);
    
private:
	button quit_button;
	button cust_menu_button;
	button driver_menu_button;
	button place_menu_button;
	button ride_menu_button;
	button display_menu_button;
	menu customerMenu;
	menu driverMenu;
	menu placeMenu;
	menu rideMenu;
	menu displayMenu;
	
	void quit();
    static void cb_quit(Address, Address);
	void custMenuButton();
	void cb_custMenuButton(Address, Address pw);

	void driverMenuButton();
	void cb_driverMenuButton(Address, Address pw);

	void placeMenuButton();
	void cb_placeMenuButton(Address, Address pw);

	void rideMenuButton();
	void cb_rideMenuButton(Address, Address pw);

	void displayMenuButton();
	void cb_displayMenuButton(Address, Address pw);

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
