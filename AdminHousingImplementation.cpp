//Javier Solorzano & David Saldana
#include <iostream>
#include <array>
#include "AdminHousingStats.h"
#include <fstream>
#include <iomanip>
using namespace std;

//opens file -> reads in stats to arrays ->
//displays them to user
void AdminHousingStats::viewRegion(){
  ifstream openFile;//Accesses respective region's file
  int index;//index for the for loops

  //passes variable to function to return state name
  setFileName();
  openFile.open(fileName + txT);
 
  while(!openFile){//checks if file opened
    cout <<'\n'<< "Unable to identify state" << '\n';
    setFileName();
    openFile.open(fileName + txT);
    cout << fileName << ' ' << txT << '\n';
  }
  //opens file
  //manipulates format of values
  cout << fixed << setprecision(1) ;
  
  //reads in first to values for year ranges
  openFile >> firstYear >> lastYear ;

  yearNum = (lastYear - firstYear + 1); // Calculates size of dynamic arrays

  //reads in vacancy rate stat for each state/national
 for (index = 0; index < (yearNum); index++)
  {
    openFile >> vacancyRate[index];
  }

  //reads in average home value stat for each state/national
 for (index = 0; index < (yearNum); index++)
  {
    openFile >> avgHomeValue[index];
  }

  //reads in homeownership rate stat for each state/national
  for (index = 0; index < (yearNum); index++)
  {
    openFile >> homeownershipRate[index];
  }
  displayRegionData(fileName);//calls print to display info
  
 //closes the file
  openFile.close();
}

void AdminHousingStats::createRegion() {
ofstream regionCreation;
char repeatFunction ;

//User Prompt
cout << "What is the name of the region you wish to store data for?" << '\n'; 
cout << "Use _ instead of spaces " << '\n';  
cin >> fileName;
  
//Updates Regions.txt  
regionCreation.open("Regions.txt",std::ios_base::app); 
regionCreation << '\n'<< fileName ;
regionCreation.close();
  
 //Creates file 
regionCreation.open(fileName + txT);
//Use prompt to get year range for new region's data  
cout << "What is the earliest year your data will reference?" << '\n';
cin >> firstYear;
cout << "What is the latest year your data will reference?" << '\n';  
cin >> lastYear;
//Checks years given by user if they are a valid year range  
while(lastYear <= firstYear){
cout << "Invalid latest year given, it should be greater" << 
  "than the earliest year" 
  << '\n';
cout << "First Year: " << firstYear << '\n'; 
cout << "Enter the latest year" << '\n' ;
cin >>lastYear;  
}  
//calculates size of dynamic arrays
yearNum = (lastYear - firstYear) + 1;
  
//program recieves values from user that will be a region's data
cout << '\n' << "Input data for Vacancy rate" << '\n';
for(int i = 0; i < yearNum; i++)
{  
cout <<'\n' <<  "Year " << firstYear + i << " <-- ";
cin >> vacancyRate[i];  
}
  
cout <<'\n' << "Input data for Avg Home Value" << '\n';
for(int i = 0;i < yearNum; i++)
{  
cout << '\n' <<"Year " << firstYear + i << " <-- ";
cin >> avgHomeValue[i];  
}

cout << '\n' << "Input data for Homeownership Rate" << '\n';
for(int i = 0;i < yearNum; i++)
{  
cout << '\n' << "Year " << firstYear + i << " <-- " ;
cin >> homeownershipRate[i];  
}
//Program sends the values input by the user to the newly created file
//Sends year range value  
regionCreation << firstYear << '\n'<< lastYear << '\n';
//Sends vacancy rate  
for(int i = 0;i < yearNum; i++)
{  
regionCreation << vacancyRate[i];
regionCreation << '\n';  
}
//Sends average home value  
for(int i = 0;i < yearNum; i++)
{  
regionCreation << avgHomeValue[i];
regionCreation << '\n';
}

 //Sends homeownership rate
for(int i = 0;i < yearNum; i++)
{  
regionCreation << homeownershipRate[i];
regionCreation << '\n'; 
}
displayRegionData(fileName);// prints the data of the newely made region   
}

