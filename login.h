#include <iostream>
#include <fstream>
#include <string>
#include "validator.h"
using namespace std;
//this function will take username and password to store in username.txt
void Register()
{
    string username, password;
    cout << "Select a username:";
    cin >> username;
    cout << "Select a password:";
    cin >> password;
    bool valid_user = validate_username(username); //to check either username is valid or not
    //for reference visit validator.h
    if (valid_user) //if username is valid store it in username.txt
    {
        ofstream file;
        file.open("username.txt");
        file << username << endl
             << password;
        file.close();
        //print message when it is done
        cout << "You are successfully registered" << endl;
        cout << "******************************************" << endl;
    }
    else
    { //print message if user register invalid username
        cout << "******************************************" << endl;
        cout << "Invalid Username type\n";
        cout << "username should be alphabets" << endl;
        cout << "******************************************" << endl;
    }
}
//this function will search existing username and password in file
//if we get exact username and password then return true
//else return false;
bool search_username(string user, string passw)
{
    string usr, pw; //usr and pw is username and password from file respectively
    ifstream read("username.txt", ios::app);
    getline(read, usr);
    getline(read, pw);
    read.close();
    if (usr == user && pw == passw)
        return true;
    else
    {
        return false;
    }
}
//this function will help existing user to get there password back
//user just need to pass there username
void forgot_password()
{
    string your_id;    //username given by user to search password
    string user_data;  //to search username from file
    string user_passw; //to seaarch password from file
    cout << "Enter your username to get password" << endl;
    cin >> your_id;
    ifstream search("username.txt", ios::app);
    getline(search, user_data);
    getline(search, user_passw);
    search.close();
    //if [your_id]-username given by user match with [user_data]username from file
    //print password to the user
    if (your_id == user_data)
        cout << "Your password:" << user_passw << endl;

    else //else print appropriate message
    {
        cout << "Cant find" << endl;
    }
}
//this function will check loggin in the system
//it will took username and password from the user
//input will be searched in file using search_username()
//if it is present in file then return true and message of successful login
//else appropriate message to get password using forgot_password()

bool isLoggedIn()
{
    string user, passw; //this user and passw will take user input to login
    cout << "Select a username:";
    cin >> user;
    cout << "Select a password:";
    cin >> passw;
    //search_username() return either input exists in file or not
    bool flag = search_username(user, passw); //store boolean value in flag
    if (flag)                                 //if present in file allow login and return true to mybank.cpp
    {
        cout << "******************************************" << endl;
        cout << "Your are successfully logged in!!" << endl;
        cout << "******************************************" << endl;
        return true;
    }
    else //given proper message
    {
        int c;
        cout << "******************************************" << endl;
        cout << "Please Enter valid Username or Password\n";
        cout << "******************************************" << endl;
        cout << "forget password?type 1 for yes and 0 for no" << endl;
        cin >> c;
        if (c == 1)
            forgot_password();
        return false;
    }
}