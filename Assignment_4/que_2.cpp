#include<iostream>
using namespace std;

class Student{
    int roll_no;
    float marks[3];
    string gender;
    string name;
    float total_marks;

    public:
        Student() : Student(" "," ",0){}

        Student(string n, string g, int roll){
            name = n;
            gender = g;
            roll_no = roll;
            
        }
        //accept

        void acceptDetails(){
            cout<<"Enter name : \n";
            cin>>name;
            cout<<"Enter gender : \n";
            cin>>gender;
            cout<<"Enter roll number : \n";
            cin>>roll_no;

            for(int i = 0; i<3; i++){
                cout<<"Enter marks of subject "<<i+1<<" : \n";
                cin>>marks[i];
                total_marks += marks[i];
            }
            total_marks /= 3;
        }

        //display
        void displayDetails(){
            cout<<"Name : "<<name<<"\n";
            cout<<"Gender : "<<gender<<"\n";
            cout<<"roll number : "<<roll_no<<"\n";
            cout<<"Percentage : "<<total_marks<<"\n";
        }
        //marks getter
        float get_totalMarks(){
            return total_marks;
        }
        int get_roll(){
            return roll_no;
        }
};

//sort function

//menu function
int menu(){
    int choice;

    cout<<"\n Menu \n";
    cout<<"0. Exit\n";
    cout<<"1. Display Details of all students\n";
    cout<<"2. Accept Details of all students\n";
    cout<<"3. Sort the marks according to percentage\n";
    cout<<"4. Search a student from roll number.\n";

    cin>>choice;

    if(choice == 0){
        cout<<"Program Exit\n";
    }

    return choice;
}
int main(){
    int size=2,choice;
//    cout<<"Enter number of students.\n";

    Student stud_arr[2];
    float marks[size];

    for(int i = 0;i<size;i++){
        stud_arr[i].acceptDetails();
        marks[i] = stud_arr[i].get_totalMarks();
    }

    while((choice = menu())!=0){
        switch(choice){
            case 1:
                for(int i = 0;i<size;i++){
                    stud_arr[i].displayDetails();
                }
                break;
            case 2:
                for(int i = 0;i<size;i++){
                    stud_arr[i].acceptDetails();
                }
                break;
            case 3:{
                for(int i = 0;i<size;i++){

                    for(int j = 0;j<size-i;j++){
                        if(stud_arr[j].get_roll() > stud_arr[j+1].get_roll()){
                            Student temp = stud_arr[j+1];
                            stud_arr[j+1] = stud_arr[j];
                            stud_arr[j] = temp;

                        }
                    }
                }
            

                cout<<"Sorted marks : \n";
                for(int i = 0; i<size; i++){
                    stud_arr[i].displayDetails();
                }
                break;
            }
            case 4:{
                int roll;
                cout<<"Enter roll numeber : \n";
                cin>>roll;
                for(int i = 0;i<size;i++){
                    if(roll == stud_arr[i].get_roll()){
                        stud_arr[i].displayDetails();
                        break;
                    }
                }
                break;
            }
            default:
                cout<<"Invalid choice.\n";
                break;
        };
    }
    return 0;

}
