#include <iostream>
#include <fstream>
#include <windows.h>
#include <sstream>
using namespace std;
namespace login{

class Login{
	private:
		string LoginID, Password;
	public:
		Login():LoginID(""),Password(""){}

		void setID(string id){
			LoginID = id;
		}

		void setPW(string pw){
			Password = pw;
		}

		string getID(){
 			return LoginID;
		}

		string getPW(){
 			return Password;
		}
};

	registration(Login log){
		system("cls");
		string id, pw;
		cout<<"\tEnter Login ID: ";
		cin>>id;
		log.setID(id);

		start:
		cout<<"\tEnter A Strong Password: ";
		cin>>pw;
		if(pw.length() >= 8){
		log.setPW(pw);
		}
		else{
		cout<<"\tEnter Minimum 8 Characters!"<<endl;
		goto start;
		}
		ofstream outfile("D:/Login.txt", ios::app);
		if(!outfile){
		cout<<"\tError: File Can't Open!"<<endl;
		}
		else{
		outfile<<"\t"<<log.getID()<<" : "<<log.getPW()<<endl<<endl;
		cout<<"\tUser Registered Successfuly!"<<endl;
		}
		outfile.close();
		Sleep(3000);
		}

		login(){
		system("cls");
		string id, pw;
		cout<<"\tEnter Login ID: ";
		cin>>id;

		cout<<"\tEnter Password: ";
		cin>>pw;
		
		ifstream infile("D:/Login.txt");
		if(!infile){
		cout<<"\tError: File Can't Open!"<<endl;
		}
		else{
		string line;
		bool found = false;
		while(getline(infile,line)){
		stringstream ss;
		ss<<line;
		string userID, userPW;
		char delimiter;
		ss>>userID>>delimiter>>userPW;
		
		if(id==userID && pw==userPW){
		found = true;
		
		cout<<"\tPlease Wait";
		for(int i=0; i<3; i++){
		cout<<".";
		Sleep(800);
		}
		system("cls");
		cout<<"\tWelcome To This Page!"<<endl;
		}
		}
		if(!found){
		cout<<"\tError: Incorrect Login ID Or Password!"<<endl;
		}
		}
		infile.close();
		Sleep(5000);
		}

		int main(){
		Login log;

		bool exit = false;
		while(!exit){
		system("cls");
		int val;
		cout<<"\tWelcome To Registration & Login Form"<<endl;
		cout<<"\t************************************"<<endl;
		cout<<"\t1.Register."<<endl;
		cout<<"\t2.Login."<<endl;
		cout<<"\t3.Exit."<<endl;
		cout<<"\tEnter Choice: ";
		cin>>val;
		
		if(val==1){
		registration(log);	
		}
		
		else if(val==2){
		login();
		}

		else if(val==3){
		system("cls");
		exit = true;
		cout<<"\tGood Luck!"<<endl;
		Sleep(3000);
		}
		Sleep(3000);
		}
	}
}