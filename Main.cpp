#include "Classes/std_lib_facilities_4.h"
#include "Classes/Customer.h"
#include "Classes/Driver.h"
#include "Classes/Place_Info.h"
#include "Classes/Geo_Loc.h"
#include "Classes/Main_Window.h"

int main(){
    while(True){
        Main_Window win(Point(100,100),600,400,"My Ride");
        return gui_main();
    }
}
