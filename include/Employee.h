#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include<vector>
#include"person.h"
#include"Validation.h"
#include"Client.h"
#include"searchIdException.h"
using namespace std;


class Employee:public person
{
public:
    // employee() {}
    void setSalary(double salary)
    {
        this->salary= Validation::setSalary(salary);

    }
    double getSalary()
    {
        return salary;
    }

    void display()
    {
        person::display();
        cout<<"salary: "<<salary<<endl;
    }

    void addClient(Client& client)
    {
        clients.push_back(client);
        // FileManager f;
        // f.addClient(client);
    }

    Client* searchClient(int id)
    {

        for (int i = 0; i <clients.size(); i++)
        {

            if(clients[i].getId() == id)
            {
                vector <Client>::iterator it = clients.begin()+i;
                return &(*it);
            }

            //else {throw searchIdException();}
        }
        return NULL;
    }

    void listClient()
    {
        cout<<"all clients info: "<<endl;
        for (int i = 0; i <clients.size(); i++)
        {
            cout<<"client num "<<i+1<<endl;
            clients[i].display() ;
        }
    }

    void editClient(int id, string name, string password, double balance)
    {
        Client* c = searchClient(id);
        c->setName(name);
        c->setPassword(password);
        c->setBalance(balance);
    }

    //virtual ~employee() {}

protected:
    double salary;

private:
};
static vector<Employee> employees;

#endif // EMPLOYEE_H
