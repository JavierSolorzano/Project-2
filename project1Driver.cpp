//David Saldana & Javier Solorzano
/*This program acts as a database for U.S. housing statistics such as Rental Vacancy 
Rate, the Homeowenrship Rate and the Average Home Price. On top of being able to 
view data of a region, the user will also be able to create and update their 
own files that will contain relevant statistics. The program comes supplied
with a few data for California and the National Averages of the U.S.*/

#include "AdminHousingStats.h"
#include "GuestHousingStats.h"
#include <iostream>

int main() {

  AdminHousingStats adminHousingProgram;
  GuestHousingStats guestHousingProgram;
  
  guestHousingProgram.menuLoop();

  return 0;
}
