#include <iostream>
#include<vector>
#include<person.h>
#include<Client.h>
#include<Employee.h>
#include<FilesHelper.h>
#include<FileManager.h>
#include<Screens.h>
using namespace std;
#include<fstream>

int Client::Client_num =FilesHelper::getLast("client id.txt");
int main()
{
    Screens::runApp();
    //Screens::loginOptions();
    //Screens::loginScreen(Screens::loginAs());
    //FilesHelper::saveLast("client id.txt",0);
    //int x=FilesHelper::getLast("client id.txt");
    //FilesHelper::clearFile("client id.txt",x);
    /*ifstream file;
    file.open("")*/
   /*string n;
    Employee e;
    getline(cin,n);
    e.setName(n);
    cout<<"password"<<endl;
    e.setPassword("5852158669");
    e.setId(2525);
    e.setSalary(60000);
    e.display();


    Client c;
    getline(cin,n);
    c.setName(n);
    c.setPassword("58693214");
    //c.setId(2525);
    c.setBalance(60000);
    c.display();

   /* FileManager f;
    vector<Client>cl=f.getAllClients();
    cout<<"all clients"<<endl;
    for(int i=0;i<cl.size();i++){
        cl[i].display();
    }*/
    return 0;
}


