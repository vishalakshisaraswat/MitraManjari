#include<iomanip>
#include<iostream>
#include <ctime>
using namespace std;
namespace MenstrualCycle {
	class Cycle
	{
			protected:
		string lastDate;
    	string currentPeriodStart;
    	int cycleDuration;
		
		public:
		void readDates()
		{	
			cout << "Enter the last date of menstruation (YYYY-MM-DD): ";
    		cin >> lastDate;
    		cout << "Enter the start date of the current period (YYYY-MM-DD): ";
    		cin >> currentPeriodStart;
    		cout << "Enter the duration of the menstrual cycle (in days): ";
    		cin >> cycleDuration;
			
		}
		
		string calculateNextPeriodDate() {
        // Parse the currentPeriodStart and increment it by cycleDuration
        	int year, month, day;
        	sscanf(currentPeriodStart.c_str(), "%d-%d-%d", &year, &month, &day);
        
        	tm currentPeriodTm = {0};
    		currentPeriodTm.tm_year = year - 1900;
    	    currentPeriodTm.tm_mon = month - 1;
        	currentPeriodTm.tm_mday = day;
        
	        time_t currentPeriodTime = mktime(&currentPeriodTm); //converting from days to seconds
    	    currentPeriodTime += cycleDuration * 24 * 60 * 60;

        	tm* nextPeriodTm = localtime(&currentPeriodTime);
	        char buffer[11];
    	    strftime(buffer, 11, "%Y-%m-%d", nextPeriodTm);
    	     
        	return string(buffer);
    	}
    	
    	void display()  {
  	    	cout << "Last cycle: " << lastDate << endl;
    	    cout << "Current cycle: " << currentPeriodStart << endl;
        	cout << "Duration: " << cycleDuration << " days" ;
    	}
	
	};
}
int main()
{
	Cycle m;
	m.readDates();
	m.display();
	string next = m.calculateNextPeriodDate();
	cout<<endl<<"Expected data: "<<next;  //prints next date
}
