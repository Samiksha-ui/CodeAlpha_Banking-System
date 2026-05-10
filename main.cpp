#include <iostream>
#include <vector>
using namespace std;

class Account {
private:
    string name;
    int accountNumber;
    double balance;

public:
    Account(string n, int acc, double bal){
        name=n;
        accountNumber=acc;
        balance=bal;
    }

    void deposit(double amount){
        balance+=amount;
        cout<<"Amount Deposited Successfully\n";
    }

    void withdraw(double amount){
        if(amount<=balance){
            balance-=amount;
            cout<<"Withdrawal Successful\n";
        }else{
            cout<<"Insufficient Balance\n";
        }
    }

    void display(){
        cout<<"\nAccount Holder: "<<name<<endl;
        cout<<"Account Number: "<<accountNumber<<endl;
        cout<<"Balance: "<<balance<<endl;
    }

    int getAccNo(){
        return accountNumber;
    }
};

int main(){

    vector<Account> accounts;

    int choice;

    do{
        cout<<"\n--- BANKING SYSTEM ---\n";
        cout<<"1. Create Account\n";
        cout<<"2. Deposit\n";
        cout<<"3. Withdraw\n";
        cout<<"4. Display Account\n";
        cout<<"5. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        if(choice==1){
            string name;
            int acc;
            double bal;

            cout<<"Enter Name: ";
            cin>>name;
            cout<<"Account Number: ";
            cin>>acc;
            cout<<"Initial Balance: ";
            cin>>bal;

            accounts.push_back(Account(name,acc,bal));
            cout<<"Account Created Successfully\n";
        }

        else if(choice==2){
            int acc;
            double amt;
            cout<<"Enter Account Number: ";
            cin>>acc;

            for(auto &a:accounts){
                if(a.getAccNo()==acc){
                    cout<<"Enter Amount: ";
                    cin>>amt;
                    a.deposit(amt);
                }
            }
        }

        else if(choice==3){
            int acc;
            double amt;
            cout<<"Enter Account Number: ";
            cin>>acc;

            for(auto &a:accounts){
                if(a.getAccNo()==acc){
                    cout<<"Enter Amount: ";
                    cin>>amt;
                    a.withdraw(amt);
                }
            }
        }

        else if(choice==4){
            int acc;
            cout<<"Enter Account Number: ";
            cin>>acc;

            for(auto &a:accounts){
                if(a.getAccNo()==acc){
                    a.display();
                }
            }
        }

    }while(choice!=5);

    cout<<"Thank You!\n";
    return 0;
}