void AdminHousingStats::updateRegionStats(){
  int userYear; //user year of choice to update
  ofstream updateOut; //variable to open and write to file
  char userStatChoice; //Menu choice
  char selectNewYear ;
  viewRegion();
do{
  // specific update
  cout << '\n' << "Which year would you like to update?" << '\n';
  cout << "Earliest year: " << firstYear <<
    " Latest Year: " << lastYear << '\n';
  cin >> userYear;//User proof later
  while(userYear > lastYear || userYear < firstYear)
  {
  cout << "**Invalid year given, please enter a year that exists" << 
    "in the following range**" << '\n'<< '\n';    
  cout << "Earliest year: " << firstYear << '\n' <<
    "Latest Year: " << lastYear << '\n';
  cin >> userYear;  
  }
  
  //menu do-while/update
 do
 {
  cout << '\n' <<"Which statistic type would you like to update for the year "
    << userYear << "?" << '\n' << "A. Vacancy Rate" << '\n'
    << "B. Average Home Price"
    << '\n' << "C. Homeownership Rate" << '\n'
    << "D. Stats up to date" << '\n';
  cin >> userStatChoice;
   
  userStatChoice = toupper(userStatChoice);//converts user option to upper case

   //if statment checks that user year falls within avaliable year range
  if(userYear >= firstYear && userYear <= lastYear)
  {
     int index = userYear - firstYear; //subscript

    //menu option cases to read in up to date data
    //for each stat option
    switch(userStatChoice)
    {
      case 'A' :
        cout << '\n' << "Input your new vacancy " <<
          "rate(Ex:7.0): " << '\n';
        cin >> vacancyRate[index]; 
      break;
    
      case 'B' :
        cout << '\n' << "Input your new average " <<
          "home price(Ex:202733): " << '\n';
        cin >> avgHomeValue[index];
        break;
    
      case 'C' :
        cout << '\n' << "Input your new homeowne" <<
          "rship rate(Ex:63.5): " << '\n';
        cin >> homeownershipRate[index];
        break;

      case 'D' :
        break;

      default:
        cout << '\n' << "**Invalid Option Selected" <<
          " Try Again**" << '\n';
    }
  }
  displayRegionData(fileName);// prints
   
  } while(userStatChoice != 'D');
  
  cout << "Would you like to change data from a different year?" << '\n';
  cout << "Enter Y if so" << '\n';
  cin >> selectNewYear;
  
  }while(selectNewYear == 'Y'|| selectNewYear == 'y');
   // opens and clears text file
   updateOut.open(fileName + txT,ios::out | ios::trunc);

   // begins the writing to the file
 updateOut << firstYear << '\n'<< lastYear << '\n';

 
 //program sends data  to file
 for(int i = 0;i < yearNum; i++)
 {  
 updateOut << vacancyRate[i] << '\n';
 }
 
 for(int i = 0;i < yearNum; i++)
 {  
 updateOut << avgHomeValue[i] << '\n';
 }

 for(int i = 0;i < yearNum; i++)
 {  
 updateOut << homeownershipRate[i] << '\n';
 }

 displayRegionData(fileName);// prints
  updateOut.close();
   }

void AdminHousingStats::displayRegionData(string nameOfRegion){
cout << fixed << setprecision(1); //format displays value after decimal
  //format for the table of stats
cout << '\n'; 
cout << "Housing Stats for "<< nameOfRegion << '\n';  
cout << setfill('-') << setw(71) << '\n';
cout << setfill(' ') << setw(10) << "Years:" << setw(20) <<
  "Vacancy Rate:" << setw(20) << "Avg Home Price:" <<
   setw(20) << "Homeownership rate:" 
    << '\n';
cout << setfill('-') << setw(71) << '\n';

  //formats the indiviual stats to the menu from the arrays
for(int i = 0; i < yearNum; i++ )
{
cout << '|' << setfill(' ') << setw(8);
cout << firstYear + i << '|'  ;

cout << setw(19) << vacancyRate[i] << '|' ;
cout << setprecision(0); 
cout << setw(19) << avgHomeValue[i] << '|' ;
cout << setprecision(1); 
cout << setw(19) << homeownershipRate[i] << '|';
cout << '\n';
} 
cout << setfill('-') << setw(71) << '\n';
}

void AdminHousingStats::displayAvailableRegions(){// last region called again
ifstream regions;
string regionName;
  
regions.open("Regions.txt");
//need to check if file opened correctly
cout << "List of available regions:" << '\n' <<'\n'; 
//Priming the read  
regions >> regionName;
cout << regionName << '\n';
while(!regions.eof()) 
{
regions >> regionName;
cout << regionName << '\n'; 
}
 regions.close();
}

