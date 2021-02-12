#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using std::fstream;
using std::ifstream;
using std::ios;
using std::ofstream;
using namespace std;
class bank
{
    char First_name[20];
    char Last_name[10];
    char acc_no[30];
    int total_amount;

public:
    void read_data();
    void show_data();
    void write_data();
    void search_data();
    void update_rec();
    void delete_data();
    void read_rec();
};
void bank::read_data()
{
    cout << "******************************************" << endl;
    cout << "******************************************" << endl;
    cout << "----Add Account Information-----" << endl;
    cout << "Enter the First Name:" << endl;
    cin >> First_name;
    cout << "Enter the Last Name:" << endl;
    cin >> Last_name;
    cout << "Enter Account no:";
    cin >> acc_no;
    cout << "Enter amount to Enter:";
    cin >> total_amount;
    cout << " Information has been Added" << endl;
    cout << "******************************************" << endl;
    cout << "******************************************" << endl;
}
void bank::read_rec()
{ //incomplete function
    string line;
    ifstream myfile("record.txt", ios::binary);
    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            if (myfile.read(reinterpret_cast<char *>(this), sizeof(*this)) > 0)
            {
                show_data();
            }
        }
        myfile.close();
    }
    else
    {
        cout << "Unable to open" << endl;
        return;
    }
}
void bank::show_data()
{
    cout << "******************************************" << endl;
    cout << "******************************************" << endl;
    cout << "------Displaying Account Information-------" << endl;
    cout << "First name:" << First_name << endl;
    cout << "Last name:" << Last_name << endl;
    cout << "Account Number:" << acc_no << endl;
    cout << "Total amount:" << total_amount << endl;
    cout << "******************************************" << endl;
    cout << "******************************************" << endl;
    cout << endl;
    cout << endl;
}
void bank::write_data()
{
    ofstream outfile;
    outfile.open("record.txt", ios::app | ios::binary);
    read_data();
    outfile.write(reinterpret_cast<char *>(this), sizeof(*this));
    outfile.close();
}
void bank::search_data()
{
    int n;
    ifstream infile;
    infile.open("record.txt", ios::binary);
    if (!infile)
    {
        cout << "\nError in opening! File Not Found!!" << endl;
        return;
    }
    infile.seekg(0, ios::end);
    int count = infile.tellg() / sizeof(*this);
    cout << "\n There are " << count << " record in the file";
    cout << "\n Enter Record Number to Search: ";
    cin >> n;
    infile.seekg((n - 1) * sizeof(*this));
    infile.read(reinterpret_cast<char *>(this), sizeof(*this));
    show_data();
}
void bank::update_rec()
{
    int n;
    fstream iofile;
    iofile.open("record.txt", ios::in | ios::binary);
    if (!iofile)
    {
        cout << "\nError in opening! File Not Found!!" << endl;
        return;
    }
    iofile.seekg(0, ios::end);
    int count = iofile.tellg() / sizeof(*this);
    cout << "\n There are " << count << " record in the file";
    cout << "\n Enter Record Number to Search: ";
    cin >> n;
    iofile.seekg((n - 1) * sizeof(*this));
    iofile.read(reinterpret_cast<char *>(this), sizeof(*this));
    cout << "Record " << n << " has following data" << endl;
    show_data();
    iofile.close();
    iofile.open("record.txt", ios::out | ios::in | ios::binary);
    iofile.seekp((n - 1) * sizeof(*this));
    cout << "\nEnter data to Modify " << endl;
    read_data();
    iofile.write(reinterpret_cast<char *>(this), sizeof(*this));
}
void bank::delete_data()
{
    int n;
    ifstream myfile;
    myfile.open("record.txt", ios::binary);
    if (!myfile)
    {
        cout << "Unable to open file" << endl;
        return;
    }
    myfile.seekg(0, ios::end);
    int count = myfile.tellg() / sizeof(*this);
    cout << "There are " << count << "No. of file" << endl;
    cout << "Enter file number to delete" << endl;
    cin >> n;
    fstream tmpfile;
    tmpfile.open("tmp.txt", ios::out | ios::binary);
    myfile.seekg(0);
    for (int i = 0; i < count; i++)
    {
        myfile.read(reinterpret_cast<char *>(this), sizeof(*this));
        if (i == (n - 1))
            continue;
        tmpfile.write(reinterpret_cast<char *>(this), sizeof(*this));
    }
    myfile.close();
    tmpfile.close();
    remove("record.txt");
    rename("tmp.txt", "record.txt");
}
