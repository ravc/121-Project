//Josh Haynes CSCE 121-200 project add/remove customers,places, and drivers
#include "std_lib_facilities_4.h"
#include "Graphics/GUI.h"
#include "Customer.h"
#include "Driver.h"
#include "Place_Info.h"
using namespace Graph_lib;
//cust structs
struct add_cust_window : Graph_lib::Window{
public:
    add_cust_window(Point xy, int w, int h, const string& title);
private:
	//buttons etc
	In_box name;
	In_box balance;
	In_box photo;
	Button quit_button;
	Button proceed;
	//functions
	void quit();
	void proceeder();
    static void cb_quit(Address, Address);
    static void cb_proceed(Address,Address pw);
};
add_cust_window::add_cust_window(Point xy,int w,int h,const string& title):
	Window(xy,w,h,title),
	name(Point(170,100),100,20,"customer name: "),
	balance(Point(170,150),100,20,"customer balance: "),
	photo(Point(170,200),100,20,"photo FILE NAME: "),
	proceed(Point(320,340),70,20,"add",cb_proceed),
	quit_button(Point(340,370),50,20,"quit",cb_quit)
{
	attach(name);
	attach(quit_button);
	attach(balance);
	attach(photo);
	attach(proceed);
}
//functions
void add_cust_window::cb_quit(Address, Address pw) {
  reference_to<add_cust_window>(pw).quit();   // quit is defined next
}
void add_cust_window::quit() {
  hide();                   // FLTK idiom for delete window
}
void add_cust_window::cb_proceed(Address,Address pw){
	reference_to<add_cust_window>(pw).proceeder();
}
void add_cust_window::proceeder(){
	//take inbox data and create a customer
	string namein = name.get_string();
	int balancein = balance.get_int();
	string photoin = photo.get_string();
	//cout << namein << ", " << balancein << ", " << photoin <<"\n";
	customers c(namein,balancein,photoin);//construct custo
	listOfCustomers.push_back(c);//add customer to vector
	hide();
}
struct remove_cust_window : Graph_lib::Window{
public:
    remove_cust_window(Point xy, int w, int h, const string& title);
private:
	//buttons etc
	In_box name;
	Button quit_button;
	Button proceed;
	//functions
	void quit();
	void proceeder();
    static void cb_quit(Address, Address);
    static void cb_proceed(Address,Address pw);
};
remove_cust_window::remove_cust_window(Point xy,int w,int h, const string& title): 
		Window(xy,w,h,title),
		name(Point(170,100),100,20,"customer name: "),
		proceed(Point(320,340),70,20,"remove",cb_proceed),
		quit_button(Point(340,370),50,20,"quit",cb_quit)
{
	attach(name);
	attach(quit_button);
	attach(proceed);
}
void remove_cust_window::cb_quit(Address, Address pw) {
  reference_to<remove_cust_window>(pw).quit();   // quit is defined next
}
void remove_cust_window::quit() {
  hide();                   // FLTK idiom for delete window
}
void remove_cust_window::cb_proceed(Address, Address pw){
	reference_to<remove_cust_window>(pw).proceeder();
}
void remove_cust_window::proceeder(){
	string nametbd = name.get_string();
	for (int i = 0;i < custos.size();i++){
	 	if (listOfCustomers[i].getName() == nametbd){
	 		listOfCustomers.erase(listOfCustomers.begin()+i);
		 }
	}
	hide();
}
//place structs
struct add_tag_window : Graph_lib::Window{
public:
	vector<string> tags_in;
	Geo_Loc gloc;
	string namein,addyin,photoin;
	add_tag_window(Point xy,int w,int h,const string& title,string n,string a,string p,Geo_Loc g,vector<string> t);
private:

