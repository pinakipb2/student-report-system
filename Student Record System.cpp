/****************************************
* Title: Student Record System          *
* Author: PINAKI BHATTACHARJEE          *
* IDE: Dev C++ 5.11                     *
*****************************************/

//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include<iostream>
#include<fstream>
#include <windows.h>      // For gotoxy() and Sleep function
#include <ctime>
#include<iomanip>
#include <ctype.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************

class record
{
	private :
		int roll; 	
		char name[50];
		char fname[50];
		long long contact;
	public:
		void create_record();	// function to get record from user
		void show_record() const;	// function to show record on screen
		void modify();	// function to add new record
		void report() const;	// function to show record in tabular format
		int retroll() const;	// function to return roll number
};      	   // class ends here

//****************************************************************
//    	function to create record for a student
//****************************************************************

void record::create_record()
{
	l1 : cout<<"\nEnter Roll No. : ";
	cin>>roll;
		
	record stu;		// check for same roll number
	ifstream inFile;
	inFile.open("record.dat",ios::binary);
	if(!inFile)
	{
		cout<<"\aFile could not be open !! Press any Key...";
		return;
	}
    	while(inFile.read(reinterpret_cast<char *> (&stu), sizeof(record)))
	{
		if(stu.retroll()==roll)
		{
			cout << "\a\n\n\t This Roll No. has already been used.";
				cout << "\n\n\t Please Enter an unique Roll No. \n\n";
				goto l1;
				break;
		}
	}
    inFile.close();

	cout<<"\n\nEnter The Name of The Student : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nEnter Father\'s Name : ";
	cin.getline(fname,50);
	cout<<"\nEnter Contact Number : ";
	cin>>contact;
	cout<<"\n\n\nProfile Created..";
}
	
//****************************************************************
//    	function to display selected record of a student
//****************************************************************	

void record::show_record() const
{
	cout<<"\nRoll No. : "<<roll;
	cout<<"\nStudent Name : ";
	cout<<name;
	cout<<"\nFather\'s Name : ";
	cout<<fname;
	cout<<"\nContact Number : "<<contact;
}

//****************************************************************
//    	function to modify selected record of a student
//****************************************************************

void record::modify()
{
	cout<<"\nRoll No. : "<<roll;
	cout<<"\nModify Student Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nModify Father\'s Name : ";
	cin.getline(fname,50);
	cout<<"\nModify Contact Number : ";
	cin>>contact;
}

//*****************************************************************
//		function to print all info from file ( constant )
//*****************************************************************
	
void record::report() const
{	
	cout<<"    "<<roll<<setw(7)<<" "<<name<<setw(5)<<" "<<fname<<setw(21)<<contact<<endl;
}

//******************************************************************
//	  accessor function for returning roll number ( constant )
//******************************************************************
	
int record::retroll() const
{
	return roll;
}


//***************************************************************
//    				function declaration
//****************************************************************

void write_record();	// function to write record in binary file
void display_sp(int);	// function to display student details given by user
void modify_record(int);	// function to modify record of file
void delete_record(int);	// function to delete record of file
void display_all();		// function to display all student details
void intro();	// introductory screen function

//***************************************************************
//						LOGIN SYSTEM
//***************************************************************

COORD coord = {0,0}; 
             
void gotoxy(int x, int y)         //For Setting the position of Cursor
{
	
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition( GetStdHandle (STD_OUTPUT_HANDLE), coord ); 
}

void time()
{
	//  for current time and date
	gotoxy(1,10);
		time_t now;	
	time (&now);
	cout << "\n\n\t\t Current Date & Time is: "<<ctime(&now);;         // For Displaying Date and Time	
	// Creating Object of Time

}
	
void loading()
{
	gotoxy(24,26);
	int i;
	for (i=0; i<5; i++)
	{
		cout << "\xdb\xdb\xdb\xdb\xdb";
		Sleep(100);
	}
	Sleep(500);
	cout << endl << endl;
	gotoxy(24,28);
}

