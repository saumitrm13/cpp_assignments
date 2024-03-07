
#include <iostream>
#include <string>

using namespace std;
class Student{
private:
    int rollNo;
    int marks;
    string name;
    
public:
    void initStudent(){
        rollNo = 0;
        name = " ";
        marks = 0;
    }
    
    void acceptStudentFromConsole(){
        cout<<"\nEnter Student Name : "<<endl;
        cin>>name;
        cout<<"Enter Roll Number : "<<endl;
        cin>>rollNo;
        cout<<"Enter Marks : "<<endl;
        cin>>marks;
    }
    
    void printStudentOnConsole(){
        cout<<"\n       Name  : "<<name<<endl;
        cout<<"Roll Numeber : "<<rollNo<<endl;
        cout<<"     Marks   : "<<marks<<endl;
    }
};

int menu(){
    int choice;
    
    cout << "\nMenu"<<endl;
    cout << "1. Initialize Student"<<endl;
    cout << "2. Print Student Details"<<endl;
    cout << "3. Accept Student Details"<<endl;
    cout << "0. Exit"<<endl;
    cout << "Enter your choice: ";
    cin >> choice;
    if(choice == 0){
        cout<<"Program Exit";
    }
    return choice;
}
int main() {
    int choice;
    Student student;
    
    while((choice = menu()) != 0){
        switch(choice){
            case 1:
                student.initStudent();
                cout<<"\nStudent initialized."<<endl;
                break;
            case 2:
                student.printStudentOnConsole();
                break;
            case 3:
                student.acceptStudentFromConsole();
                break;
            
            default:
                cout<<"Invalid Choice. Enter a choice from 0 to 3.";
        }
    }
    return 0;
}

