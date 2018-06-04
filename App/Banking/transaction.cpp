#include "transaction.h"

Transaction::Transaction(float amount, string date, string type, bool from_to, float initial_balance, float final_balance)
    :amount(amount),
    date(date),
    type(type),
    from_to(from_to),
    initial_balance(initial_balance),
    final_balance(final_balance)
{
}

Credit::Credit(float amount, string date, float initial_balance, float final_balance)
    :Transaction(amount, date,"CREDIT", initial_balance, final_balance)
{
}

Debit::Debit(float amount, string date, float initial_balance, float final_balance)
    :Transaction(amount, date, "DEBIT", initial_balance, final_balance)
{
}

Transfer::Transfer(float amount, string date, bool from_to, float initial_balance, float final_balance)
    :Transaction(amount, date, "TRANSFER", from_to, initial_balance, final_balance)
{
}

Fees::Fees(float amount, string date, float initial_balance, float final_balance)
    :Transaction(amount, date, "FEES", initial_balance, final_balance)
{
}

ostream& operator << (ostream& os, const Transaction& transaction)
{
    if((transaction.type)=="DEBIT")
    {
        os<<"*DEBIT*"<<endl;
        os<<"-> "<<transaction.initial_balance<<"  +  "<<transaction.amount<<"   Balance: "<<transaction.final_balance;
    }

    if((transaction.type)=="CREDIT")
    {
        os<<"*CREDIT*"<<endl;
        os<<"-> "<<transaction.initial_balance<<"  -  "<<transaction.amount<<"   Balance: "<<transaction.final_balance;
    }

    if((transaction.type)=="FEES")
    {
        os<<"*FEES*"<<endl;
        os<<"-> "<<transaction.initial_balance<<"  -  "<<transaction.amount<<"   Balance: "<<transaction.final_balance;
    }

    if((transaction.type)=="TRANSFER")
    {
        if(transaction.from_to==0)
        {
            os<<"*TRANSFER CREDIT*"<<endl;
            os<<"-> "<<transaction.initial_balance<<"  -  "<<(transaction.final_balance-transaction.initial_balance)<<"   Balance: "<<transaction.final_balance;
        }

        if(transaction.from_to==1)
        {
            os<<"*TRANSFER DEBIT*"<<endl;
            os<<"-> "<<transaction.initial_balance<<"  +  "<<(transaction.final_balance-transaction.initial_balance)<<"   Balance: "<<transaction.final_balance;
        }
    os<<"  *** Date: "<<transaction.date;
    }

    return os;
}


//ostream& operator << (ostream& os, const Simple& transaction)
//{
//    if((transaction.debit_credit)==0)
//    {
//        os<<"*DEBIT*"<<endl;
//        os<<"-> "<<transaction.initial_balance<<"  +  "<<transaction.amount<<"   Balance: "<<transaction.final_balance;
//    }

//    if((transaction.debit_credit)==1)
//    {
//        os<<"*CREDIT*"<<endl;
//        os<<"-> "<<transaction.initial_balance<<"  -  "<<transaction.amount<<"   Balance: "<<transaction.final_balance;
//    }
//    os<<"  *** Date: "<<transaction.date;

//    return os;
//}

//ostream& operator << (ostream& os, const Transfer& transaction)
//{
//    if((transaction.from_to)==0)
//    {
//        os<<"*DEBIT*"<<endl;
//        os<<"-> "<<transaction.initial_balance<<"  +  "<<transaction.amount<<"   Balance: "<<transaction.final_balance;
//    }

//    if((transaction.from_to)==1)
//    {
//        os<<"*CREDIT*"<<endl;
//        os<<"-> "<<transaction.initial_balance<<"  -  "<<transaction.amount<<"   Balance: "<<transaction.final_balance;
//    }
//    os<<"  *** Date: "<<transaction.date;

//    return os;
//}