void mainEntrance()
{
	gotoxy(15,2);
		cout<<"  ллл  ллл     ллл           ллл      ллллл      "<<endl; gotoxy(15,3);
		cout<<"  ллл лл        ллл         ллл       ллл  лл      "<<endl; gotoxy(15,4);
		cout<<"  ллллл          ллл       ллл        ллл   лл      "<<endl; gotoxy(15,5);
		cout<<"  ллллл           ллл     ллл         ллл лл      "<<endl; gotoxy(15,6);
		cout<<"  ллл лл           ллл   ллл          ллл   лл      "<<endl; gotoxy(15,7);
		cout<<"  ллл  лл           ллл ллл           ллл  лл      "<<endl; gotoxy(15,8);
		cout<<"  ллл   лл           ллллл            ллллл      "<<endl<<endl; gotoxy(6,9);
		cout << "     **************************************************************" << endl;
	gotoxy(6,10);
		cout << "                       DATA STRUCTURES PROJECT                     " << endl;
	gotoxy(6,11);
		cout << "     **************************************************************" << endl;
}

void login()
{
	system("cls");
	string username = "";
	string password = "";
	char ch,ch2,retry;
	int i = 0, j = 0;
	mainEntrance();
	time();	
	gotoxy(55,10);
	cout << "(LOGIN)";
	gotoxy(20,15);
	cout << "Enter Username: \n\t\t    Enter Password: ";
	
	gotoxy(36,15);
	ch2=getch();
	while(ch2 != 13){                  // gets input until 'Enter' key is pressed
	
		if(ch2 == '\b'){
			if(username.size() > 0 )  {
				username.erase(username.begin() + username.size() -1);
				cout << "\b \b";
				j--;
			}
			ch2 = getch();
		}
		else{
			if(j<10)
			{
				cout << ch2;
				username.push_back(ch2);
				ch2 = getch();
				j++;
			}
			else{
				ch2 = getch();
			}
		}
	}
	
	gotoxy(36,16);
	ch=getch();
	while(ch != 13){                  // gets input until 'Enter' key is pressed
	
		if(ch == '\b'){
			if(password.size() > 0){
				password.erase(password.begin() + password.size() -1);
				cout << "\b \b";
				i--;
			}
			ch = getch();
		}
		else{
			if(i<10)
			{
				password.push_back(ch);
				cout << "*"; 					  // For showing stars instead of actual alphabets
				ch = getch();
				i++;
			}
			else{
				ch = getch();
			}
		}
	}
	if (username == "admin" && password == "12345")
	{
		gotoxy(15,16);
		cout << "\n\n Username & Password Matched !! ";
		cout << "\n\n\t Access Granted...\n\n";
		cout << "\n\n\t\t Now Loading: ";
		loading();
		return;
	}	
	else 
	{
		system("cls");
		cout << "\n\n You entered Wrong UserName/Password ";
		cout << "\n\n\t Press 'R' or 'r' to Enter Again OR any other key to exit ...\n\n";
		cin >> retry;	
			if(retry == 'r' || retry == 'R')
			{
				system("cls");
				login();
			}
			else
			{
				exit(0);
			}
	}
}

//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM  ( BODY )
//****************************************************************

int main()
{
	system("color 0D");		// change of display color to pink
	login();
	char ch;
	int num;
	intro();
	do
	{
		system("cls");
		cout<<"\n\n\n\tMAIN MENU :-";
		cout<<"\n\n\n\t01. ENTER RECORD";
		cout<<"\n\n\t02. SEARCH RECORD";
		cout<<"\n\n\t03. ALL STUDENT\'S LIST";
		cout<<"\n\n\t04. DELETE A PROFILE";
		cout<<"\n\n\t05. MODIFY A PROFILE";
		cout<<"\n\n\t06. EXIT";
		cout<<"\n\n\n\tSelect Your Option (1-6) : ";
		cin>>ch;
		system("cls");
		switch(ch)
		{
			case '1':
				write_record();
				break;
			case '2': 
				cout<<"\n\n\tEnter Roll No. of The Student : "; cin>>num;
				display_sp(num);
				break;
			case '3':
				display_all();
				break;
			case '4':
				cout<<"\n\n\tEnter Roll No. of The Student : "; cin>>num;
				delete_record(num);
				break;
			case '5':
				cout<<"\n\n\tEnter Roll No. of The Student : "; cin>>num;
				modify_record(num);
				break;
			case '6':
		 		gotoxy(21,10);
				cout<<"THANKS FOR USING STUDENT MANAGEMENT SYSTEM";
				break;
			default :
				gotoxy(33,10);
				cout<<"\aWrong choice !!!";
		}
		cin.ignore();
		cin.get();
    } while(ch!='6');
	return 0;
}

