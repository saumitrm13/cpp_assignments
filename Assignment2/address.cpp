#include <iostream>
#include <string>
using namespace std;

class Address{
    string building;
    string street;
    string city;
    double pin;

    public:
        //constructors
        Address() : Address(" "," "," ",0){
            cout<<"Empty address created";
        }
        Address(string b,string s,string c, double p){
            building = b;
            street = s;
            city = c;
            pin = p;
            
        }
        void accept(){
            cout<<"\nEnter Building name : ";
            cin>>building;
            cout<<"\nEnter Street name : ";
            cin>>street;
            cout<<"\nEnter City name : ";
            cin>>city;
            cout<<"\nEnter Pincode : ";
            cin>>pin;
            cout<<"\nAddress Complete";
        }

        //getters
        string get_building(){
            return building;
        }
        string get_street(){
            return street;
        }
        string get_city(){
            return city;
        }
        double get_pin(){
            return pin;
        }

        //setters

        void set_building(string b){
            building = b;
        }

        void set_street(string s){
            street = s;
        }
        void set_city(string c){
            city = c;
        }
        void set_pin(double p){
            pin = p;
        }

        void display_address(){
            cout<<"\n Address : "<<building<<" , "<<street<<" , "<<city<<" , "<<pin;
        }
};

int menu(){
    int choice;

    cout<<"\nMenu";
    cout<<"\n1. Create Address";
    cout<<"\n2. Create Address with user entered values";
    cout<<"\n3. Update Details";
    cout<<"\n4. Show Details";
    cout<<"\n5. Display Entire Address";
    cout<<"\n6. Accept Address";
    cout<<"\n0. Exit\n";

    cin>>choice;

    if(choice == 0){
        cout<<"\nProgram Exit\n";
    }
    return choice;
}

int submenu_show(){
    int choice;

    cout<<"\nMenu for displaying details\n";
    cout<<"\n1. Show Building Name";
    cout<<"\n2. Show Street Name";
    cout<<"\n3. Show City Name";
    cout<<"\n4. Show Pincode";
    cout<<"\n0. Exit\n";
    
    cin>>choice;
    

    return choice;
}

int submenu_accept(){
    int choice;

    cout<<"\nMenu for accepting details\n";
    cout<<"\n1. Set Building Name";
    cout<<"\n2. Set Street Name";
    cout<<"\n3. Set City Name";
    cout<<"\n4. Set Pincode";
    cout<<"\n0. Exit\n";
    
    cin>>choice;

    return choice;
}


int main(){
    int choice;
    Address *addPtr = NULL;
    string building,street,city;
    double pin;

    while((choice = menu())!=0){
        switch(choice){
            case 1:
            {
                addPtr = new Address();
                break;
            }
            case 2:
            {
                cout<<"\nEnter Building name : ";
                cin>>building;
                cout<<"\nEnter Street name : ";
                cin>>street;
                cout<<"\nEnter City name : ";
                cin>>city;
                cout<<"\nEnter Pincode : ";
                cin>>pin;
                cout<<"\nAddress Complete";
                addPtr = new Address(building,street,city,pin);
                break;
            }
            case 3:
                if(addPtr == NULL){
                    cout<<"\nNo address created. Create an address First.";
                    break;
                }
                int choice2;
                while((choice2 = submenu_accept())!=0){

                    switch(choice2){
                        case 1:
                            cout<<"\nEnter Building Name : ";
                            cin>>building;
                            addPtr->set_building(building);
                            cout<<"\nValue Updated";
                            break;
                        case 2:
                            cout<<"\nEnter Street Name : ";
                            cin>>street;
                            addPtr->set_building(street);
                            cout<<"\nValue Updated";
                            break;
                        case 3:
                            cout<<"\nEnter City Name : ";
                            cin>>city;
                            addPtr->set_city(city);
                            cout<<"\nValue Updated";
                            break;
                        case 4:
                            cout<<"\nEnter Pin : ";
                            cin>>pin;
                            addPtr->set_pin(pin);
                            cout<<"\nValue Updated";
                            break;
                        default:
                            cout<<"\nEnter a valid choice.";
                            break;
                    }
                }
                break;
                case 4:
                    if(addPtr == NULL){
                    cout<<"\nNo address created. Create an address First.";
                    break;
                    }
                    int choice3;
                    while((choice3 = submenu_show())!=0){

                        switch(choice3){
                            case 1:
                                cout<<"\nBuilding Name : "<<addPtr->get_building();
                                break;
                            case 2:
                                cout<<"\nStreet Name : "<<addPtr->get_street();
                                break;
                            case 3:
                                cout<<"\nCity Name : "<<addPtr->get_city();
                                break;
                            case 4:
                                cout<<"\nPincode : "<<addPtr->get_pin();
                                break;
                            default:
                                cout<<"\nEnter a valid choice.";
                                break;
                        }

                    }
                case 5:
                    if(addPtr == NULL){
                    cout<<"\nNo address created. Create an address First.";
                    break;
                    }
                    addPtr->display_address();
                    break;
                case 6:
                    if(addPtr == NULL){
                    cout<<"\nNo address created. Create an address First.";
                    break;
                    }
                    addPtr->accept();
                    break;
                default:
                    cout<<"\nEnter a valid choice";
        }
    }
    delete addPtr;
    addPtr = NULL;
    return 0;
}