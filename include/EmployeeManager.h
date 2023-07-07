#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H
#include"person.h"
#include"Admin.h"

class EmployeeManager
{
    public:
        static void printEmployeeMenu()
        {
            system("cls");
            cout<<"Employee Function"<<endl;
            cout<<"1-Add new client"<<endl;
            cout<<"2-List of all client"<<endl;
            cout<<"3-search for a client"<<endl;
            cout<<"4-Edit client"<<endl;
            cout<<"5-Display"<<endl;
            cout<<"6-Update password"<<endl;
            cout<<"7-logout"<<endl;
        }

        static void newClient(Employee* employee)
        {
            Client client;
            string name, password;
            double balance;
            int id;
            cout<<"enter new client"<<endl;
            cout<<"name : ";
            cin>>name;
            client.setName(name);
            cout<<"password : ";
            cin>>password;
            client.setPassword(password);
            cout<<"balance : ";
            cin>>balance;
            client.setBalance(balance);
            employee->addClient(client);
            cout<<"Client accepted"<<endl;
        }

        static void listAllClients(Employee* employee)
        {
            employee->listClient();
        }

        static void searchForClient(Employee* employee)
        {
            int id;
            cout<<"Client id: ";
            cin>>id;
            Client* client = employee->searchClient(id);
            if(client == NULL)
            {
                cout<<"client not found"<<endl;
            }
            else
            {
                client->display();
            }
        }

       static void editClientInfo(Employee *employee)
{
    int x;
    int id;
    string name, password;
    double balance;
    cout<<"enter id: "<<endl;
    cin>>id;
    Client *client=employee->searchClient(id);
    if(client!=nullptr)
    {
        cout<<"what you want to edit:"<<endl;
        cout<<"1.all data"<<endl;
        cout<<"2.name"<<endl;
        cout<<"3.password"<<endl;
        cout<<"4.balance"<<endl;
        cin>>x;

        switch(x)
        {
            case 1:
                {
                    cout<<"enter new name: "<<endl;
                    cin>>name;
                    cout<<"enter new password: "<<endl;
                    cin>>password;
                    cout<<"enter new balance: "<<endl;
                    cin>>balance;
                    employee->editClient(id,name,password,balance);
                    break;
                }
            case 2:
                {
                      cout<<"enter new name: "<<endl;
                    cin>>name;
                    password=client->getPassword();
                    balance=client->getBalance();
                    employee->editClient(id,name,password,balance);
                    break;

                }
            case 3:
                {
                           cout<<"enter new password: "<<endl;
                    cin>>password;
                    name=client->getName();
                    balance=client->getBalance();
                    employee->editClient(id,name,password,balance);
                    break;
                }
            case 4:
                {
                           cout<<"enter new balance: "<<endl;
                    cin>>balance;
                    password=client->getPassword();
                    name=client->getName();
                    employee->editClient(id,name,password,balance);
                    break;
                }
            default:
                {
                    cout<<"invalid input"<<endl;
                    editClientInfo(employee);
                    break;
                }

        }
    }
        else{

            cout<<"Client not found try again"<<endl;
            cout<<"1.try again"<<endl;
            cout<<"2.back"<<endl;
            int x;
            cout<<"enter your choice"<<endl;
            cin>>x;
            if(x==1)
            {
                editClientInfo(employee);
            }
            else if(x==2)
            {
                printEmployeeMenu();
                employeeOptions(employee);
            }
            else{


                cout<<"not valid"<<endl;
                system("pause");
                printEmployeeMenu();
                employeeOptions(employee);

            }
        }

    //}
}

static bool employeeOptions(Employee *employee)
{
int x;
cout<<"enter your choice: "<<endl;
cin>>x;
switch(x)
{
   case 1:
       {
           system("cls");
           newClient(employee);
           break;
       }
   case 2:
    {
        system("cls");
        listAllClients(employee);
        break;

    }
   case 3:
       {
           system("cls");
           searchForClient(employee);
           break;
       }
   case 4:
    {
        system("cls");
        editClientInfo(employee);
        break;
    }
   case 5:
    {
        system("cls");
        employee->display();
        break;
    }
   case 6:
    {
        system("cls");
        updatePassword(employee);
        break;
    }
   case 7:
    {
        return true;

    }
   default:
    {
        cout<<"invalid choice"<<endl;
        employeeOptions(employee);
    }

}
Back(employee);

}
static void Back(Employee *employee)
{
    system("pause");
    printEmployeeMenu();
    employeeOptions(employee);

}
static void updatePassword(person* person)
{
cout<<"enter new password: "<<endl;
string password;
cin>>password;
person->setPassword(password);
cout<<"password updated "<<endl;

}

static Employee* login(int id, string password){
    cout<<"login"<<endl;
    Admin a;
Employee *employeptr= a.searchEmployee(id);
if(employeptr==NULL)
{
    return NULL;
}
else
{
    if(employeptr->getPassword()==password)
    {
        return employeptr;
    }
    else
    {
    cout<<"incorrect ID or password"<<endl;
        return nullptr;
    }
}
}
        //EmployeeManager() {}
        //virtual ~EmployeeManager() {}

    protected:

    private:
};

#endif // EMPLOYEEMANAGER_H
