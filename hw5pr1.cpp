/*
 * Ruben A. Vazquez-Chapa
 * Fall Semester 2017 (Oct 2)
 * Solution for Homework 5
 * 
 * This program is based from my hw3pr2.cpp
 * and has been modified to work with
 * reading and writing to files. If the 
 * file is in the same directory just type 
 * the file name with extension if not give the 
 * full path of the file.
 */

#include "std_lib_facilities_4.h"

class Geo_loc{
    public:
        void set_location(vector<double> loc) {location.push_back(loc);} //adds a location to the vector
        double lat(int index) {return location[index][0];} //returns the latitude
        double lon(int index) {return location[index][1];} //returns the longitude
        void remove_last_loc() {location.erase(location.end());} //removes the last stored location
        int size_of() {return location.size();} //returns the number of locations
        Geo_loc() {};
        vector<double> coor(int index){return location[index];} //returns the coordinates for a location
    
    private:
        vector< vector<double> > location;
};
class Place_info{
    public:
        void add_place(string name, string addr, vector<string> tag, vector<double> coor){ // creates a new place
            place_name.push_back(name); //adds the name
            address.push_back(addr); //adds the address
            tags.push_back(tag); //adds the tags
            loc.set_location(coor); //add the coordinates
        }
        string name(int index) {return place_name[index];} //returns the name of a place
        string addr(int index) {return address[index];} //returns the address of a place
        vector<string> tag(int index) {return tags[index];} //returns a vector containing tags
        void remove_last_place() { //removes the last place added
            place_name.erase(place_name.end());
            address.erase(address.end());
            tags.erase(tags.end());
            loc.remove_last_loc();
        }
        vector<string> available_places() {return place_name;} //returns the current available places
        int location_index(string name){ //returns the index of a location
            for(unsigned i = 0; i < place_name.size(); i++){
                if(name == place_name[i]){
                    return i;
                }
            }
            return -99;
        }
        string places_to_file(){ //writes the available places to a file
            string places;
            for(unsigned i = 0; i < place_name.size(); i++){
                places += place_name[i] + " " + address[i] + " " + to_string(loc.lat(i)) + " " + to_string(loc.lon(i)) + " " + to_string(tags[i].size()) + " ";
                for(unsigned j = 0; j < tags[i].size(); j++){
                    places += tags[i][j] + " ";
                }
                places += "\n";
            }
            return places;
        }
        void info_of_places(){ //prints out the info of all the places
            for(unsigned i = 0; i < place_name.size(); i++){
                cout << place_name[i] << endl << address[i] << endl;
                cout << "Tags" << endl;
                for(unsigned j = 0; j < tags[i].size(); j++){
                    cout << tags[i][j] << endl;
                }
            }
        }
        Place_info() {};
        Geo_loc loc; //calls the Geo_loc class
        
