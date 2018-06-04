#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include <string>

using namespace std;

enum tr_type
{
    DEBIT, CREDIT, FEES, TRANSFER
};

class Transaction
{
protected:
    float amount;
    string date;
    tr_type type;
    bool from_to;
    float initial_balance, final_balance;
    //string description;
public:
    Transaction(float amount=0, string date="To be set", tr_type type=DEBIT, float initial_balance=0, float final_balance=0);
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
