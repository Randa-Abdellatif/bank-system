#ifndef DATASOURCEINTERFACE_H
#define DATASOURCEINTERFACE_H
#include <iostream>
#include<Admin.h>
#include<vector>
#include<Employee.h>
#include<Client.h>
using namespace std;


class DataSourceInterface
{
    public:
        virtual void addClient(Client c)=0;
        virtual void addEmployee(Employee e)=0;
        virtual void addAdmin(Admin a)=0;
        virtual vector<Client> getAllClients()=0;
        virtual vector<Employee>getAllEmployees()=0;
        virtual vector<Admin>getAllAdmins()=0;
        virtual void removeAllClients()=0;
        virtual void removeAllEmployees()=0;
        virtual void removeAllAdmins()=0;
        //DataSourceInterface() {}
        //virtual ~DataSourceInterface() {}

    protected:

    private:
};

#endif // DATASOURCEINTERFACE_H