    private:
        vector<string> place_name; //stores the names of each place
        vector<string> address; //stores the address of each place
        vector< vector<string> > tags; //stores the tags of each place
};
class My_Ride{
    public:
        void add_customer(string name, double account) { //adds a customer
            customer.push_back(name); //gives the customer a name
            customer_account.push_back(account); //gives the customer a starting balance
        }
        void add_driver(string name, double lat, double lon, double account) { //adds a driver
            driver.push_back(name); //gives the driver a name
            driver_account.push_back(account); //gives the driver a starting balance
            driver_location.push_back({lat,lon});
        }
        void make_payment(double distance, int customer, int driver) { //deducts money from the customer and adds to a user
            customer_account[customer] -= distance;
            driver_account[driver] += distance/2;
        }
        void update_location(string name, double lat, double lon) { //updates the location of a customer or driver
            for(unsigned i = 0; i < driver.size(); i++){ //finds the driver
                if(driver[i] == name){
                    driver_location[i] = {lat, lon}; //sets the place
                    return;
                }
            }
        }
        vector<double> location_of(int index){ //finds the location of a given person
            return driver_location[index];
        }
        vector< vector<double> > locations_of(){ //finds all the locations of a driver
            return driver_location;
        }
        void customer_info(int index) { //returns the information of a certain customer
            cout << customer[index] << " has a balance of " << customer_account[index] << endl;
        }
        void driver_info(int index) { //returns the information of a certain driver
            cout << driver[index] + " is at " << driver_location[index][0] << " " << driver_location[index][1]  << endl;
            cout << " and has a balance of " << driver_account[index] << endl;
        }
        string name(string who, int index){ //returns the name of a customer or driver
            if(who == "driver"){
                return driver[index];
            }else{
                return customer[index];
            }
        }
        int index(string who, string name){ //returns the index value of a customer or driver
            if(who == "driver"){
                for(unsigned i = 0; i < driver.size(); i++){ //finds the driver
                    if(name == driver[i]){
                        return i;
                    }
                }
            }else{
                for(unsigned i = 0; i < customer.size(); i++){ //finds the customer
                    if(name == customer[i]){
                        return i;
                    }
                }
            }
            return -99;
        }
        void add_fund(string who, string name, double amount){ //adds money to a certain person
            int person = index(who, name);
            if(who == "driver"){
                driver_account[person] += amount;
            }else{
                customer_account[person] += amount;
            }
        }
        vector<string> current_drivers() {return driver;} //returns all the drivers
        vector<string> current_customers() {return customer;} //returns all the customers
        string drivers_to_file(){ //writes the drivers to the file
            string drivers;
            for(unsigned i = 0; i < driver.size(); i++){
                drivers += driver[i] + " " + to_string(driver_account[i]) + " " + to_string(driver_location[i][0]) + " " + to_string(driver_location[i][1]) + "\n";
            }
            return drivers;
        }
        string customers_to_file(){ //writes the customers to the file
            string customers;
            for(unsigned i = 0; i < customer.size(); i++){
                customers += customer[i] + " " + to_string(customer_account[i]) + "\n";
            }
            return customers;
        }
        My_Ride() {};
        Place_info place; //calls the Place_info class
    
    private:
        vector< vector<double> > driver_location; //stores the location of the drivers
        vector<string> driver; //stores the name of the drivers
        vector<string> customer; //stores the name of the customers
        vector<double> customer_account; //stores the customers balance
        vector<double> driver_account; //stores the drives balance
};

