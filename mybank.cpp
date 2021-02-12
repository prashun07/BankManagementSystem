#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "bankbackend.h"
#include "login.h"
using std::fstream;
using std::ifstream;
using std::ios;
using std::ofstream;
using namespace std;
/*
This is main window of bank management system.Currently this window contain bank
side management only. Suppose you are bank employee of this ABC bank.
first you have to login into system with proper username and password.
if you are a new employee first register yourself,then login to the system.
after login you will get six options to choose.
option 1: Add record of new bank client
Record contains following info:
first name,last name,account number,amount
option 2:show all record from file
option 3:search particular record by record number
option 4:update record
option 5: delete record
option 6: exit from system
 "bankbackend.h" is user defined header which contains proper
 code of how 6 option from above will work.

 "validator.h" is user defined header which contains code to validate username
 "login.h" is user defined header which contains code to login system
*/
void bank_ui(int choice) //function to provide bank interface to employee after he/she loggin
{
    bank A; //object of class bank visit bankbackend.h
    while (true)
    {
        cout << "Select one option below ";
        cout << "\n\t1-->Add record to file";
        cout << "\n\t2-->Show record from file";
        cout << "\n\t3-->Search Record from file";
        cout << "\n\t4-->Update Record";
        cout << "\n\t5-->Delete Record";
        cout << "\n\t6-->Quit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            A.write_data();
            break;
        case 2:
            A.read_rec();
            break;
        case 3:
            A.search_data();
            break;
        case 4:
            A.update_rec();
            break;
        case 5:
            A.delete_data();
            break;
        case 6:
            cout << "Quiting.......!" << endl;
            exit(0);
            break;
        default:
            cout << "Enter Correct choice" << endl;
            exit(0);
        }
    }
}

int main()
{
    int option;
    bool result;
    cout << "******************************************" << endl;
    cout << "WELCOME TO ABC BANK\n";
    cout << "1:Register(if you are new in job)\n";
    cout << "2 : login\n3 : Exit\n";
    cout << "******************************************" << endl;
    cout << "Yourchoice :";
    cin >> option;
    if (option == 1)
    {
        Register();
        main();
    }
    else if (option == 2)
    {
        result = isLoggedIn();
    }
    else
    {
        system("Exit");
    }
    if (result)
    {
        int choice;
        bank_ui(choice);
    }
    system("pause");
    return 0;
}