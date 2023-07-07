#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include<person.h>
#include<Validation.h>
#include<Client.h>

using namespace std;


class employee:public person
{
    public:
       // employee() {}
        void setSalary(double salary)
        {
            this->salary= Validation::setSalary(salary);

        }
        double getSalary(){return salary;}
        void display(){
            person::display();
            cout<<"salary: "<<salary<<endl;
        }

        /*void addClient(Client& client){
            client.setName();
            client.setBalance();
            client.setId();
            client.setPassword();
        }*/
        Client* searchClient(int id){
            Client c;
            for(int i=0;;i++){

            }
        }
        //virtual ~employee() {}

    protected:
        double salary;

    private:
};

#endif // EMPLOYEE_H