double deg_to_rad(double degrees){ //converts degrees ro radians
    constexpr double pi = 4*atan(1); //trigonomic way to calculate Pi
    return (degrees * (pi/180));
}
double distance(My_Ride& ride, int point_a, int point_b){ //calculates distance between two points
    constexpr double radius = 3963.1676; //given radius of the earth in miles
    double x1 = deg_to_rad(ride.place.loc.lat(point_a));
    double x2 = deg_to_rad(ride.place.loc.lat(point_b));
    double y1 = deg_to_rad(ride.place.loc.lon(point_a));
    double y2 = deg_to_rad(ride.place.loc.lon(point_b));
    
    return (acos((sin(x1)*sin(x2)) + (cos(x1)*cos(x2)*cos(y1-y2)))*radius); //equation given to calculate distance
}
void display_place_information(My_Ride& ride, int place_one, int place_two){ //displays the information of some places
    cout << endl << ride.place.name(place_two) << " - " << ride.place.addr(place_two) << endl;
    cout << endl << "TAGS" << endl;
    
    for(unsigned i = 0; i < ride.place.tag(place_two).size(); i++){
        cout << ride.place.tag(place_two)[i] << endl;
    }
    
    cout << endl << "The distance between " << ride.place.name(place_one) << " and";
    cout << endl << ride.place.name(place_two) << " is ";
    cout << distance(ride, place_one, place_two);
    cout << " miles" << endl;
}
bool in_range(double latitude, double longitude){ //checks to see if all coordinates are in range
    vector<int> boolean_vector;
        
    if((latitude >= -90) && (latitude <= 90)){
        boolean_vector.push_back(1);
    }
    if((longitude >= -180) && (longitude <= 180)){
        boolean_vector.push_back(1);
    }
    
    if(boolean_vector.size() == 2){ //if the vector is of size 2 then all coordinates are valid
        return true;
    }else{
        return false;
    }
}
string search_by_tag(My_Ride& ride, string look_for, string start){ //searches for a place by tags
    vector<string> closest_match;
    int found = 0;
    
    for(unsigned i = 0; i < ride.place.available_places().size(); i++){
        for(unsigned j = 0; j < ride.place.tag(i).size(); j++){
            if(ride.place.tag(i)[j] == look_for){
                closest_match.push_back(ride.place.available_places()[i]);
                found = 1;
            }
        }
    }
    
    unique(closest_match.begin(), closest_match.end());
    
    vector< vector<double> > closest_tag;
    for(unsigned i = 0; i < closest_match.size(); i++){
        closest_tag.push_back({distance(ride, ride.place.location_index(start) , ride.place.location_index(closest_match[i])), double(i)});
    }
    
    sort(closest_tag.begin(), closest_tag.end());
    
    if(found){
        return closest_match[closest_tag[0][1]];
    }else{
        cout << "No place found for the tag" << endl;
        return {"0"};
    }
}
int nearest_driver(My_Ride& ride, string where){ //finds the nearest driver
    vector< vector<double> > driver_loc = ride.locations_of();
    int location;
    
    for(unsigned i = 0; i < driver_loc.size(); i++){
        if(ride.place.loc.coor(ride.place.location_index(where))[0] == driver_loc[i][0] && ride.place.loc.coor(ride.place.location_index(where))[1] == driver_loc[i][1]){
            return i;
        }
    }
    
    vector<string> places = ride.place.available_places();
    
    for(unsigned i = 0; i < places.size(); i++){
        if(where == places[i]){
            location = i;
            break;
        }
    }
    
    vector< vector<double> > distances;
    
    for(unsigned i = 0; i < driver_loc.size(); i++){
        distances.push_back({distance(ride, location, i), double(i)}); //this way i can store the index of each location and sort by distance
    }
    
    sort(distances.begin(), distances.end());
    
    return distances[0][1]; //returns the location index
}
void request_ride(My_Ride& ride, string customer, int start, string where){ //requests a ride
    int customer_index = ride.index("customer", customer); //finds the customer
    int driver_index = nearest_driver(ride, where); //finds the driver
    double miles = distance(ride, start, ride.place.location_index(where)); //calculates the miles driven
    ride.make_payment(miles, customer_index, driver_index); //pays and deducts accounts
    ride.update_location(ride.name("driver", driver_index), ride.location_of(driver_index)[0], ride.location_of(driver_index)[1]); //updates the location of the driver
}
string options(){ //lists all the available options
    string opt;
    
    cout << "please chose an option" << endl << endl;
    cout << "1) Add customer" << endl << "2) Add Driver" << endl;
    cout << "3) Add a place" << endl << "4) Add money" << endl;
    cout << "5) Request a ride" << endl << "6) Print customer info" << endl;
    cout << "7) Print driver info" << endl << "8) Print Place info" << endl;
    cout << "9) Quit" << endl;
    
    cin >> opt;
    
    return opt;
}
void add_customers(My_Ride& ride){//adds a customer
    string name;
    double starting_balance;
    
    cout << "Name of the customer: ";
    cin >> name;
    
    cout << "Starting Balance for " << name << endl;
    cin >> starting_balance;
    
    if(!cin.good()){
        cout << "Invalid input" << endl;
        return;
    }
    
    ride.add_customer(name, starting_balance);
}
void add_drivers(My_Ride& ride){//adds a driver
    string name;
    string current_location;
    int loc;
    double lat;
    double lon;
    double starting_balance;
    
    cout << "Name of the driver: ";
    cin >> name;
    cout << endl << "Where is the driver now" << endl;
    
    for(unsigned i = 0; i < ride.place.available_places().size(); i++){
        cout << i << ") " << ride.place.available_places()[i] << endl;
    }
    cin >> loc;
    
    if((unsigned(loc) <= ride.place.available_places().size()) && (loc >= 0)){
        lat = ride.place.loc.lat(loc);
        lon = ride.place.loc.lon(loc);
    }else{
        cout << "Invalid input" << endl;
        return;
    }
    
    cout << "Starting Balance for " << name << endl;
    cin >> starting_balance;
    
    if(!cin.good()){
        cout << "Invalid input" << endl;
        return;
    }
    
    ride.add_driver(name, lat, lon, starting_balance);
}
void add_places(My_Ride& ride){//adds a place
    string location_name;
    string address;
    vector<string> tags;
    string tag;
    double lat;
    double lon;
    
    cout << "Location name: ";
    cin >> location_name;
    
    cout << endl << "Address: ";
    cin >> address;
    
    cout << endl << "Enter each tag individually. Press q to quit";
    while(tag != "q"){
        cin >> tag;
        tags.push_back(tag);
    }
    
    cout << endl << "Latitude: ";
    cin >> lat;
    
    cout << endl << "Longitude: ";
    cin >> lon;
    
    if(in_range(lat, lon)){
        ride.place.add_place(location_name, address, tags, {lat, lon});
    }else{
        cout << "Coordinates not in range" << endl;
        return;
    }
}
void add_driver_funds(My_Ride& ride){//add funds for a driver
    cout << "Which driver?" << endl;
    
    for(unsigned i = 0; i < ride.current_drivers().size(); i++){
        cout << i << ") " << ride.current_drivers()[i] << endl;
    }
    
    int index;
    cin >> index;
    
    string name;
    if(cin.good() && (unsigned(index) <= ride.current_drivers().size()) && (index >= 0)){
        name = ride.current_drivers()[index];
    }
    
    cout << "Amount to add: ";
    
    double account;
    cin >> account;
    
    if(cin.good()){
        string who = "driver";
        ride.add_fund(who, name, account);
    }else{
        cout << "Invalid input" << endl;
        return;
    }
}
void add_customer_funds(My_Ride& ride){//add funds for a customer
    string who = "customer";
    cout << "Which customer?" << endl;
    
    for(unsigned i = 0; i < ride.current_customers().size(); i++){
        cout << i << ") " << ride.current_customers()[i] << endl;
    }
    
    int index;
    cin >> index;
    
    string name;
    
    if(cin.good() & (unsigned(index) <= ride.current_customers().size()) & (index >= 0)){
        name = ride.current_customers()[index];
    }
    
    cout << "Amount to add: ";
    
    double account;
    cin >> account;
    
    if(cin.good()){
        ride.add_fund(who, name, account);
    }else{
        cout << "Invalid input" << endl;
        return;
    }
}
void ride_request(My_Ride& ride){//the main function that will request a ride_request
    int index;
    int place;
    
    cout << "Who needs a ride" << endl;
    
    for(unsigned i = 0; i < ride.current_customers().size(); i++){
        cout << i << ") " << ride.current_customers()[i] << endl;
    }
    
    cin >> index;
    
    if((unsigned(index) <= ride.current_customers().size()) && (index >= 0)){
        cout << "Where are they?" << endl;
        
        for(unsigned i = 0; i < ride.place.available_places().size(); i++){
            cout << i << ") " << ride.place.available_places()[i] << endl;
        }
        
        int start;
        cin >> start;
        
        cout << "Where do they want to go" << endl;
        
        for(unsigned i = 0; i < ride.place.available_places().size(); i++){
            cout << i << ") " << ride.place.available_places()[i] << endl;
        }
        
        cout << "-1) Search by tag" << endl;
        cin >> place;
        
        if((unsigned(place) <= ride.place.available_places().size()) && (place >= 0)){
            request_ride(ride, ride.current_customers()[index], start, ride.place.available_places()[place]);
        }else if(place == -1){
            string look_for;
            cout << "What tags do you want to search for?" << endl;
            cin >> look_for;
            string place_match = search_by_tag(ride, look_for, ride.name("customer", index));
            if(place_match == "0"){
                cout << "You can add a place with that tag" << endl;
                return;
            }else{
                request_ride(ride, ride.current_customers()[index], start,  place_match);
            }
        }else{
            cout << "Invalid input" << endl;
            return;
        }
    }else{
        cout << "Invalid input" << endl;
        return;
    }
}
istream& operator >>(istream& infile, My_Ride& ride){//overloaded operator to read from file
    int total_drivers;
    infile >> total_drivers;
    for(int i = 0; i < total_drivers; i++){
        string name;
        double balance, lat, lon;
        infile >> name >> balance >> lat >> lon;
        ride.add_driver(name, lat, lon, balance);
    }
    
    int total_customers;
    infile >> total_customers;
    for(int i =0; i < total_customers; i++){
        string name;
        double balance;
        infile >> name >> balance;
        ride.add_customer(name, balance);
    }
    
    int total_places;
    infile >> total_places;
    for(int i = 0; i < total_places; i++){
        string name, addr;
        double lat, lon;
        int total_tags;
        vector<string> tags;
        
        infile >> name >> addr >> lat >> lon >> total_tags;
        
        for(int i = 0; i < total_tags; i++){
            string tag;
            infile >> tag;
            tags.push_back(tag);
        }
        
        ride.place.add_place(name, addr, tags, {lat, lon});
    }
    
    return infile;
}
ostream& operator <<(ostream& outfile, My_Ride& ride){//overloaded operator to write to file
    int number_of_drivers = ride.current_drivers().size();
    outfile << number_of_drivers;
    outfile << ride.drivers_to_file();
    
    int number_of_customers = ride.current_customers().size();
    outfile <<  number_of_customers;
    outfile << ride.customers_to_file();
    
    int number_of_places = ride.place.available_places().size();
    outfile << number_of_places;
    outfile << ride.place.places_to_file();
    
    return outfile;
}

