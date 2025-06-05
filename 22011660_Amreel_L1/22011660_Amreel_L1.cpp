#include <string>
#include <iostream>
using namespace std;

struct Student
{
    int id;
    char phoneNum[20];
    char Name[50];
    char email[50];
};



int main() {
   Student std[5];
   
   for(int i=0;i<5;i++){
       cout<<"detail of student "<<(i+1)<<" :\n";
       
       cout<<"ID: ";
       cin>>std[i].id;
       cin.ignore();
       
       cout<<"PhoneNum: ";
       cin.getline(std[i].phoneNum,20);
       
       cout<<"Name: ";
       cin.getline(std[i].Name,50);
       
       cout<<"email: ";
       cin.getline(std[i].email,50);
       
       cout>>"Student database:\n";
       for(int i =0;i<5;i++){
        cout << "\nStudent " << (i + 1) << ":\n";
        cout << "ID: " << std[i].id << endl;
        cout << "Name: " << std[i].Name << endl;
        cout << "Phone: " << std[i].phoneNum << endl;
        cout << "Email: " << std[i].email << endl;
       }
   }
   
    return 0;
}