//***************************************************************
//    	function to write in file
//****************************************************************

void write_record()
{
	record stu;
	ofstream outFile;
	outFile.open("record.dat",ios::binary|ios::app);
	stu.create_record();
	outFile.write(reinterpret_cast<char *> (&stu), sizeof(record));
	outFile.close();
}

//***************************************************************
//    	function to read specific record from file
//****************************************************************

void display_sp(int n)
{
	record stu;
	bool flag=false;
	ifstream inFile;
	inFile.open("record.dat",ios::binary);
	if(!inFile)
	{
		cout<<"\aFile could not be open !! Press any Key...";
		return;
	}
	cout<<"\nSTUDENT PROFILE : \n";
    	while(inFile.read(reinterpret_cast<char *> (&stu), sizeof(record)))
	{
		if(stu.retroll()==n)
		{
			stu.show_record();
			flag=true;
		}
	}
    inFile.close();
	if(flag==false)
		cout<<"\a\n\nRoll number does not exist.";
}

//***************************************************************
//    	function to modify record of file
//****************************************************************

void modify_record(int n)
{
	bool found=false;
	record stu;
	fstream File;
    File.open("record.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"\aFile could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&stu), sizeof(record));
		if(stu.retroll()==n)
		{
			stu.show_record();
			cout<<"\n\nEnter The New Details of account"<<endl;
			stu.modify();
			int pos=(-1)*static_cast<int>(sizeof(record));
			File.seekp(pos,ios::cur);
		    File.write(reinterpret_cast<char *> (&stu), sizeof(record));
		    cout<<"\n\n\t Record Updated Successfully...";
		    found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\a\n\n Record Not Found ";
}

//***************************************************************
//    	function to delete record of file
//****************************************************************

void delete_record(int n)
{
	char confirm='n';
	record stu;
	ifstream inFile;
	ofstream outFile;
	inFile.open("record.dat",ios::binary);
	if(!inFile)
	{
		cout<<"\aFile could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\tAre you sure, you want to delete this record ? (y/n)..";
	cin>>confirm;
			if(confirm=='n')
			{
				cout<<"\n\n\tRecord not deleted !!";
			}
			else {
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&stu), sizeof(record)))
	{
		if(stu.retroll()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&stu), sizeof(record));
		}
	}
    inFile.close();
	outFile.close();
	remove("record.dat");
	rename("Temp.dat","record.dat");
	cout<<"\n\n\tThe record has been successfully deleted if it exsisted...";
			 	}
}

//****************************************************************
//    	function to display all student's details list
//****************************************************************

void display_all()
{
	record stu;
	ifstream inFile;
	inFile.open("record.dat",ios::binary);
	if(!inFile)
	{
		cout<<"\aFile could not be open !! Press any Key...";
		return;
	}
	gotoxy(33,2);
	cout<<"STUDENT LIST\n\n";
	cout<<" ==============================================================================\n";
	cout<<"  ROLL NO.      NAME                  FATHER\'S NAME                 CONTACT NO.\n";
	cout<<" ==============================================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&stu), sizeof(record)))
	{
		stu.report();
	}

	inFile.close();
}


//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************

void intro()
{
	system("cls");
	gotoxy(33,5);
	cout<<"WELCOME TO";
	gotoxy(26,8);
	cout<<"STUDENT MANAGEMENT SYSTEM";
	gotoxy(23,15);
	cout<<"MADE BY : PINAKI BHATTACHARJEE";
	gotoxy(20,17);
	cout<<"SCHOOL : KENDRIYA VIDYALAYA, BURDWAN";
	cin.get();
}

//***************************************************************
//    			END OF PROJECT
//***************************************************************
