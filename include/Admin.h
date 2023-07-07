#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include "Employee.h"
#include"searchIdException.h"
using namespace std;

class Admin: public Employee
{
    public:
        void addEmployee(Employee& employee)
    {
        employees.push_back(employee);
    }

    Employee* searchEmployee(int id)
    {

        for (int i = 0; i <employees.size(); i++)
        {

            if(employees[i].getId() == id)
            {
                vector <Employee>::iterator it = employees.begin()+i;
                return &(*it);
            }
           // else {throw searchIdException();}
        }
        return NULL;

    }

   void listEmployee()
    {
        cout<<"all employees info: "<<endl;
        for (int i = 0; i <employees.size(); i++)
        {
            cout<<"employee num "<<i+1<<endl;
            employees[i].display() ;
        }

    }

    void editEmployee(int id, string name, string password, double salary)
    {
        Employee* e = searchEmployee(id);
        e->setName(name);
        e->setPassword(password);
        e->setSalary(salary);
    }
        Admin() {}
        virtual ~Admin() {}

    protected:


    private:
};
  static vector<Admin>admins;
#endif // ADMIN_H
