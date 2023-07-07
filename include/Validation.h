#ifndef VALIDATION_H
#define VALIDATION_H
#include <iostream>
#include <string>         // std::string
#include <locale>         // std::locale, std::isalpha
//#include <stdio.h>
#include <ctype.h>
using namespace std;


class Validation
{
protected:
    static string name;
    static string password;
    static double balance;
    static double salary;
public:
  static string setName(string n)
        {
           while(n.size()<5 || n.size()>20){
                    cout<<"not valid,";
                if(n.size()<5){
                    cout<<"min size 5"<<endl;
                }
            else if(n.size()>20){
                cout<<"max size 20"<<endl;
            }
            cin>>n;
            //getline(cin,n);
        }


        bool test = false;
        while( test == false)
        {

            for(int i = 0; i < n.size(); i++)
            {
                 if(isalpha(n[i]))
                {
                    test=true;
                }
                else
                {
                    cout << "Input must only contain letters\n";
                    cin>>n;
                    //getline(cin,n);
                    i=0;

                }
            }

            return n;
        }

        }

          static string setPassword(string p)
        {
            while(p.size()<8 || p.size()>20){
                    cout<<"not valid,";
                if(p.size()<8){
                    cout<<"min size 8"<<endl;
                }
            else if(p.size()>20){
                cout<<"max size 20"<<endl;
            }
            cin>>p;
           //getline(cin,p);
            }
            return p;
            //password=p;
        }
         static double setBalance(double b)
        {
            while(b<1500){
                cout<<"not valid min balance 1500"<<endl;
                cin>>b;
            }
            return b;
           //balance=b;
        }

        static double setSalary(double s)
        {
            while(s<5000){
                cout<<"not valid min salary 5000"<<endl;
                cin>>s;
            }
            return s;
           // salary=s;
        }

};

#endif // VALIDATION_H
