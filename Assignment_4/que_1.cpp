#include<iostream>

using namespace std;

class Date{
    int day;
    int month;
    int year;

    public:
        Date():Date(1,1,2000){

        }
        Date(int d, int m, int y){
            day = d;
            month = m;
            year = y;
        }
        //getters
        int get_day(){
            return day;
        }
        int get_month(){
            return month;
        }
        int get_year(){
            return year;
        }

        //setters
        void set_day(int d){
            day = d;
        }

        void set_month(int m){
            month = m;
        }

        void set_year(int y){
            year = y;
        }

        //accept
        void acceptDate(){
            cout<<"Enter Day : \n";
            cin>>day;
            cout<<"Enter Month : \n";
            cin>>month;
            cout<<"Enter Year : \n";
            cin>>year;
            cout<<"Date updated \n";
        }

        //accept
        void displayDate(){
            cout<<"Date : "<<day<<" / "<<month<<" / "<<year<<"\n";
        }

        //is leap year
        bool isLeapYear(){
            if((year%4 == 0)||(year%4 == 0)){
                return true;
            }
            return false;
        }
};

class Person{
    string name;
    string address;
    Date birthdate;

    public:
        Person():Person(" "," "){

        }
        Person(string n,string addr){
            name = n;
            address = addr;
            //birthdate.acceptDate();
            cout<<"Person Object Created.\n";
        }
        //getters
        string get_name(){
            return name;
        }
        string get_address(){
            return address;
        }
        Date get_bday(){
            return birthdate;
        }
        //setters
        void set_name(string n){
            name = n;
        }
        
        void set_address(string addr){
            address = addr;
        }
        
        void set_bday(Date bday){
            this->birthdate = bday;
        }

        //accept
        void acceptPerson(){
            cout<<"Enter name : \n";
            cin>>name;
            cout<<"Enter Address : \n";
            cin>>address;
            birthdate.acceptDate();
        }
        //display
        void displayPerson(){
            cout<<"Name : "<<name;
            cout<<"Address : "<<address;
            birthdate.displayDate();
        }

};

class Employee : public Person
{
    int emp_id;
    float salary;
    string department;
    Date doj;

    public:
        Employee():Employee(0,0," "){}
        
        Employee(int id,float sal,string dept){
            emp_id = id;
            salary = sal;
            department = dept;
            //cout<<"For Date of Joining\n";
            //doj.acceptDate();
            cout<<"Employee created\n";
        }

        //getters
        int get_empId(){
            return emp_id;
        }
        float get_salary(){
            return salary;
        }
        string get_department(){
            return department;
        }
        Date get_doj(){
            return doj;
        }
        //setters
        void set_empId(int id){
            emp_id = id;
        }
        void set_salary(float sal){
            salary = sal;
        }
        void set_Department(string dept){
            department = dept;
        }
        void set_doj(Date date){
            doj = date;
        }

        //accept
        void acceptEmployee(){
            cout<<"Enter Employee Id : \n";
            cin>>emp_id;
            cout<<"Enter Salary : \n";
            cin>>salary;
            cout<<"Enter Department : \n";
            cin>>department;
            this->acceptPerson();
            doj.acceptDate();
        }

        //display
        void displayEmployee(){
            cout<<"\nEmployee Id : "<<emp_id;
            cout<<"\nSalary : "<<salary;
            cout<<"\nDepartment : "<<department;
            this->displayPerson();
            doj.displayDate();
        }
};
int main(){
    
    Employee e1;
    e1.acceptEmployee();
    e1.displayEmployee();
    
}