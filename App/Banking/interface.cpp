#include "interface.h"

void main_menu()
{
    cout<<"0- SWITCH BANK"<<"\n\n\n";
    cout<<"1- ACCOUNTS"<<endl;
    cout<<"2- CLIENTS"<<endl;
    cout<<"3- TRANSACTIONS"<<endl;
    cout<<"\n4- QUIT"<<endl;
    cout<<"\n\n: ";
}

void client_menu()
{
    cout<<"CLIENTS"<<"\n\n\n";
    cout<<"1- NEW CLIENT"<<endl;
    cout<<"2- DELETE CLIENT"<<endl;
    cout<<"3- CHANGE CLIENT ADRESS"<<endl;
    cout<<"4- FIND CLIENT"<<endl;
    cout<<"5- LIST CLIENTS"<<endl;
    cout<<"\n6- <BACK>"<<endl;
}

void account_menu()
{
    cout<<"ACCOUNTS"<<"\n\n\n";
    cout<<"1- NEW ACCOUNT"<<endl;
    cout<<"2- DELETE ACCOUNT"<<endl;
    cout<<"3- BLOCK ACCOUNT"<<endl;
    cout<<"4- FIND ACCOUNT"<<endl;
    cout<<"5- LIST ACCOUNTS"<<endl;
    cout<<"6- PROCESS FEES"<<endl;
    cout<<"\n7- <BACK>"<<endl;
}

void transactions_menu()
{
    cout<<"TRANSACTIONS"<<"\n\n\n";
    cout<<"1- DEPOSIT"<<endl;
    cout<<"2- WITHDRAW"<<endl;
    cout<<"3- TRANSFER"<<endl;
    cout<<"4- LIST TRANSACTIONS"<<endl;
    cout<<"\n5- <BACK>"<<endl;
}

void clr_scrn()
{
    system("CLS");
}

void pause()
{
    system("pause");
}
