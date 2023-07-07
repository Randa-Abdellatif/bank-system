#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include<vector>
#include"person.h"
#include"Validation.h"

using namespace std;

class Client:public person
{
    static int Client_num;
    public:

    void setBalance(double balance)
    {
        this->balance= Validation::setBalance(balance);

    }
    double getBalance()
    {
        return balance;
    }
    void deposit(double amount)
    {
        balance+=amount;
    }
    void withdraw(double amount)
    {
        if(amount<=balance){
        balance-=amount;
        }
        else{cout<<"amount exceed";}
    }
    void transferTo(double amount,Client &recipient)
    {
        if(amount<=balance){
        recipient.balance+=amount;
        balance-=amount;}
        else{cout<<"amount exceed";}
    }
    void checkBalance ()
    {
        cout<<"balance: "<<balance<<endl;
    }
    void display()
    {
        person::display();
        cout<<"balance: "<<balance<<endl;
    }

    Client() {
        /*number=FilesHelper::getLast("client id.txt");
        number++;
        id=number;*/
       Client_num++;
       id = Client_num;
    }
    virtual ~Client() {}

protected:

    private:
        double balance;
        //int number;
};
static vector<Client> clients;

#endif // CLIENT_H
