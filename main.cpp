
#include<iostream>
#include<iomanip>
using namespace std;

#include"login.h"
using namespace login;

#include"cycle.h"
using namespace MenstrualCycle;

#include"timer.h"
using namespace cycletracker;

#include"game1.h"
using namespace game1;

int main(){
	bool exit=false;
//	enter software
	login::Login L;
	login::main();
	//authentication done!
	
	do{
		
		cout<<"\n\n\t*************"<<endl;
		cout<<"\t1.New user? \n\t\tUpdate cycle details"<<endl;
		cout<<"\t2. Tired?\n\t\tPlay game"<<endl;
		cout<<"\t3. Forgot date?\n\t\tCheck cycle status"<<endl;
		cout<<"\t4. Exit"<<endl;
		cout<<"\tEnter your choice: "<<endl;
		int option;
		cin>>option;
		switch(option){
			case 1:
				MenstrualCycle::main();
				break;
			case 2:
				game1::main();
				break;
			case 3:
				cycletracker::main();
				break;
			case 4:
				system("cls");
				exit = true;
				cout<<"\tGood Luck! :)"<<endl;
				Sleep(3000);
		}
	}
	while(!exit);
}
