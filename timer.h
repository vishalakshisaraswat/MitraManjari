#include <iostream>
#include <windows.h>
using namespace std;

namespace cycletracker {
	
	class Timer {
	private:
    	int countdownStart;
    	int countdownEnd;

	public:
    	Timer(int start, int end) : countdownStart(start), countdownEnd(end) {}

    	void startCountdown() {
        	start:
        	for (int i = countdownStart; i >= 0; i--) {
            	system("cls");
    	        cout << " --------------------------------------" << endl;
        	    cout << " |                 " << i << "                  |" << endl;
            	cout << " | more days until your next period...|" << endl;
            	cout << " --------------------------------------" << endl;

    	        if (i == 1) {
        	        system("cls");
            	    cout << "-------------------------------------" << endl;
                	cout << " | Your period may start tomorrow... |" << endl;
                	cout << "-------------------------------------" << endl;
                	i--;
            	}
            	Sleep(1500);
        	}

        	for (int i = countdownEnd; i >= 0; i--) {
            	system("cls");
            	cout << "-------------------------------------" << endl;
            	cout << "|               " << i << "                  |" << endl;
            	cout << "| more days of your period...      |" << endl;
            	cout << "-------------------------------------" << endl;

            	Sleep(1500);
        	}
        	goto start;
    	}
	};

}
