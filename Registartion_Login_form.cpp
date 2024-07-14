#include<iostream>
#include<fstream>
using namespace std;

class temp {
    string userName, Email, password;
    string searchName, searchPass, searchEmail;
    fstream file;
    public:
    void login();
    void signUp();
    void forget();
}obj;


int main() {

    char choice;
    cout<<"---------------------------------------\n";
    cout<<"1- Login\n";
    cout<<"2- Sign-Up\n";
    cout<<"3- Forget Password\n";
    cout<<"4- Exit\n";
    cout<<"---------------------------------------\n";
    cout<<"Enter Your Choice :: ";
    cin>>choice;

    switch(choice) {
        case '1':
            obj.login();
        break;
        case '2':
            obj.signUp();
        break;
        case '3':
            obj.forget();
        break;
        case '4':
            return 0;
        break;
        default:
            cout<<"Invalid Choice.......!";
    }
}


void temp :: signUp() {
    cin.clear();
    cin.sync();
    cout<<"Enter Your UserName :: ";
    getline(cin, userName);
    cout<<"Enter Your Email Address :: ";
    getline(cin, Email);
    cout<<"Enter Your PassWord :: ";
    getline(cin, password);

    file.open("loginData.txt", ios:: out | ios::app);
    file<<userName<<"*"<<Email<<"*"<<password<<endl;
    file.close();
}

void temp :: login() {
    cin.clear();
    cin.sync();
    cout<<"--------------LOGIN--------------"<<endl;
    cout<<"Enter Your User Name :: "<<endl;
    getline(cin, searchName);
    cout<<"Enter Your Password :: "<<endl;
    getline(cin, searchPass);

    file.open("loginData.txt", ios::in);
    getline(file, userName,'*');
    getline(file, Email,'*');
    getline(file, password,'\n');
    while(!file.eof()) {
        if(userName == searchName) {
            if(password == searchPass) {
                cout<<"\nAccount Login Succesfull....!";
                cout<<"\nUsername :: "<<userName<<endl;
                cout<<"\nEmail :: "<<Email<<endl;
            } else {
                cout<<"Password is Incorrect....!";
            }
        }
        getline(file, userName,'*');
        getline(file, Email,'*');
        getline(file, password,'\n');
    }
    file.close();
}

void temp :: forget() {
    cin.clear();
    cin.sync();
    cout<<"\nEnter Your UserName :: ";
    getline(cin, searchName);
    cout<<"\nEnter Your Email Address :: ";
    getline(cin, searchEmail);

    file.open("loginData.txt", ios::in);
    getline(file, userName, '*');
    getline(file, Email, '*');
    getline(file, password, '\n');
    while(!file.eof()) {
        if(userName == searchName) {
            if(Email == searchEmail) {
                cout<<"\nAccount Found...!"<<endl;
                cout<<"Your Password :: "<<password<<endl;
                break;
            } else {
                cout<<"Not found....!\n";
            }
        } else {
            cout<<"Not found....!\n";
        }
        getline(file, userName, '*');
        getline(file, Email, '*');
        getline(file, password, '\n');
    }
}