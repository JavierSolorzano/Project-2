#include "AdminHousingStats.h"
using namespace std;

class GuestHousingStats : protected AdminHousingStats {
public :
//Holds whether or not the user has uprgaded to admin access
bool adminUser = false; 
//overrides menuLoop in AdminHousingStats
int menuLoop();

private:
//Allows the user to use more of the program if they have the admin password 
void upgradeUserAccess();
};
