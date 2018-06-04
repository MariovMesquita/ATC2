#include <iostream>
#include <vector>
//#include "interface.h"
#include "bank.h"


using namespace std;

void print_banks(const vector<Bank *>& banks)
{
    vector<Bank*>::const_iterator it;
    int index;

    for(it=banks.begin(); it!=banks.end(); it++)
    {
        index=distance(banks.begin(), it);
        cout<<"BANK "<<index<<endl;
        cout<<**it;
    }
}


int main()
{
    size_t option=0;
    vector<Bank*> banks;
    Bank bank1("bpn",123);
    Bank bank2("cgd",456);

    banks.push_back(&bank1);
    banks.push_back(&bank2);

    Bank *mybank=banks[0];

    while(option!=4)
    {
        clr_scrn();
        cout<<"BANK: "<<mybank->name<<endl;
        main_menu();
        //cin.ignore();
        //option=cin.get();
        cin>>option;

        switch(option)
        {
        case 0://switch bank
            size_t bank_opt;
            print_banks(banks);
            cout<<"\n\nSelect a bank: ";
            cin>>bank_opt;
            mybank=banks[bank_opt];
            pause();
            break;
        case 1://accounts
            while(option!=7)
            {
                clr_scrn();
                account_menu();
                cin>>option;

                switch(option)
                {
                case 1://new acc
                    mybank->new_account();
                    break;
                case 2://delete acc
                    break;
                case 3://block acc
                    break;
                case 4://find acc
                {
                    Account* account=(mybank->find_account());
                    if(account!=NULL)
                        cout<<*account;
                    pause();
                }
                    break;
                case 5://list acc
                    mybank->list_accounts();
                    break;
                case 6://process fee
                    mybank->process_fees();

                    pause();
                    break;
                case 7://exit
                    break;
                default:
                    if(option!=0)
                    {
                        cout<<"Invalid option. Please try again."<<endl;
                    }
                    pause();
                    break;

                }
            }
            pause();
            break;
        case 2://clients
            while(option!=6)
            {
                clr_scrn();
                client_menu();
                cin>>option;

                switch(option)
                {
                case 1://new cl
                    mybank->new_client();
                    break;
                case 2://delete cl
                    break;
                case 3://edit cl ***** mudar o zip code tambem
                {
                    string address;
                    Client* client=mybank->find_client();
                    cout<<"New adress: ";
                    getline(cin,address);
                    client->change_add(address);
                    pause();
                }

                    break;
                case 4://find cl
                {
                    Client* client=mybank->find_client();
                    if(client!=NULL)
                        cout<<*client;
                    pause();
                }
                    break;
                case 5://list cl
                {
                    mybank->list_clients();
                    pause();
                }
                    break;
                case 6://exit
                    break;
                default:
                    if(option!=0)
                    {
                        cout<<"Invalid option. Please try again."<<endl;
                    }
                    pause();
                    break;

                }
            }
            pause();
            break;
        case 3:
            while(option!=5)
            {
                clr_scrn();
                transactions_menu();
                cin>>option;

                switch(option)
                {
                case 1://deposit
                    mybank->debit();
                    break;
                case 2://withdraw
                    mybank->credit();
                    break;
                case 3://transfer
                    mybank->transfer();
                    break;
                case 4://list
                    mybank->list_transactions();
                    pause();
                    break;
                case 5://exit
                    pause();
                    break;
                default:
                    if(option!=0)
                    {
                        cout<<"Invalid option. Please try again."<<endl;
                    }
                    pause();
                    break;

                }
            }
            break;
        case 4:
            break;
        default:
            if(option!=0)
            {
                cout<<"Invalid option. Please try again."<<endl;
            }
            break;

        }
    }

    return 0;
}

