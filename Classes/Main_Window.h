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
    Menu customerMenu;
    Menu driverMenu;
    Menu placeMenu;
    Menu rideMenu;
    Menu displayMenu;
    
    void quit();
    static void cb_quit(Address, Address);

    void custMenuButton();
    static void cb_custMenuButton(Address, Address pw);
    
    void driverMenuButton();
    static void cb_driverMenuButton(Address, Address pw);
    
    void placeMenuButton();
    static void cb_placeMenuButton(Address, Address pw);
    
    void rideMenuButton();
    static void cb_rideMenuButton(Address, Address pw);
    
    void displayMenuButton();
    static void cb_displayMenuButton(Address, Address pw);
    
    void addCustomer();
    static void cb_addCustomer(Address, Address pw);
    
    void removeCustomer();
    static void cb_removeCustomer(Address, Address pw);
    
    void addDriver();
    static void cb_addDriver(Address, Address pw);
    
    void removeDriver();
    static void cb_removeDriver(Address, Address pw);
    
    void addPlace();
    static void cb_addPlace(Address, Address pw);
    
    void removePlace();
    static void cb_removePlace(Address, Address pw);
    
    void payBalance();
    static void cb_payBalance(Address, Address pw);
    
    void requestRide();
    static void cb_requestRide(Address, Address pw);
    
    void displayCustomers();
    static void cb_displayCustomers(Address, Address pw);
    
    void displayDrivers();
    static void cb_displayDrivers(Address, Address pw);
    
    void displayPlaces();
    static void cb_displayPlaces(Address, Address pw);
};
