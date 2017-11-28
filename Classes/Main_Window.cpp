# ifndef Main_Window_H
# define Main_Window_H
#include "Main_Window.h"
#include "Print_Customer.h"
#include "Print_Drivers.h"
#include "Print_Places.h"
#include "Place_Info.h"
#include "Driver.h"

Main_Window::Main_Window(Point xy, int w, int h, const string& title): //setting up the window and buttons
Window(xy,w,h,title),
quit_button(Point(x_max()-70,0), 70, 20, "Quit", cb_quit),
cust_menu_button(Point(0,0),100,20,"Customer Menu",cb_custMenuButton),
customerMenu(Point(0,0),100,20,Menu::vertical,"Customer Menu"),
driver_menu_button(Point(100, 0), 100, 20, "Driver Menu",cb_driverMenuButton),
driverMenu(Point(100,0),100,20,Menu::vertical,"Driver Menu"),
place_menu_button(Point(200, 0), 100, 20, "Place Menu",cb_placeMenuButton),
placeMenu(Point(200,0),100,20,Menu::vertical,"Place Menu"),
ride_menu_button(Point(300, 0), 100, 20, "Ride Menu",cb_rideMenuButton),
rideMenu(Point(300,0),100,20,Menu::vertical,"Ride Menu"),
display_menu_button(Point(400, 0), 100, 20, "Display Menu",cb_displayMenuButton),
displayMenu(Point(400,0),100,20,Menu::vertical,"Display")
{
    customerMenu.attach(new Button(Point(0, 0), 0, 0, "Add Customer",cb_addCustomer));
    customerMenu.attach(new Button(Point(0, 0), 0, 0, "Remove Customer", cb_removeCustomer));
    driverMenu.attach(new Button(Point(0, 0), 0, 0, "Add Driver", cb_addDriver));
    driverMenu.attach(new Button(Point(0, 0), 0, 0, "Remove Driver", cb_removeDriver));
    placeMenu.attach(new Button(Point(0, 0), 0, 0, "Add Place", cb_addPlace));
    placeMenu.attach(new Button(Point(0, 0), 0, 0, "Remove Place", cb_removePlace));
    rideMenu.attach(new Button(Point(0, 0), 0, 0, "Pay Balance", cb_payBalance));
    rideMenu.attach(new Button(Point(0, 0), 0, 0, "Request Ride", cb_requestRide));
    displayMenu.attach(new Button(Point(0, 0), 0, 0, "Display Customers", cb_displayCustomers));
    displayMenu.attach(new Button(Point(0, 0), 0, 0, "Display Drivers", cb_displayDrivers));
    displayMenu.attach(new Button(Point(0, 0), 0, 0, "Display Places", cb_displayPlaces));
    attach(quit_button);
    attach(cust_menu_button);
    attach(driver_menu_button);
    attach(place_menu_button);
    attach(ride_menu_button);
    attach(display_menu_button);
    attach(customerMenu);
    attach(driverMenu);
    attach(placeMenu);
    attach(rideMenu);
    attach(displayMenu);
    customerMenu.hide();
    driverMenu.hide();
    placeMenu.hide();
    rideMenu.hide();
    displayMenu.hide();
    
    
}

void Main_Window::show_main_window(){
    show();
}
void Main_Window::quit(){
    hide();
}
void Main_Window::cb_quit(Address, Address pw){
    reference_to<Main_Window>(pw).quit();
}

void Main_Window::custMenuButton() {
    cust_menu_button.hide();
    customerMenu.show();
}
void Main_Window::cb_custMenuButton(Address, Address pw) {
    reference_to<Main_Window>(pw).custMenuButton();
}

void Main_Window::driverMenuButton() {
    driver_menu_button.hide();
    driverMenu.show();
}
void Main_Window::cb_driverMenuButton(Address, Address pw) {
    reference_to<Main_Window>(pw).driverMenuButton();
}

void Main_Window::placeMenuButton() {
    place_menu_button.hide();
    placeMenu.show();
}
void Main_Window::cb_placeMenuButton(Address, Address pw) {
    reference_to<Main_Window>(pw).placeMenuButton();
}

void Main_Window::rideMenuButton() {
    ride_menu_button.hide();
    rideMenu.show();
}
void Main_Window::cb_rideMenuButton(Address, Address pw) {
    reference_to<Main_Window>(pw).rideMenuButton();
}

void Main_Window::displayMenuButton() {
    display_menu_button.hide();
    displayMenu.show();
}
void Main_Window::cb_displayMenuButton(Address, Address pw) {
    reference_to<Main_Window>(pw).displayMenuButton();
}

void Main_Window::addCustomer() {
    
}
void Main_Window::cb_addCustomer(Address, Address pw) {
    reference_to<Main_Window>(pw).addCustomer();
}

void Main_Window::removeCustomer() {
    
}
void Main_Window::cb_removeCustomer(Address, Address pw) {
    reference_to<Main_Window>(pw).removeCustomer();
}

void Main_Window::addDriver() {
    
}
void Main_Window::cb_addDriver(Address, Address pw) {
    reference_to<Main_Window>(pw).addDriver();
}

void Main_Window::removeDriver() {
    
}
void Main_Window::cb_removeDriver(Address, Address pw) {
    reference_to<Main_Window>(pw).removeDriver();
}

void Main_Window::addPlace() {
    
}
void Main_Window::cb_addPlace(Address, Address pw) {
    reference_to<Main_Window>(pw).addPlace();
}

void Main_Window::removePlace() {
    
}
void Main_Window::cb_removePlace(Address, Address pw) {
    reference_to<Main_Window>(pw).removePlace();
}

void Main_Window::payBalance() {
    
}
void Main_Window::cb_payBalance(Address, Address pw) {
    reference_to<Main_Window>(pw).payBalance();
}

void Main_Window::requestRide() {
    
}
void Main_Window::cb_requestRide(Address, Address pw) {
    reference_to<Main_Window>(pw).requestRide();
}

int Main_Window::displayCustomers() {
    hide();
    while(true){
        Print_Customer win(Point(100,100),600,400,"My Ride");
        return gui_main();
    }
}
void Main_Window::cb_displayCustomers(Address, Address pw) {
    reference_to<Main_Window>(pw).displayCustomers();
    reference_to<Main_Window>(pw).show_main_window();
}

int Main_Window::displayDrivers() {
    vector<Place_Info> p;
    vector<drivers> d;
    hide();
    while(true){
        Print_Drivers win(Point(100,100),600,400,"My Ride",p,d);
        return gui_main();
    }
}
void Main_Window::cb_displayDrivers(Address, Address pw) {
    reference_to<Main_Window>(pw).displayDrivers();
    reference_to<Main_Window>(pw).show_main_window();
}

int Main_Window::displayPlaces() {
    vector<Place_Info> p;
    hide();
    while(true){
        Print_Places win(Point(100,100),600,400,"My Ride",p);
        return gui_main();
    }
}
void Main_Window::cb_displayPlaces(Address, Address pw) {
    reference_to<Main_Window>(pw).displayPlaces();
    reference_to<Main_Window>(pw).show_main_window();
}

#endif
