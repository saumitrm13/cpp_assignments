#include<iostream>

using namespace std;

class Box{
    public:
        double length;
        double width;
        double height;

    public:

        Box(double l,double w, double h){
            length = l;
            width = w;
            height = h;
        }

        void calculateVolume(){
            cout<<"Volume of the box : "<<length * height * width<<" meters cube \n";
        }

        void displayVolume(){
            cout<<"Length : "<<length<<endl;
            cout<<" Width : "<<width<<endl;
            cout<<"Height : "<<height<<endl;
        }

        void updateParameters(double l,double w, double h){
            length = l;
            width = w;
            height = h;
        }
};

int menu(){
    int choice;

    cout<<"\nEnter Your Choice"<<endl;
    cout<<"1. Enter Parameters\n";
    cout<<"2. Display Volume\n";
    cout<<"3. Calculate Volume\n";
    cout<<"0. Exit\n";

    cin>>choice;

    if(choice==0){
        cout<<"Program Exit\n";
    }
    
    return choice;
}

int main(){
    int choice;
    double l,w,h;
    cout<<"Enter Length : \n";
    cin>>l;
    cout<<"Enter Width : \n";
    cin>>w;
    cout<<"Enter Height : \n";
    cin>>h;
    Box box(l,w,h);
    while((choice = menu())!=0){
        switch(choice){
            case 1:
                double l,w,h;
                cout<<"Enter Length : \n";
                cin>>l;
                cout<<"Enter Width : \n";
                cin>>w;
                cout<<"Enter Height : \n";
                cin>>h;

                box.updateParameters(l,w,h);
                break;
            case 2:
                box.displayVolume();
                break;
            case 3:
                box.calculateVolume();
                break;
            default:
                cout<<"Invalid choice. Enter a choice from 0 to 3\n";
        }

    }
    return 0;
}