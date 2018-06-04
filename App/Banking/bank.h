#ifndef BANK_H
#define BANK_H
#include <list>
#include <string>
#include <iostream>
#include <limits>
#include "client.h"
#include "account.h"
#include "interface.h"
#include "transaction.h"

using namespace std;

class Bank
{
    list<Client> clients;
    list<Account*> accounts;
    unsigned int code;
    int clControl=1;

public:
    string name;
    Bank(string name="To be set", unsigned int code=0);
    Bank(const Bank& bank);

    string client_nr();
    void new_client(); // finalizar com controlo de inserção
    void delete_client();
    Client* find_client();
    Client* find_client(const string& code);
    //Client* find_client_name(const string& name); falta implementar
    void list_clients();

    void new_account();
    void process_fees();
    void delete_account();
    void list_accounts();
    Account* find_account();
    Account* find_account(const string& iban);
    Account* find_account(Client* client);


    void debit();
    void credit();
    void transfer();
    void list_transactions();

    Bank operator =(const Bank& bank);
    friend ostream &operator << (ostream& os, const Bank& bank);

    ~Bank();
};


#endif // BANK_H