int main(){
    My_Ride ride;
    
    string file;
    cout << "File to read from" << endl;
    cin >> file;
    ifstream infile(file);
    infile >> ride;
    
    while(cin.good()){
        string wait_for_input;
        string selected = options();
        
        if(selected == "1"){ //this will add a customer by asking questions
            add_customers(ride);
        }else if(selected == "2"){ //this will add a driver by asking questions
            add_drivers(ride);
        }else if(selected == "3"){ //this adds a place by asking questions
            add_places(ride);
        }else if(selected == "4"){ //this adds funds to a person
            cout << "1) Driver" << endl << "2) Customer" << endl;
            string who;
            cin >> who;
            
            if(who == "1"){
                add_driver_funds(ride);
            }else if(who == "2"){
                add_customer_funds(ride);
            }else{
                cout << "Invalid input" << endl;
                break;
            }
        }else if(selected == "5"){ //this will request a ride
            ride_request(ride);
        }else if(selected == "6"){ //this will print out the customer info
            for(unsigned i = 0; i < ride.current_customers().size(); i++){
                ride.customer_info(i);
            }
        }else if(selected == "7"){ //this will print out the driver info
            for(unsigned i = 0; i < ride.current_drivers().size(); i++){
                ride.driver_info(i);
            }
        }else if(selected == "8"){
            ride.place.info_of_places();
        }else if(selected == "9"){
            ofstream outfile(file);
            outfile << ride;
            break;
        }else{
            cout << "Invalid input try again" << endl << endl;
        }
        
        cout << endl << "Press any key to continue" << endl;
        cin >> wait_for_input;
    }
}
