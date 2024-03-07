#include<iostream>
using namespace std;

class Toolbooth{
    public:
        int paidCars;
        int nonPaidCars;
        double total_cash;
    
    public:

        Toolbooth(){
            paidCars = 0;
            nonPaidCars = 0;
            total_cash = 0;
            cout<<"Toolbooth initialized"<<endl;
        }

        void payingCar(){
            paidCars += 1;
            total_cash += 0.5;
            cout<<"Car number and money amount updated\n";
        }

        void noPayCar(){
            nonPaidCars += 1;
            cout<<"Car number updated\n";
        }

        void printOnConsole(){
            cout<<"    Total Cars         : "<<paidCars+nonPaidCars<<endl;
            cout<<"    Paid Cars          : "<<paidCars<<endl;
            cout<<"    Unpaid Cars        : "<<nonPaidCars<<endl;
            cout<<"Total amount collected : "<<total_cash<<endl;
        }
};

int menu(){
    int choice;
    cout<<"\n    Menu\n";
    cout<<"1. Add paying car\n";
    cout<<"2. Add unpaid car\n";
    cout<<"3. Display total\n";
    cout<<"0. Exit\n";

    cin>>choice;

    if(choice == 0){
        cout<<"Program Exit\n";
    }
    return choice;
}

int main(){
    Toolbooth toolbooth;
    int choice;

    while((choice = menu()) != 0){
        switch(choice){
            case 1:
                toolbooth.payingCar();
                break;
            case 2:
                toolbooth.noPayCar();
                break;
            case 3:
                toolbooth.printOnConsole();
                break;
            default:
                cout<<"Invalid choice. Enter a choice from 0 to 3\n";
                break;
        }
    }
    return 0;
}