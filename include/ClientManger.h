#ifndef CLIENTMANGER_H
#define CLIENTMANGER_H
#include <iostream>
#include"Client.h"
#include"Employee.h"
#include"person.h"
using namespace std;


class ClientManger
{
    public:
        static void printClientMenu()
        {
            system("cls");
            cout<<"\t\t\t\t\t\tClient Functions\n";
            cout<<"1-Deposit"<<endl;
            cout<<"2-Withdraw"<<endl;
            cout<<"3-transfer To"<<endl;
            cout<<"4-Check Balance"<<endl;
            cout<<"5-Display"<<endl;
            cout<<"6-Update Password"<<endl;
            cout<<"7-logout"<<endl;

        }

        static bool clientOptions(Client* client)
        {
            int x=0;
            cout<<"enter your choice: ";
            cin>>x;
            switch(x)
            {
            case 1:
                {
                    system("cls");
                    double amount =1500;
                    cout<<"enter amount to deposit : ";
                    cin>>amount;
                    client->deposit(amount);
                    client->checkBalance();
                    system("pause");
                    break;
                }
            case 2:
                {
                    system("cls");
                    double amount =1500;
                    cout<<"enter amount to withdraw : ";
                    cin>>amount;
                    client->withdraw(amount);
                    client->checkBalance();
                    break;
                }
            case 3:
                {
                system("cls");
                double amount;
                Client *otherClient;
                Employee e;
                int id;
                cout<<"enter client id you want to transfer to : ";
                cin>>id;
                 cout<<"enter the amount to transfer: "<<endl;
        cin>>amount;
                    otherClient =e.searchClient(id);
                    if(otherClient == NULL)
        {
            cout<<"Incorrect Id"<<endl;
            return NULL;
        }

                client->transferTo(amount,*otherClient);
                client->checkBalance();
                break;
                }
            case 4:
                {
                    system("cls");
                    client->checkBalance();
                    system("pause");
                    break;
                }
            case 5:
                {
                    system("cls");
                    client->display();
                    system("pause");
                    break;
                }
            case 6:
                {
                    system("cls");
                    updatePassword(client);
                    break;
                }
            case 7:
                {
                    return true;
                }
            default:
                {
                    cout<<"your choice not found in list\n";
                    clientOptions(client);
                }
            }
            Back(client);

        }

        static void Back(Client* client)
{
    printClientMenu();
    clientOptions(client);
}

    static void updatePassword(person* person)
    {
        string password;
        cout<<"enter your password: ";
        cin>>password;
        person->setPassword(password);
        cout<<"password updated"<<endl;
        FileManager f;
    }

    static Client* login(int id, string password)
    {
        Employee e;
        Client *clientptr=e.searchClient(id);
        if(clientptr == NULL)
        {
            cout<<"Incorrect Id"<<endl;
            return NULL;
        }
        else {
            if(clientptr->getPassword() == password)
            {
                return clientptr;
            }
            else{
                cout<<"incorrect password"<<endl;
                return NULL;
            }
        }
    }
        ClientManger() {}
        virtual ~ClientManger() {}

    protected:

    private:
};

#endif // CLIENTMANGER_H
