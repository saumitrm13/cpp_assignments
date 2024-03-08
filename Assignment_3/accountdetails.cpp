#include <iostream>
using namespace std;
class BankAccount
{
private:
    const int accno;
    string name;
    double balance;
    static int generate_accno;

public:
    BankAccount() : accno(++generate_accno) {}

    BankAccount(string name, double balance) : accno(++generate_accno)
    {
        this->name = name;
        this->balance = balance;
    }

    void acceptaccountDeatils()
    {
        cout << "Enter name - ";
        cin >> name;
        cout << "Enter initial Balance - ";
        cin >> balance;
    }

    void displayAccountDeatils()
    {
        cout << "Accno = " << accno << endl;
        cout << "Name = " << name << endl;
        cout << "Balanace = " << balance << endl;
    }
};

int BankAccount::generate_accno = 1000;
int menu(){
    int choice;

    cout<<"\nMENU"<<endl;
    cout<<"1. Create account"<<endl;
    cout<<"2. Accept account details"<<endl;
    cout<<"3. Display account details"<<endl;
    cout<<"0. Exit"<<endl; 

    cin>>choice;

    if(choice==0){
        cout<<"Program Exit"<<endl;
    }
    return choice;

}
int main()
{
    int choice;
    BankAccount *accPtr = NULL;

    while((choice = menu())!=0){
        switch(choice){
            case 1:
                accPtr = new BankAccount();
                cout<<"Bank account created"<<endl;
                break;
            case 2:
                if(accPtr == NULL){
                    cout<<"Create an acount first."<<endl;
                    break;
                }
                accPtr->acceptaccountDeatils();
                break;
            case 3:
                if(accPtr == NULL){
                    cout<<"Create an acount first."<<endl;
                    break;
                }
                accPtr->displayAccountDeatils();
                break;
            default:
                cout<<"Enter a valid choice"<<endl;
                break;

        }
    }
    delete accPtr;
    accPtr = NULL;
    return 0;
}

