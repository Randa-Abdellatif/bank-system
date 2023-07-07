#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include"Validation.h"
using namespace std;


class person
{
    public:
        //person() {}
        void setId(int id)
        {
            this->id=id;
        }
        int getId(){return id;}
        void setName(string name)
        {

            this->name = Validation::setName(name);
        }

        string getName(){return name;}
         void setPassword(string password)
        {
            this->password=Validation::setPassword(password);
        }
        string getPassword(){return password;}
        void display(){
            cout<<"name: "<<name<<endl;
            cout<<"Id: "<<id<<endl;
            cout<<"password: "<<password<<endl;
        }
        //virtual ~person() {}

    protected:
        int id;
        string name;
        string password;

    private:
};

#endif // PERSON_H
