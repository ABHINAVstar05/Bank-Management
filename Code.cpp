#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std ;
class Bank {
        int acct_no ;
        float curr_balance = 5000 ;
        void Deposit();
        void Withdrawal();
    public :
        string name ;
        void registration();
        void login();
        void transaction();
        void view_details();
};
// for REGISTRATION....
void Bank::registration(){
    cout<<"\n\n";
    string id, password ;
    cout<<setw(15)<<"Thanks for connecting with us...!!!\n\n\n" ;
    cout<<"Please fill the below boxes for the registration process.\n\n";
    cout<<"NOTE : "<<setw(5)<<"(1) Your username can have uppercase/lowercase alphabets, special characters and numbers.\n"
                    <<setw(5)<<"(2) Your username should not have any space.\n"
                    <<setw(5)<<"(3) Your password can have uppercase/lowercase alphabets, special characters and numbers.\n"
                    <<setw(5)<<"(4) Minimum required account balance to start your account is Rs.1000.\n\n";
    cin.ignore() ;
    cout<<"Enter your name : ";
    getline(cin,name);
    
    cout<<"\nEnter your username : ";
    cin>>id ;
    cout<<"Enter account password : ";
    cin>>password;
    cout<<"\nRegistration successfull.\n";
    srand(time(0));
    acct_no = 1 + (rand()%1000) ;     //Can generate upto 1000 different account numbers.
    cout<<"Your assigned account number for all your future reference (including transaction details) will be : "<<acct_no;
    cout<<"\n\n\n";
}
// for LOGIN.....
void Bank::login(){
    cout<<"\n\n";
    string id, password ;
    cout<<setw(15)<<"Welcome to Login page.\n\nPlease enter your login credentials below.\n\n\n" ;
    cout<<"Enter your username : ";
    cin>>id;
    cout<<"Enter account password : ";
    cin>>password ;
    cout<<"\n\nLogin successful." ;
    cout<<"\n\n\n";
}
//for DEPOSIT.......
void Bank::Deposit(){
    cout<<"\nYour current account balance : Rs."<<curr_balance<<"\n" ;
    float dep;
    cout<<"\nEnter deposit amount : Rs.";
    cin>>dep;
    curr_balance += dep ;
    cout<<"Available balance : Rs."<<curr_balance<<"\n\n";
}
//for WITHDRAWAL........
void Bank::Withdrawal(){
    cout<<"\nYour current account balance : Rs."<<curr_balance<<"\n" ;
    float withD;
    cout<<"\nEnter withdrawal amount : Rs.";
    cin>>withD;
    if (withD>curr_balance){
        cout<<"Insufficient amount\n\n";
    }
    else{
        curr_balance -= withD ;
        cout<<"Available balance : Rs."<<curr_balance<<"\n\n";
    }
}

//for TRANSACTION.... (executes deposit() or withdrawal() on the basis of option chosen.)
void Bank::transaction(){
    int f ;
    cout<<"Please select one of the available options.\n\n"
        <<"--> Press 1 for depositing money in your account.\n"
        <<"--> Press 2 for withdrawing money from your account.\n\n";
    cout<<"Enter your choice : ";
    cin>>f ;
    switch(f){
        case 1 : Bank::Deposit() ;
        break ;
        case 2 : Bank::Withdrawal() ;
    }
}
//for VIEW DETAILS.......
void Bank::view_details(){
    int a_num ;
    cout<<"Enter your account number : ";
    cin>>a_num;      //ye account no. ko database se match krke aage ka function run krna h.....
    cout<<"\n";
    cout<<"Name : "<<name ;
    cout<<"\nAvailable balance in your account : Rs."<<curr_balance<<"\n\n\n";
}
//DRIVER FUNCTION begins....

int main(){
    Bank obj1 ;
    // LOGIN REGISTRATION calling.....
    int func1 ;
    cout<<setw(15)<<"Welcome to (NAME) BANK !!!\n\n\n" ;
    cout<<"Please select an option to continue.\n\n"
        <<"Enter 1 for new user registration.\n"
        <<"Enter 2 for login account.\n\n";
    cout<<"Select option : ";
    cin>>func1 ;
    switch(func1){
        case 1 : obj1.registration() ;
        break ;
        case 2 : obj1.login() ;
        break ;
    }
    //if login details matches then the code will move ahead otherwise it will show invalid input.
    //after registration the code will move ahead as it is....

    //TRANSACTION and VIEW DETAILS calling......
    int func2 ;
    int n = 0 ;
    do{
        cout<<"Please select one of the below options to continue.\n\n" ;
        cout<<"Enter 1 for performing money transaction.\n"
            <<"Enter 2 for viewing your account details.\n"
            <<"Enter 3 to exit.\n\n";
        cout<<"Enter your choice here : ";
        cin>>func2 ;
        cout<<"\n\n";
        switch(func2){
            case 1 : obj1.transaction() ;
            break ;
            case 2 : obj1.view_details() ;
            break ;
            case 3 : exit(0) ;
        }
        n++ ;
    } 
    while (n!=5) ;
}
