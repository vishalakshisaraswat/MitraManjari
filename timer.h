#include <iostream>
#include<string>
#include <windows.h>
using namespace std;

namespace cycletracker {
	
	class Timer {
	private:
    	int countdownStart;
    	int countdownEnd;
		string ans;
		
	public:
    	Timer(int start, int end) : countdownStart(start), countdownEnd(end) {}

    	void startCountdown() {
    		int f;
        	do{
			
        	for (int i = countdownStart; i >= 0; i--) {
            	system("cls");
    	        cout << " --------------------------------------" << endl;
        	    cout << " |                 " << i << "                  |" << endl;
            	cout << " | more days until your next period...|" << endl;
            	cout << " --------------------------------------" << endl;
            	Sleep(1500);
			}
			
				
    	        do {
        	        system("cls");
            	    cout << "-------------------------------------" << endl;
                	cout << " | Your period may start tomorrow... |" << endl;
                	cout << "-------------------------------------" << endl;
					cout<<"Did your period start?";
					cin>>ans;            	
				}
            	while(ans =="no");
//            	Sleep(1500);
        	
			if(ans =="yes"){
			
        	for (int i = countdownEnd; i >= 0; i--) {
            	system("cls");
            	cout << "-------------------------------------" << endl;
            	cout << "|               " << i << "                  |" << endl;
            	cout << "| more days of your period...      |" << endl;
            	cout << "-------------------------------------" << endl;

            	Sleep(1500);
        	}
        }
        cout<<"\n\tKnow more... 1";
        cout<<"\n\tExit 0";
        cin>>f;
        }
        while(f);
    	}
	};

}
