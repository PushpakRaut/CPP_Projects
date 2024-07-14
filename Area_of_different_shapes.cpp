#include<iostream>
#include<cmath>
using namespace std;

int main() {
    char choice;
    int radius, length, width, area;
    cout<<"---------------------------------------\n";
    cout<<"1- Area of Circle \n";
    cout<<"2- Area of Rectacngle\n";
    cout<<"3- Area of Square\n";
    cout<<"4- Exit\n";
    cout<<"---------------------------------------\n";
    cout<<"Enter Your Choice :: ";
    cin>>choice;

    switch(choice) {
        case '1':
            cout<<"Enter the radius of circle :: ";
            cin>>radius;
            area = 3.14 * pow(radius, 2);
        break;
        case '2':
            cout<<"Enter the Length of the Rectangle :: ";
            cin>>length;
            cout<<"Enter the Width of the Rectangle :: ";
            cin>>width;
            area = length * width;
        break;
        case '3':
            cout<<"Enter the Length of side of the Square :: ";
            cin>>length;
            area = pow(length, 2);
        break;
        case '4':
            return 0;
        break;
        default:
            cout<<"Invalid Choice.......!";
    }
    cout<<"\nArea :: "<<area<<endl;
}