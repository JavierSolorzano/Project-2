//Javier Solorzano & David Saldana
#include <string>
using namespace std;

//defines this once to prevent redefiniton when the header file is included
#pragma once

class AdminHousingStats
{
private:
int firstYear;//both used read year range
//for default program data in txt files
int lastYear;
int yearNum;//size of our dynamic arrays using year range
string fileName;//holds the name of region
const string txT = ".txt";//appends to the end of fileName variable 
//to open file for said region
float *vacancyRate;//dynamic array to hold vacancy rate
float *avgHomeValue;//dynamic array to hold average home price 
float *homeownershipRate;//dynamic array to hold homeownership rate

public:

AdminHousingStats(){//Default constructor/initialization
  firstYear = 0;
  lastYear = 0; 
  yearNum = 0;
  vacancyRate = new float(yearNum);
  avgHomeValue = new float(yearNum);
  homeownershipRate = new float(yearNum);
}
void createRegion();//user can create a region
 
void updateRegionStats();//update a region's individual stats

void displayRegionData(string nameOfFile);//displays data for specific region
void setFileName();//updates the name the text file for the region
//void deleteRegion();
int menuLoop();//main menu system of the program
void updateRegionYears();//user updates the year range for a specific region
~AdminHousingStats(){//frees memory for dynamic arrays
  delete vacancyRate;
  delete avgHomeValue;
  delete homeownershipRate;
}//destructor
protected:
void displayAvailableRegions();//displays available regions from regions.txt
void viewRegion();//prompts the user to view a specific region & data
};
