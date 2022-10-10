#include "GuestHousingStats.h"
#include <iostream>
using namespace std;

//overwritten menu function
int GuestHousingStats :: menuLoop(){
  char choice;//holds user menu choice
  char functionRepeat;//Holds user choice to repeat a choice in the menu
  
  do//do-while loop for the programs main menu
  {
    //menu options limited to three options for guest access
   cout << '\n' <<"1. Display Available Regions" << '\n' << 
     "2. View Regions" << '\n' << "3. Upgrade Access Level" << '\n'
     << "4. Exit" << '\n';
    cin >> choice;

    switch(choice)
    {
      case '1' :
        displayAvailableRegions();
        break;
      case '2' :
        do{
        viewRegion();
          
        cout << "Would you like to view another region?" << '\n';
        cout << "Enter Y if so" << '\n';
        cin >> functionRepeat;
        }while(functionRepeat == 'Y'|| functionRepeat == 'y');
    
        break;
      case '3' :
       upgradeUserAccess();
        if (adminUser){
         cout << "Current user is now an admin!" << '\n'; 
         //runs the base class menuloop until the end of the program 
         AdminHousingStats::menuLoop();
          return 0;
          }
      break;
      case '4' :
        cout << '\n' << "***Program Exited***" << '\n' << '\n'
          << "Have a Good Day :)!"<< '\n';
        return 0;
      
      default: cout << choice << "is not a valid menu item.\n";
    }
  }while(choice != 3 && adminUser == false );
}
void GuestHousingStats :: upgradeUserAccess(){
  string passwordInput;//user password input
  string password = "admin";//password to upgrade to admin
  char redoPassword = 'N';//holds value to rerun prompts
  
  do{
   cout << "Input password to be able to create and manipulate data" << '\n' << '\n';
   cout << "Admin Access Required Password: " << '\n';
   cin >> passwordInput;
    
    if(password == passwordInput){
     adminUser = true;
    }else{//Allows user to cotinue in the menu or to try again
     cout << "Incorrect password given. Would you like to try again?" << '\n';  
     cout << "Input (Y) if so" << '\n';
     cin >> redoPassword;
      
   if (isalpha(redoPassword)) 
   toupper(redoPassword); 
    
  }}while(redoPassword == 'Y');
}