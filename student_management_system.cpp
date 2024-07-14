#include<iostream>
#include<fstream>
using namespace std;

class temp {
    string rollNum, name, fatherName, address, search;
    fstream file;
    public:
    void addStud();
    void viewStud();
    void searchStud();
}obj;


int main() {

    char choice;
    cout<<"---------------------------------------\n";
    cout<<"1- Add Student Record\n";
    cout<<"2- View All Student Record\n";
    cout<<"3- Search Student Record\n";
    cout<<"4- Exit\n";
    cout<<"---------------------------------------\n";
    cin>>choice;

    switch(choice) {
        case '1':
            obj.addStud();
        break;
        case '2':
            obj.viewStud();
        break;
        case '3':
            obj.searchStud();
        break;
        case '4':
            return 0;
        break;
        default:
            cout<<"Invalid Choice.......!";
    }
}


void temp :: addStud() {

    cin.clear();
    cin.sync();
    cout<<"Enter Student Roll Number :: ";
    getline(cin, rollNum);
    cout<<"Enter Student Name :: ";
    getline(cin, name);
    cout<<"Enter Student Father Name :: ";
    getline(cin, fatherName);
    cout<<"Enter Student Address :: ";
    getline(cin, address);

    file.open("stuData.txt", ios::out | ios::app);
    file<<rollNum<<"*";
    file<<name<<"*";
    file<<fatherName<<"*";
    file<<address<<endl;
    file.close();
}

void temp :: viewStud() {

    file.open("stuData.txt", ios::in);
    getline(file, rollNum, '*');
    getline(file, name, '*');
    getline(file, fatherName, '*');
    getline(file, address, '\n');

    while(!file.eof()) {
        cout<<"\n";
        cout<<"Student Roll Number :: "<<rollNum<<endl;
        cout<<"Student Name :: "<<name<<endl;
        cout<<"Student Father Name :: "<<fatherName<<endl;
        cout<<"Student Address :: "<<address<<endl;
        
        getline(file, rollNum, '*');
        getline(file, name, '*');
        getline(file, fatherName, '*');
        getline(file, address, '\n');
    }
    file.close();
}

void temp :: searchStud() {
    cin.clear();
    cin.sync();
    cout<<"Enter Student Roll Number :: ";
    getline(cin, search);

    file.open("stuData.txt", ios::in);
    getline(file, rollNum, '*');
    getline(file, name, '*');
    getline(file, fatherName, '*');
    getline(file, address, '\n');
    while(!file.eof()) {
        if(rollNum == search) {
            cout<<endl;
            cout<<"Student Roll Number :: "<<rollNum<<endl;
            cout<<"Student Name :: "<<name<<endl;
            cout<<"Student Father Name :: "<<fatherName<<endl;
            cout<<"Student Address :: "<<address<<endl;
        }

        getline(file, rollNum, '*');
        getline(file, name, '*');
        getline(file, fatherName, '*');
        getline(file, address, '\n');
    }
    file.close();
}