void AdminHousingStats::setFileName(){
  displayAvailableRegions();//displays regions
  
  //User prompt for specific region
  cout << '\n'<< "Enter name of region you wish to view/update:" << '\n' ;
  cin >> fileName;
}

int AdminHousingStats::menuLoop(){
  char choice;//holds user menu choice
  char functionRepeat;
  do//do-while loop for the programs main menu
  {
    //menu options displayed
   cout << '\n' <<"1. Display Available Regions" << '\n' << 
     "2. View Regions" << '\n' << "3. Create Region" << '\n'
     << "4. Update Individual Region Data" << '\n' 
        << "5. Update Region Year Range" << '\n' 
        << "6. Exit" << '\n';
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
        do{
        createRegion();
          
        cout << "Would you like to create another region?" << '\n';
        cout << "Enter Y if so" << '\n';
        cin >> functionRepeat;
        }while(functionRepeat == 'Y'|| functionRepeat == 'y');
        
        break;
      case '4' :
        do{
        updateRegionStats();
          
        cout << "Would you like to update another region's stats?" << '\n';
        cout << "Enter Y if so" << '\n';
        cin >> functionRepeat;
        }while(functionRepeat == 'Y'|| functionRepeat == 'y');
        
        break;
      case '5' : 
        do{
        updateRegionYears();
          
        cout << "Would you like to update another region's years?" << '\n';
        cout << "Enter Y if so" << '\n';
        cin >> functionRepeat;
        }while(functionRepeat == 'Y'|| functionRepeat == 'y');
        
        break; 
      case'6': 
        cout << '\n' << "***Program Exited***" << '\n' << '\n'
          << "Have a Good Day :)!"<< '\n';
        return 0;
      
      default: cout << choice << "is not a valid menu item.\n";
    }
  }while(choice != 6);
}

void AdminHousingStats::updateRegionYears(){  
ofstream regionUpdate;//holds the name of state to update
int newFirstYear; //user's first year in new range
int newLastYear; //user's second year in new range

viewRegion();//
  
cout << "What new year range would you like this data to work with?" 
  << '\n'<< '\n';
cout << "Enter the earliest year" << '\n' ;
cin >> newFirstYear;
cout <<'\n'<< "Enter the latest year" << '\n' ;
cin >> newLastYear; 
//Checks years given by user if they are a valid year range
while(newLastYear <= newFirstYear ){
cout << "**Invalid latest year given, it should be greater "
  "than the earliest year**" << '\n' << '\n';
cout << "First Year: " << newFirstYear << '\n'; 
cout << "Enter the latest year" << '\n' ;
cin >> newLastYear;  
}
  
yearNum = (newLastYear - newFirstYear) + 1;

vacancyRate = new float(yearNum);
avgHomeValue = new float(yearNum);
homeownershipRate = new float(yearNum);

cout << '\n' << "Input data for Vacancy rate" << '\n';
//program recieves data from user
for(int i = 0;i < yearNum; i++)
{  
cout <<'\n' <<  "Year " << newFirstYear + i << " <-- ";
cin >> vacancyRate[i];  
}
  
cout <<'\n' << "Input data for Avg Home Value" << '\n';
  
for(int i = 0;i < yearNum; i++)
{  
cout << '\n' <<"Year " << newFirstYear + i << " <-- ";
cin >> avgHomeValue[i];  
}

cout << '\n' << "Input data for Homeownership Rate" << '\n';
  
for(int i = 0;i < yearNum; i++)
{  
cout << '\n' << "Year " << newFirstYear+ i << " <-- " ;
cin >> homeownershipRate[i];  
}
//Copies data to file

regionUpdate.open(fileName + txT,ios::out | ios::trunc);
regionUpdate << newFirstYear << '\n'<< newLastYear << '\n';

 
//program sends data  to file
for(int i = 0;i < yearNum; i++)
{  
regionUpdate << vacancyRate[i] << '\n';
}
  
for(int i = 0;i < yearNum; i++)
{  
regionUpdate << avgHomeValue[i] << '\n';
}

for(int i = 0;i < yearNum; i++)
{  
regionUpdate << homeownershipRate[i] << '\n';
}

displayRegionData(fileName);// prints
regionUpdate.close();
}
