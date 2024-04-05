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
		}
		
		string calculateNextPeriodDate() {
    
        		int year, month, day;
        		sscanf(currentPeriodStart.c_str(), "%d-%d-%d", &year, &month, &day);
        
        		tm currentPeriodTm = {0};
    			currentPeriodTm.tm_year = year - 1900;
    			currentPeriodTm.tm_mon = month - 1;
        		currentPeriodTm.tm_mday = day;
        
        		sscanf(lastDate.c_str(), "%d-%d-%d", &year, &month, &day);
        
        		tm lastDateTm = {0};
    			lastDateTm.tm_year = year - 1900;
    	    		lastDateTm.tm_mon = month - 1;
        		lastDateTm.tm_mday = day;
        		
	        	time_t currentPeriodTime = mktime(&currentPeriodTm); //converting from days to seconds
	        	time_t lastDatePeriodTime = mktime(&lastDateTm);
	        
	        	cycleDuration = (currentPeriodTime - lastDatePeriodTime) / (24 * 60 * 60);

    	    		currentPeriodTime += cycleDuration * 24 * 60 * 60; //calculating the next period time

        		tm* nextPeriodTm = localtime(&currentPeriodTime);
	        	char buffer[11];
    	    		strftime(buffer, 11, "%Y-%m-%d", nextPeriodTm);
    	     
        		return (buffer);
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
	string next = m.calculateNextPeriodDate();
	m.display();
	cout<<endl<<"Expected data: "<<next;  //prints next date
}
