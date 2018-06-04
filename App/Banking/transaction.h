#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include <string>

using namespace std;

class Transaction
{
protected:
    float amount, initial_balance, final_balance;
    string date;
    string type;
    bool from_to;
    //string description;
public:
    Transaction(float amount=0, string date="To be set", string type="To be set", bool from_to=0, float initial_balance=0, float final_balance=0);
    friend ostream& operator << (ostream& os, const Transaction& transaction);

};

class Debit:public Transaction
{
public:
    Debit(float amount=0, string date="To be set", float initial_balance=0, float final_balance=0);
    //friend ostream& operator << (ostream& os, const Simple& transaction);
};

class Credit:public Transaction
{
public:
    Credit(float amount=0, string date="To be set", float initial_balance=0, float final_balance=0);
    //friend ostream& operator << (ostream& os, const Simple& transaction);
};

class Transfer:public Transaction
{
//protected:
//    bool from_to;
public:
    Transfer(float amount=0, string date="To be set", bool from_to=0, float initial_balance=0, float final_balance=0);
    //friend ostream& operator << (ostream& os, const Transfer& transaction);
};

class Fees:public Transaction
{
public:
    Fees(float amount=0, string date="To be set", float initial_balance=0, float final_balance=0);
};

#endif // TRANSACTION_H
