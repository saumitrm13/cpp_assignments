#include<iostream>

using namespace std;

class Time{
    int hours;
    int minutes;
    int seconds;

    public:
        //constructors
        Time() : Time(0,0,0){
        }

        Time(int hr, int min, int sec){
            hours = hr;
            minutes = min;
            seconds = sec;
            cout<<"\nTime object created\n";
        }

        //getters
        int getHour(){
            return hours;
        }

        int getMinutes(){
            return minutes;
        }

        int getSeconds(){
            return seconds;
        }

        //setters

        void setHours(int hr){
            hours = hr;
        }

        void setMinutes(int min){
            minutes = min;
        }

        void setSeconds(int sec){
            seconds = sec;
        }

        //display function
        
        void displayTime(){
            cout<<"\nTime \n "<<hours<<" : "<<minutes<<" : "<<seconds<<"\n";
        }


};

int main(){

    int size;
    int hr,min,sec;
    int choice; 
    cout<<"Enter numeber of time objects to be created.\n";
    cin>>size;

    Time **arr = new Time*[size];
    for(int i = 0; i<size; i++){
        int choice;
        cout<<"\nEnter\n1. To create an empty object.\n";
        cout<<"2. To create object with given parameters.\n";
        cin>>choice;
        if(choice == 1){
            arr[i] = new Time();
        }
        else if(choice == 2){
            cout<<"\nEnter Hours :\n";
            cin>>hr;
            cout<<"Enter Minutes :\n";
            cin>>min;
            cout<<"Enter Seconds :\n";
            cin>>sec;
            arr[i] = new Time(hr,min,sec);
        }
        else{
            arr[i] = new Time();
        }
    }

    do{
        cout<<"\nEnter the index of the object(from 1 to "<<size<<") to display it's time.\n";
        cout<<"Enter 0 to Exit.\n";
        cin>>choice;
        if(choice != 0){
            if(choice<=size){
                arr[choice-1]->displayTime();
            }
            else{
                cout<<"Enter a choice number lesser than the size of the array.\n";
            }
        }
        else{
            cout<<"Program Exit\n";
        }
    }while(choice!=0);

    for(int i=0;i<size;i++){
        delete[] arr[i];
    }
    delete[] arr;
    

    return 0;
}