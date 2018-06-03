#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include <iostream>
#include <list>
#include "account.h"

using namespace std;

class Client
{
    string name;
    string client_code;
    string birth_date;
    unsigned int nif;
    string address;
    string zip_code;
    list<Account*> accounts;

public:
    Client(string name="Not set", string client_code=0, string birth_date="01-01-1900", unsigned int nif=0, string address="Not set", string zip_code="Not set");
    Client(const Client& client);
    friend ostream &operator << (ostream& os, const Client &client);
    int age();
    bool find_name(string name);
    bool find_code(string code);
    void change_add(string address);
    void add_account(Account* account);
    ~Client();
};

#endif // CLIENT_H
