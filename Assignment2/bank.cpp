#include <iostream>
using namespace std;

class BankAccount
{
private:
    const int accno;
    string name;
    double balance;

public:
    BankAccount(int accno, string name, double balance) : accno(accno)
    {
        this->name = name;
        this->balance = balance;
    }

    double getBalance() const
    {
        return balance;
    }

    // can i make the deposit function const? - NO
    void deposit()
    {   
        int amount;
        cout<<"Enter amount to be deposited."<<endl;
        cin>>amount;
        balance += amount;
        cout<<"Amount added"<<endl;
    }

    // can i make the deposit function const? - NO
    void withdraw()
    {
        int amount;
        cout<<"Enter amount to be withdrawn"<<endl;
        cin>>amount;
        if(amount>balance){
            cout<<"Not enough balance"<<endl;
        }
        else{
            balance -= amount;
            cout<<"Amount withdrawn"<<endl;
        }
    }

    void displayAccountDetails() const
    {
        cout << "Accno - " << accno << endl;
        cout << "Name - " << name << endl;
        cout << "Balance - " << balance << endl;
    }
};

int menu(){
    int choice;

    cout<<"\nMENU"<<endl;
    cout<<"1. Create Account"<<endl;
    cout<<"2. Display details"<<endl;
    cout<<"3. Deposit"<<endl;
    cout<<"4. Withdraw"<<endl;
    cout<<"5. Show balance"<<endl;
    cout<<"0. EXIT"<<endl;

    cin>>choice;

    if(choice == 0){
        cout<<"Program Exit"<<endl;
    }
    return choice;
}

int main()
{
    BankAccount *bankPtr = NULL;
    int choice;
    string name;
    int accno;
    double balance;

    while((choice = menu())!=0){
        switch(choice){
            case 1:
                cout<<"Enter account number :"<<endl;
                cin>>accno;
                cout<<"Enter Name :"<<endl;
                cin>>name;
                cout<<"Enter Balance : "<<endl;
                cin>>balance;

                bankPtr = new BankAccount(accno,name,balance);
                cout<<"Account Created"<<endl;
            case 2:
                if(bankPtr == NULL){
                    cout<<"Create an account first."<<endl;
                    break;
                }
                bankPtr->displayAccountDetails();
                break;
            case 3:
                if(bankPtr == NULL){
                    cout<<"Create an account first."<<endl;
                    break;
                }
                bankPtr->deposit();
                break;
            case 4:
                if(bankPtr == NULL){
                    cout<<"Create an account first."<<endl;
                    break;
                }
                bankPtr->withdraw();
                break;
            case 5:
                if(bankPtr == NULL){
                    cout<<"Create an account first."<<endl;
                    break;
                }
                cout<<"Balance : "<<bankPtr->getBalance()<<endl;
                break;
            default:
                cout<<"Enter a valid choice"<<endl;
                break;
        }
    }
    delete bankPtr;
    bankPtr = NULL;
    return 0;
}