#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <iostream>
#include<fstream>
#include<string>
#include<DataSourceInterface.h>
#include<Client.h>
#include<Employee.h>
#include<Admin.h>
#include<parser.h>
#include<FilesHelper.h>
using namespace std;


class FileManager:public DataSourceInterface
{
public:

    void addClient(Client c)
    {
        FilesHelper::saveClient(c);
    }
    void addEmployee(Employee e)
    {
        FilesHelper::saveEmployee("Employee.txt","employee id.txt",e);
    }
    void addAdmin(Admin a)
    {
        FilesHelper::saveEmployee("Admin.txt","admin id.txt",a);
    }
    vector<Client> getAllClients()
    {
        //vector<Client>clients;
        clients=FilesHelper::getClients();
        return clients;
    }

    vector<Employee> getAllEmployees()
    {

        //vector<Employee>employees;
        employees=FilesHelper::getEmployees();
        return employees;
    }

    vector<Admin> getAllAdmins()
    {
        //vector<Admin> admins;
        admins=FilesHelper::getAdmins();
        return admins;
    }

    void removeAllClients()
    {
        FilesHelper::clearFile("Clients.txt","client id.txt");

    }
    void removeAllEmployees()
    {
        FilesHelper::clearFile("Employee.txt","employee id.txt");

    }
    void removeAllAdmins()
    {
    FilesHelper::clearFile("Admin.txt","admin id.txt");

    }
    //FileManager() {}
    //virtual ~FileManager() {}

protected:

private:
};

#endif // FILEMANAGER_H
