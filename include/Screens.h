#ifndef SCREENS_H
#define SCREENS_H
#include"ClientManger.h"
#include"FileManager.h"
#include"EmployeeManager.h"
#include"AdminManager.h"

class Screens
{
    public:
        static void bankName()
        {
            const char *string = "BBBB   aaa    N    N  k    k\n"
                                 "B  B  a   a   N N  N  k   k\n"
                                 "BBB   aaaaa   N  N N  k k\n"
                                 "B  B  a   a   N   NN  kk k\n"
                                 "BBBB  a   a   N    N  k   k\n";

  std::cout << string;
system("pause");
        }

    static void welcome()
    {
        system("cls");
        std::vector<std::string> v;

        v.push_back("H   H    EEEEE   L       L        OOOOO");
        v.push_back("H   H    E       L       L       O     O");
        v.push_back("H   H    E       L       L       O     O");
        v.push_back("HHHHH    EEEEE   L       L       O     O");
        v.push_back("H   H    E       L       L       O     O");
        v.push_back("H   H    E       L       L       O     O");
        v.push_back("H   H    EEEEE   LLLLL   LLLLL    OOOOO");

        for (auto row : v)
        {
            for (auto col : row)
                cout << col;
            cout << endl;
        }
system("pause");
    }

        static void loginOptions()
        {
            system("cls");
            cout<<"login as"<<endl;
            cout<<"1-Client"<<endl;
            cout<<"2-Employee"<<endl;
            cout<<"3-Admin"<<endl;
            cout<<"4-Exit"<<endl;
        }

        static int loginAs()
        {
            int x;
            cout<<"login as : "<<endl;
            cin>>x;
            switch(x)
            {
            case 1:
                {
                    return 1;
                    break;
                }
            case 2:
                {
                    return 2;
                    break;
                }
            case 3:
                {
                    return 3;
                    break;
                }
            case 4:
                {
                    return 4;
                    break;
                }

            default:
                {
                    invalid(x);
                    break;
                }

            }
        }

        static void invalid(int c)
        {
            cout<<"your choice not found in list"<<endl;
            loginAs();
        }

        static void loginScreen(int c)
        {
            switch(c)
            {
            case 1:
                {
                    system("cls");
                    loginClient();
                    break;
                }
            case 2:
                {
                    system("cls");
                    loginEmployee();
                    break;
                }
            case 3:
                {
                    system("cls");
                    loginAdmin();
                    break;
                }
            case 4:
                {
                FileManager f;
                f.removeAllClients();
                for(int i=0; i<clients.size(); i++)
                {
                    f.addClient(clients[i]);
                }
                f.removeAllEmployees();
                 for(int i=0; i<employees.size(); i++)
                {
                    f.addEmployee(employees[i]);
                }
                f.removeAllAdmins();
                f.addAdmin(admins[0]);
                }
            }
        }

        static void loginClient()
        {
            cout<<"login client page"<<endl;
            int id;
            string password;
            cout<<"id : ";
            cin>>id;
            cout<<"password : ";
            cin>>password;
            Client *client=ClientManger::login(id,password);
            if(client != NULL)
            {
                ClientManger::printClientMenu();
                if(ClientManger::clientOptions(client))
                {
                 system("cls");
                 loginOptions();
                 loginScreen(loginAs());
                }
            }
            else
            {
                cout<<"1-try again"<<endl;
                cout<<"2-return"<<endl;
                int x;
                cout<<"enter your choice : ";
                cin>>x;
                system("cls");
                if(x==1)
                {
                    loginClient();
                }
                else if(x==2)
                {
                    system("cls");
                    loginOptions();
                    loginScreen(loginAs());
                }
                else
                {
                    cout<<"your choice not found in list"<<endl;
                    system("pause");
                    system("cls");
                    loginOptions();
                    loginScreen(loginAs());
                }
            }
        }

        static void loginEmployee()
        {
cout<<"login employee page"<<endl;
            int id;
            string password;
            cout<<"id : ";
            cin>>id;
            cout<<"password : ";
            cin>>password;
            Employee *employee=EmployeeManager::login(id,password);
            if(employee != NULL)
            {
                EmployeeManager::printEmployeeMenu();
                if(EmployeeManager::employeeOptions(employee))
                {
                 system("cls");
                 loginOptions();
                 loginScreen(loginAs());
                }
            }
            else
            {
                cout<<"1-try again"<<endl;
                cout<<"2-return"<<endl;
                int x;
                cout<<"enter your choice : ";
                cin>>x;
                system("cls");
                if(x==1)
                {
                    loginEmployee();
                }
                else if(x==2)
                {
                    system("cls");
                    loginOptions();
                    loginScreen(loginAs());
                }
                else
                {
                    cout<<"your choice not found in list"<<endl;
                    system("pause");
                    system("cls");
                    loginOptions();
                    loginScreen(loginAs());
                }
            }
        }

        static void loginAdmin()
        {
cout<<"login admin page"<<endl;
            int id;
            string password;
            cout<<"id : ";
            cin>>id;
            cout<<"password : ";
            cin>>password;
            Admin *admin=AdminManager::loginAdminP(id,password);
            if(admin != NULL)
            {
                AdminManager::printAdminMenue();
                if(AdminManager::adminOptions(admin))
                {
                 system("cls");
                 loginOptions();
                 loginScreen(loginAs());
                }
            }
            else
            {
                cout<<"1-try again"<<endl;
                cout<<"2-return"<<endl;
                int x;
                cout<<"enter your choice : ";
                cin>>x;
                system("cls");
                if(x==1)
                {
                    loginAdmin();
                }
                else if(x==2)
                {
                    system("cls");
                    loginOptions();
                    loginScreen(loginAs());
                }
                else
                {
                    cout<<"your choice not found in list"<<endl;
                    system("pause");
                    system("cls");
                    loginOptions();
                    loginScreen(loginAs());
                }
            }
        }

        static void runApp()
        {
          bankName();
          welcome();
          FileManager f;
          f.getAllClients();
          f.getAllEmployees();
          f.getAllAdmins();
          loginOptions();
          loginScreen(loginAs());

        }
        Screens() {}
        virtual ~Screens() {}

    protected:

    private:
};

#endif // SCREENS_H
