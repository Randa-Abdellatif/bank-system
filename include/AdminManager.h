#ifndef ADMINMANAGER_H
#define ADMINMANAGER_H
#include <iostream>
#include<stdlib.h>
#include<EmployeeManager.h>
#include"Admin.h"
using namespace std;


class AdminManager:public EmployeeManager{
public:
    static void printAdminMenue(){
    system("cls");
    cout<<"Admin Functions"<<endl;
    cout<<"1-Add new client "<<endl;
    cout<<"2-List of all client"<<endl;
    cout<<"3-Search for a client"<<endl;
    cout<<"4-Edit client"<<endl;
    cout<<"5-Add new employee"<<endl;
    cout<<"6-List of all employee"<<endl;
    cout<<"7-Search for a employee"<<endl;
    cout<<"8-Edit employee"<<endl;
    cout<<"9-update password"<<endl;
    cout<<"10-Display"<<endl;
    cout<<"11-Logout"<<endl;
    cout<<endl;
    }

   static void editEmployeeInfo(Admin *admin)
{
    int x;
    int id;
    string name, password;
    double salary;
    cout<<"enter id: "<<endl;
    cin>>id;
    Employee *employee=admin->searchEmployee(id);
    if(employee!=nullptr)
    {
        cout<<"what you want to edit:"<<endl;
        cout<<"1.all data"<<endl;
        cout<<"2.name"<<endl;
        cout<<"3.password"<<endl;
        cout<<"4.salary"<<endl;
        cin>>x;

        switch(x)
        {
            case 1:
                {
                    cout<<"enter new name: "<<endl;
                    cin>>name;
                    cout<<"enter new password: "<<endl;
                    cin>>password;
                    cout<<"enter new salary: "<<endl;
                    cin>>salary;
                    admin->editEmployee(id,name,password,salary);
                    break;
                }
            case 2:
                {
                      cout<<"enter new name: "<<endl;
                    cin>>name;
                    password=employee->getPassword();
                    salary=employee->getSalary();
                    admin->editEmployee(id,name,password,salary);
                    break;

                }
            case 3:
                {
                           cout<<"enter new password: "<<endl;
                    cin>>password;
                    name=employee->getName();
                    salary=employee->getSalary();
                    admin->editEmployee(id,name,password,salary);
                    break;
                }
            case 4:
                {
                           cout<<"enter new salary: "<<endl;
                    cin>>salary;
                    password=employee->getPassword();
                    name=employee->getName();
                    admin->editEmployee(id,name,password,salary);
                    break;
                }
            default:
                {
                    cout<<"invalid input"<<endl;
                    editEmployeeInfo(admin);
                    break;
                }

        }
    }
        else{

            cout<<"Employee not found try again"<<endl;
            cout<<"1.try again"<<endl;
            cout<<"2.back"<<endl;
            int x;
            cout<<"enter your choice"<<endl;
            cin>>x;
            if(x==1)
            {
                editEmployeeInfo(admin);
            }
            else if(x==2)
            {
                printAdminMenue();
                adminOptions(admin);
            }
            else{


                cout<<"not valid"<<endl;
                system("pause");
                printAdminMenue();
                adminOptions(admin);

            }
        }

    }


 static void newEmployee(Admin* admin)
        {
            Employee employee;
            string name, password;
            double salary;
            int id;
            cout<<"enter new Employee"<<endl;
            cout<<"name : ";
            cin>>name;
            employee.setName(name);
            cout<<"password : ";
            cin>>password;
            employee.setPassword(password);
            cout<<"salary : ";
            cin>>salary;
            employee.setSalary(salary);
            admin->addEmployee(employee);
            cout<<"Employee accepted"<<endl;
        }



        static void listAllEmployee(Admin* admin)
        {
            admin->listEmployee();
        }



        static void searchForEmployee(Admin* admin)
        {
            int id;
            cout<<"Employee id: ";
            cin>>id;
            Employee* employee = admin->searchEmployee(id);
            if(employee == NULL)
            {
                cout<<"  Employee not found"<<endl;
            }
            else
            {
                employee->display();
            }
        }



    static bool adminOptions(Admin *admin)
{
int x;
cout<<"enter your choice: "<<endl;
cin>>x;
switch(x)
{
   case 1:
       {
           system("cls");
           newClient(admin);
           break;
       }
   case 2:
    {
        system("cls");
        listAllClients(admin);
        break;
    }
   case 3:
       {
           system("cls");
           searchForClient(admin);
           break;
       }
   case 4:
    {
        system("cls");
        editClientInfo(admin);
        break;
    }

     case 5:
       {
           system("cls");
           newEmployee(admin);
           break;
       }
   case 6:
    {
        system("cls");
        listAllEmployee(admin);
        break;
    }
   case 7:
       {
           system("cls");
           searchForEmployee(admin);
           break;
       }


   case 8:
    {
        system("cls");
       editEmployeeInfo(admin);
       break;
    }
   case 9:
    {
        system("cls");
        ClientManger::updatePassword(admin);
        break;
    }
    case 10:
    {
        system("cls");
        admin->display();
        break;
    }
   case 11:
    {
        return true;

    }
   default:
    {
        cout<<"invalid choice"<<endl;
        adminOptions(admin);
    }

}
Back(admin);

}


static void Back(Admin *admin)
{
    system("pause");
    printAdminMenue();
    adminOptions(admin);

}


static Admin* loginAdminP(int id ,string password ){
    cout<<"loginAdminP"<<endl;
   if( admins[0].getId() == id && admins[0].getPassword()==password)
   {
       return &admins[0];
   }
   else{
    cout<<"Incorrect id or password"<<endl;
    return NULL;
   }

}
        AdminManager() {}
        virtual ~AdminManager() {}

    protected:

    private:
};

#endif // ADMINMANAGER_H
