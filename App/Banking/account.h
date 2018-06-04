#ifndef ACCOUNT
#define ACCOUNT
#include <string>
#include <iostream>
#include <list>
#include "transaction.h"

using namespace std;

struct fees
{
    float student=0;
    float retired=3;
    float normal=2;
};

class Account
{
protected:
    string type;
    fees fee;
    unsigned int account_nr;
    bool status;
    list<Transaction*> transactions;
    float balance;
public:
    string iban;
    //STRING IBAN é PUBLICO
    //bool status deve ser publico tambem
    //construtor contas em ficheiros t/ de ser de forma diferente
    //struct cliente c/ dados (nome, idade, etc....)
    //apontadores c/ identificadores p  / cada conta, e ñ endereços de memoria
    Account(float balance=200, string iban ="to be set", unsigned int account_nr=0, bool status=1);
    Account(const string& type);
    Account(const Account& account);
    friend ostream &operator << (ostream& os, const Account &account);
    RandomAccountNumber();
//  RandomIban();
    void block();
    //void unblock? ou mesma fun faz o msm?
    virtual void process_fee(void)=0;
    float deposit(float amount);
    float withdraw(float amount);
    unsigned int get_account_nr();
    float get_balance();
    void add_transaction(Transaction* transaction);
    void print_transactions();
    ~Account();
};

class Student : public Account
{
    public:
    Student(float balance=0, string iban="1234789", unsigned int account_nr=0, bool status=1);
    Student(const Student& student);
    Student(const string& type);
    void process_fee()
    {
       balance=balance-(fee.student);
    }
};

class Retired : public Account
{
    public:
    Retired(float balance=0, string iban="1234789", unsigned int account_nr=0, bool status=1);
    Retired(const Retired& retired);    
    Retired(const string& type);
    void process_fee()
    {
       balance=balance-(fee.retired);
    }
};

class Normal : public Account
{
    public:
    Normal(float balance=0, string iban="1234789", unsigned int account_nr=0, bool status=1);
    Normal(const Normal& normal);
    Normal(const string& type);
    void process_fee()
    {
       balance=balance-(fee.normal);
    }
};

#endif // ACCOUNT



