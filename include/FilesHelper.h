#ifndef FILESHELPER_H
#define FILESHELPER_H
#include <iostream>
#include<fstream>
#include"Client.h"
#include"Employee.h"
#include"parser.h"

using namespace std;

class FilesHelper
{
public:
    static void saveLast(string fileName, int id)
    {
        fstream myFile;
        myFile.open(fileName,ios::out);//write
        if(myFile.is_open())
        {
            myFile<<id<<endl;
            myFile.close();

        }
    }

    static int getLast(string fileName)
    {
        int x;
        fstream myFile;
        myFile.open(fileName,ios::in);//read

        if(myFile.is_open())
        {
            string line;
            while(getline(myFile,line))
            {
                x =stoi(line);
            }
            myFile.close();
        }
        return x;
    }

    static void saveClient(Client c)
    {
        int x = (getLast("client id.txt")+1);
        fstream myFile;
        myFile.open("Clients.txt",ios::app);//write
        if(myFile.is_open())
        {
            myFile<<c.getName()<<" ";
            myFile<<x<<" ";
            myFile<<c.getPassword()<<" ";
            myFile<<c.getBalance()<<" "<<endl;
            myFile.close();

        }
        saveLast("client id.txt",x);
    }

    static void saveEmployee(string fileName, string lastIdFile, Employee e)
    {
        int x = (getLast(lastIdFile)+1);
        fstream myFile;
        myFile.open(fileName,ios::app);//write
        if(myFile.is_open())
        {
            myFile<<e.getName()<<" ";
            myFile<<x<<" ";
            myFile<<e.getPassword()<<" ";
            myFile<<e.getSalary()<<" "<<endl;
            myFile.close();

        }
        saveLast(lastIdFile,x);
    }
     static vector<Client> getClients()
    {
        fstream myFile;
        myFile.open("Clients.txt",ios::in);//read
        vector<Client>clients;
        Client c;
        if(myFile.is_open())
        {
            string line;
            while(getline(myFile,line))
            {
               c=Parser::parseToClient(line);
                clients.push_back(c);

            }
            myFile.close();
        }
        return clients;

    }

    static vector<Employee> getEmployees()
    {
        fstream myFile;
        myFile.open("Employee.txt",ios::in);//read
        vector<Employee>employees;
        Employee e;
        if(myFile.is_open())
        {
            string line;
            while(getline(myFile,line))
            {
                e=Parser::parseToEmployee(line);
                employees.push_back(e);
            }
            myFile.close();
        }
        return employees;

    }
    static vector<Admin> getAdmins()
    {
        vector<Admin> admins;
        fstream myFile;
        Admin a;
        myFile.open("Admin.txt",ios::in);//read
        if(myFile.is_open())
        {
            string line;
            while(getline(myFile,line))
            {
                a=Parser::parseToAdmin(line);
                admins.push_back(a);
            }
            myFile.close();
        }
        return admins;

    }

    static void clearFile(string fileName, string lastIdFile)
    {
        fstream myFile;
        myFile.open(fileName,ios::out);
        if(myFile.is_open())
        {
            string* line=new string;
            while(getline(myFile,*line))
            {
                delete line;
            }
            myFile.close();
        }
        myFile.open(lastIdFile,ios::out);
        if(myFile.is_open())
        {
             myFile<<0<<endl;
            myFile.close();
        }
    }
        //FilesHelper() {}
        //virtual ~FilesHelper() {}

    protected:

    private:
};

#endif // FILESHELPER_H
