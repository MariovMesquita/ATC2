#include "bank.h"

Bank::Bank(string name, unsigned int code)
    :name(name),
     code(code)
{}

Bank::Bank(const Bank &bank)
    :clients(bank.clients),
     accounts(bank.accounts),
     name(bank.name),
     code(bank.code)
{}

Bank Bank::operator =(const Bank& bank)
{
    Bank New;
    New.clients=bank.clients;
    New.accounts=bank.accounts;
    return New;
}

ostream &operator << (ostream& os, const Bank& bank)
{
    os<<bank.name<<endl<<bank.code<<endl;

    return os;
}

string Bank::client_nr()
{
    string nr;
    int aux;

    nr=to_string(g_clControl);
    aux=(nr.length()/sizeof(nr[0]));
    aux=7-aux;
    nr.insert(0,aux,'0');

    g_clControl++;

    return nr;
}

void Bank::new_client()
{
    string name, cl_number, birthday, adress, zip;
    int nif;

    cout<<"Name: ";
    cin.ignore();
    getline(cin,name);//name
    cl_number=client_nr();//client number
    cout<<"Birth date(dd/mm/yyyy): ";
    getline(cin,birthday);//birth date
    cout<<"NIF: ";
    cin>>nif;//nif
    cout<<"Adress: ";
    cin.ignore();
    getline(cin,adress);//adress
    cout<<"ZIP-code: ";
    getline(cin, zip);//zip-code

    Client new_cl(name,cl_number,birthday,nif,adress,zip);
    clients.push_back(new_cl);
}

void Bank::list_clients()
{
    list<Client>::const_iterator it;

    for(it=clients.begin(); it!=clients.end(); it++)
    {
        cout<<*it;
    }
}

Client* Bank::find_client()
{
    int option=0;

    while(option!=3)
    {
        clr_scrn();
        cout<<"Search by:\n\n"<<"1- NAME"<<endl<<"2- CODE"<<endl<<"3- BACK\n: ";
        cin.ignore();
        cin>>option;

        switch(option)
        {
        case 1:
        {
            cout<<"Name: ";
        }
            break;

        case 2:
        {
            Client* client;
            string code;
            cout<<"Code: ";
            cin.ignore();
            getline(cin,code);
            client=find_client_code(code);
            if(client!=NULL)
                return client;
            pause();
        }
            break;

        case 3:
            pause();
            break;

        default:
            break;
        }
    }
}

Client* Bank::find_client_code(const string& code)
{

    list<Client>::iterator it;
    for(it=clients.begin(); it!=clients.end(); it++)
    {
        if(it->find_code(code))
            return &*it;
    }
    cout<<"NOT FOUND"<<endl;
}

void Bank::new_account()
{
    Client* owner;
    char opt;
    string owner_code;
    do
    {
        cout<<"Owner code: ";
        cin.ignore();
        getline(cin,owner_code);
        owner=find_client_code(owner_code);
        if(owner==NULL)                     //não funciona
        {
            list_clients();
            cout<<"Try again? (y/n)\n: ";
            cin.ignore();
            cin>>opt;
        }
    }while(owner==NULL && opt!='y');

    cout<<"Account type:"<<endl<<"1- Normal"<<endl<<"2- Student"<<endl<<"3- Retired\n: ";
    cin>>opt;
    cin.clear();
    cin.ignore( numeric_limits <streamsize> ::max(), '\n' );
    cout<<opt;
    switch(opt)
    {
    case '1':
    {
        Account* aux=new Normal ("NORMAL");
        owner->add_account(aux);
        accounts.push_back(aux);
        cout<<aux;
        pause();
    }
    break;

    case '2':
    {
        Account* aux=new Student ("STUDENT");
        //cout<<"\n\n*** STUDENT ***"<<endl;
        //Student acc("STUDENT");
        //aux=&acc;
        owner->add_account(aux);
        accounts.push_back(aux);
        cout<<aux;
        //delete aux;
        pause();
    }
        break;

    case '3':
    {
        Account* aux=new Retired ("RETIRED");
        owner->add_account(aux);
        accounts.push_back(aux);
        cout<<aux;
        pause();
    }
        break;

    default:
        cout<<"Invalid option!";
        break;

    }
}

void Bank::process_fees()
{
    list<Account*> ::iterator it;
    for(it=accounts.begin(); it!=accounts.end();it++)
    {
        cout<<*it;
    }
}

void Bank::list_accounts()
{
    //Account* acc;
    list<Account*> ::iterator it;
    for(it=accounts.begin(); it!=accounts.end();it++)
    {
        cout<<it;
    }
}

Bank::~Bank()
{}
