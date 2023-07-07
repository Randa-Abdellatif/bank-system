#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include"Admin.h"
#include"Client.h"
using namespace std;


class Parser
{
    public:
        static vector<string> split(string line){
            string space_delimiter = " ";
                vector<string> words{};

                size_t pos = 0;
                while ((pos = line.find(space_delimiter)) != string::npos)
                {
                    words.push_back(line.substr(0, pos));
                    line.erase(0, pos + space_delimiter.length());
                }
                return words;
        }

    static Client parseToClient(string line)
    {
        //vector <Student>v=c.allStudentsInfo();
        vector<string> words=split(line);
        Client c;
        c.setName(words[0]);
        c.setId(stoi(words[1]));
        c.setPassword(words[2]);
        c.setBalance(stod(words[3]));
        return c;
    }

    static Employee parseToEmployee(string line)
    {
        vector<string> words=split(line);
        Employee e;
        e.setName(words[0]);
        e.setId(stoi(words[1]));
        e.setPassword(words[2]);
        e.setSalary(stod(words[3]));
        return e;
    }

    static Admin parseToAdmin(string line)
    {
        vector<string> words=split(line);
        Admin a;
        a.setName(words[0]);
        a.setId(stoi(words[1]));
        a.setPassword(words[2]);
        a.setSalary(stod(words[3]));
        return a;
    }
       // Parser() {}
       // virtual ~Parser() {}

    protected:

    private:
};

#endif // PARSER_H