	//vstring tagget;
	In_box tag;
	Button quit_button;
	Button proceed;
	void quit();
	int proceeder();
    static void cb_quit(Address, Address);
    static void cb_proceed(Address,Address pw);
};
add_tag_window::add_tag_window(Point xy,int w,int h,const string& title,string n,string a,string p,Geo_Loc g,vector<string> t): Window(xy,w,h,title),tag(Point(110,110),100,20,"tag"),proceed(Point(250,330),140,20,"add another tag",cb_proceed),
quit_button(Point(290,350),100,40,"no more tags\n(create place)",cb_quit),namein(n),addyin(a),photoin(p),gloc(g),tags_in(t){
	attach(tag);
	attach(quit_button);
	attach(proceed);
}
void add_tag_window::cb_quit(Address,Address pw){
	reference_to<add_tag_window>(pw).quit();
}
void add_tag_window::quit(){
	Place_Info p(namein,addyin,tags_in,gloc,photoin);
	listOfPlaces.push_back(p);
	hide();
}
void add_tag_window::cb_proceed(Address,Address pw){
	reference_to<add_tag_window>(pw).proceeder();
}
int add_tag_window::proceeder(){
	string tagin = tag.get_string();
	tags_in.push_back(tagin);
	//somehow return this to add_place_window::proceeder
	hide();
	while (true){//open a new window, get a new tag
    	add_tag_window win2(Point(100,100),400,400,"tag",namein,addyin,photoin,gloc,tags_in);
    	return gui_main();
	}
}
struct add_place_window : Graph_lib::Window{
public:
    add_place_window(Point xy, int w, int h, const string& title);
private:
	vector<string> tagsin;
	//buttons etc
	In_box name;
	In_box photo;
	In_box address;
	In_box lat;
	In_box lon;
	//In_box num_tags;
	Button quit_button;
	Button proceed;
	//functions
	void quit();
	int proceeder();
    static void cb_quit(Address, Address);
    static void cb_proceed(Address,Address pw);
};
add_place_window::add_place_window(Point xy,int w,int h,const string& title):
	Window(xy,w,h,title),
	name(Point(170,90),100,20,"place name: "),
	photo(Point(170,120),100,20,"photo FILE NAME: "),
	address(Point(170,150),100,20,"address: "),
	lat(Point(170,200),100,20,"latitude: "),
	lon(Point(170,230),100,20,"longitude"),
	//num_tags(Point(170,260),100,20,"number of tags: "),
	proceed(Point(260,340),130,20,"proceed to tags",cb_proceed),
	quit_button(Point(340,370),50,20,"quit",cb_quit)
{
	attach(name);
	attach(quit_button);
	attach(address);
	attach(lon);
	attach(lat);
	attach(photo);
	//(num_tags);
	attach(proceed);
}
//functions
void add_place_window::cb_quit(Address, Address pw) {
  reference_to<add_place_window>(pw).quit();   // quit is defined next
}
void add_place_window::quit() {
  hide();                   // FLTK idiom for delete window
}
void add_place_window::cb_proceed(Address,Address pw){
	reference_to<add_place_window>(pw).proceeder();
}
int add_place_window::proceeder(){
	string photoin = photo.get_string();
	string namein = name.get_string();
	string addyin = address.get_string();
	int longi = lon.get_int();
	int lati = lat.get_int();
	Geo_Loc g(lati,longi);
	hide();
	while (true){//open a new window, get a new tag
    	add_tag_window win2(Point(100,100),400,400,"tag",namein,addyin,photoin,g,tagsin);
    	return gui_main();
	}
	// Place_Info p(namein,addyin,tagsin,g);
	// places.push_back(p);
}
struct remove_place_window : Graph_lib::Window{
public:
    remove_place_window(Point xy, int w, int h, const string& title);
private:
	//buttons etc
	In_box name;
	Button quit_button;
	Button proceed;
	//functions
	void quit();
	void proceeder();
    static void cb_quit(Address, Address);
    static void cb_proceed(Address,Address pw);
};
remove_place_window::remove_place_window(Point xy,int w,int h, const string& title): 
		Window(xy,w,h,title),
		name(Point(170,100),100,20,"place name: "),
		proceed(Point(320,340),70,20,"remove",cb_proceed),
		quit_button(Point(340,370),50,20,"quit",cb_quit)
{
	attach(name);
	attach(quit_button);
	attach(proceed);
}
void remove_place_window::cb_quit(Address, Address pw) {
  reference_to<remove_place_window>(pw).quit();   // quit is defined next
}
void remove_place_window::quit() {
  hide();                   // FLTK idiom for delete window
}
void remove_place_window::cb_proceed(Address, Address pw){
	reference_to<remove_place_window>(pw).proceeder();
}
void remove_place_window::proceeder(){
	string nametbd = name.get_string();
	for (int i = 0;i < places.size();i++){
	 	if (listOfPlaces[i].getName() == nametbd){
	 		//cout<<places[i].getName();
	 		listOfPlaces.erase(listOfPlaces.begin()+i);
		}
	}
	hide();
}
//driver structs
struct add_driver_window : Graph_lib::Window{
public:
    add_driver_window(Point xy, int w, int h, const string& title);
private:
	//buttons etc
	In_box name;
	In_box balance;
	In_box photo;
	Button quit_button;
	Button proceed;
	In_box lat;
	In_box lon;
	//functions
	void quit();
	void proceeder();
    static void cb_quit(Address, Address);
    static void cb_proceed(Address,Address pw);
};
add_driver_window::add_driver_window(Point xy,int w,int h,const string& title):
	Window(xy,w,h,title),
	name(Point(170,100),100,20,"driver name: "),
	balance(Point(170,150),100,20,"driver balance: "),
	photo(Point(170,200),100,20,"photo FILE NAME: "),
	lat(Point(170,230),100,20,"lattitude: "),
	lon(Point(170,260),100,20,"longitude: "),
	proceed(Point(320,340),70,20,"add",cb_proceed),
	quit_button(Point(340,370),50,20,"quit",cb_quit)
{
	attach(name);
	attach(quit_button);
	attach(balance);
	attach(photo);
	attach(proceed);
	attach(lat);
	attach(lon);
}
//functions
void add_driver_window::cb_quit(Address, Address pw) {
  reference_to<add_driver_window>(pw).quit();   // quit is defined next
}
void add_driver_window::quit() {
  hide();                   // FLTK idiom for delete window
}
void add_driver_window::cb_proceed(Address,Address pw){
	reference_to<add_driver_window>(pw).proceeder();
}
void add_driver_window::proceeder(){
	//take inbox data and create a customer
	string namein = name.get_string();
	int balancein = balance.get_int();
	string photoin = photo.get_string();
	int lati = lat.get_int();
	int longi = lon.get_int();
	//cout << namein << ", " << balancein << ", " << photoin <<"\n";
	//drivers d(namein,balancein);//construct custo
	Geo_Loc g(lati,longi);
	drivers d(g,namein,balancein,photoin);
	listOfDrivers.push_back(d);
	hide();
}
struct remove_driver_window : Graph_lib::Window{
public:
    remove_driver_window(Point xy, int w, int h, const string& title);
private:
	//buttons etc
	In_box name;
	Button quit_button;
	Button proceed;
	//functions
	void quit();
	void proceeder();
    static void cb_quit(Address, Address);
    static void cb_proceed(Address,Address pw);
};
remove_driver_window::remove_driver_window(Point xy,int w,int h, const string& title): 
		Window(xy,w,h,title),
		name(Point(170,100),100,20,"driver name: "),
		proceed(Point(320,340),70,20,"remove",cb_proceed),
		quit_button(Point(340,370),50,20,"quit",cb_quit)
{
	attach(name);
	attach(quit_button);
	attach(proceed);
}
void remove_driver_window::cb_quit(Address, Address pw) {
  reference_to<remove_driver_window>(pw).quit();   // quit is defined next
}
void remove_driver_window::quit() {
  hide();                   // FLTK idiom for delete window
}
void remove_driver_window::cb_proceed(Address, Address pw){
	reference_to<remove_driver_window>(pw).proceeder();
}
void remove_driver_window::proceeder(){
	string nametbd = name.get_string();
	for (int i = 0;i < driverss.size();i++){
	 	if (listOfDrivers[i].getName() == nametbd){
	 		listOfDrivers.erase(listOfDrivers.begin()+i);
		 }
	}
	hide();
}