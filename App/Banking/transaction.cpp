#include "transaction.h"

Transaction::Transaction(float p_amount, string p_date, tr_type p_type, float p_initial_balance, float p_final_balance)
    :amount(p_amount),
    date(p_date),
    type(p_type),
    initial_balance(p_initial_balance),
    final_balance(p_final_balance)
{
}

Credit::Credit(float amount, string date, float initial_balance, float final_balance)
    :Transaction(amount, date,CREDIT, initial_balance, final_balance)
{
}

Debit::Debit(float amount, string date, float initial_balance, float final_balance)
    :Transaction(amount, date, DEBIT, initial_balance, final_balance)
{
}

Transfer::Transfer(float amount, string date, bool from_to, float initial_balance, float final_balance)
    :Transaction(amount, date, TRANSFER, initial_balance, final_balance)
{
    this->from_to=from_to;
}

Fees::Fees(float amount, string date, float initial_balance, float final_balance)
    :Transaction(amount, date, FEES, initial_balance, final_balance)
{
}

ostream& operator << (ostream& os, const Transaction& transaction)
{
    switch (transaction.type)
    {
    case DEBIT:
    {
        os<<"*DEBIT*"<<endl;
        os<<"-> "<<transaction.initial_balance<<"  +  "<<transaction.amount<<"   Balance: "<<transaction.final_balance;
        break;
    }
    case CREDIT:
    {
        os<<"*CREDIT*"<<endl;
        os<<"-> "<<transaction.initial_balance<<"  -  "<<transaction.amount<<"   Balance: "<<transaction.final_balance;
        break;
    }
    case FEES:
    {
        os<<"*FEES*"<<endl;
        os<<"-> "<<transaction.initial_balance<<"  -  "<<transaction.amount<<"   Balance: "<<transaction.final_balance;
        break;
    }
    case TRANSFER:
    {
        if(transaction.from_to==0)
        {
            os<<"*TRANSFER CREDIT*"<<endl;
            os<<"-> "<<transaction.initial_balance<<"  -  "<<transaction.amount<<"   Balance: "<<transaction.final_balance;
        }

        if(transaction.from_to==1)
        {
            os<<"*TRANSFER DEBIT*"<<endl;
            os<<"-> "<<transaction.initial_balance<<"  +  "<<transaction.amount<<"   Balance: "<<transaction.final_balance;
        }

        break;
    }
//    if((transaction.type)=="DEBIT")
//    {
//        os<<"*DEBIT*"<<endl;
//        os<<"-> "<<transaction.initial_balance<<"  +  "<<transaction.amount<<"   Balance: "<<transaction.final_balance;
//    }

//    if((transaction.type)=="CREDIT")
//    {
//        os<<"*CREDIT*"<<endl;
//        os<<"-> "<<transaction.initial_balance<<"  -  "<<transaction.amount<<"   Balance: "<<transaction.final_balance;
//    }

//    if((transaction.type)=="FEES")
//    {
//        os<<"*FEES*"<<endl;
//        os<<"-> "<<transaction.initial_balance<<"  -  "<<transaction.amount<<"   Balance: "<<transaction.final_balance;
//    }

//    if((transaction.type)=="TRANSFER")
//    {
//        if(transaction.from_to==0)
//        {
//            os<<"*TRANSFER CREDIT*"<<endl;
//            os<<"-> "<<transaction.initial_balance<<"  -  "<<transaction.amount<<"   Balance: "<<transaction.final_balance;
//        }

//        if(transaction.from_to==1)
//        {
//            os<<"*TRANSFER DEBIT*"<<endl;
//            os<<"-> "<<transaction.initial_balance<<"  +  "<<transaction.amount<<"   Balance: "<<transaction.final_balance;
//        }
//    }


    default:
        break;
    }
    os<<"  *** Date: "<<transaction.date;

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
