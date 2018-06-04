#include "bank.h"

Bank::Bank(string name, unsigned int code)
    :code(code),
    name(name)

{}

Bank::Bank(const Bank &bank)
    :clients(bank.clients),
     accounts(bank.accounts),
     code(bank.code),
     name(bank.name)
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

    nr=to_string(clControl);
    aux=(nr.length()/sizeof(nr[0]));
    aux=7-aux;
    nr.insert(0,aux,'0');

    clControl++;

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
            client=find_client(code);
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

Client* Bank::find_client(const string& code)
{
    list<Client>::iterator it;
    for(it=clients.begin(); it!=clients.end(); it++)
    {
        if(it->find_code(code))
            return &*it;
    }
    cout<<"NOT FOUND"<<endl;
    return NULL;
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
        owner=find_client(owner_code);
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
        cout<<*aux;
        pause();
    }
    break;

    case '2':
    {
        Account* aux=new Student ("STUDENT");
        owner->add_account(aux);
        accounts.push_back(aux);
        cout<<*aux;
        pause();
    }
        break;

    case '3':
    {
        Account* aux=new Retired ("RETIRED");
        owner->add_account(aux);
        accounts.push_back(aux);
        cout<<*aux;
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
    float initial,final,amount;
    list<Account*>::iterator it;
    Transaction* transaction;

    for(it=accounts.begin(); it!=accounts.end();it++)
    {
        initial=(*(*it)).get_balance();
        (*(*it)).process_fee();
        final=(*(*it)).get_balance();
        amount=initial-final;
        transaction=new Fees(amount,"hoje",initial,final);
        (*(*it)).add_transaction(transaction);
    }
}

void Bank::list_accounts()
{
    //Account* acc;
    list<Account*>::iterator it;
    for(it=accounts.begin(); it!=accounts.end();it++)
    {
        cout<<*(*it);
    }
    pause();
}

Account* Bank::find_account()
{
    int option=0;

    while(option!=3)
    {
        //clr_scrn();
        cout<<"Search by:\n\n"<<"1- IBAN"<<endl<<"2- CLIENT CODE"<<endl<<"3- BACK\n: ";
        cin.ignore();
        cin>>option;

        switch(option)
        {
        case 1:
        {
            Account* acc;
            string iban;
            cout<<"IBAN: ";
            cin.ignore();
            getline(cin,iban);
            acc=find_account(iban);
            if(acc!=NULL)
                return acc;

            return NULL;
        }
            break;

        case 2:
        {
            unsigned int account_number;
            Client* client;
            string code;
            cout<<"Client Code: ";
            cin.ignore();
            getline(cin,code);
            client=find_client(code);
            if(client!=NULL)
            {
                client->print_accounts_number();
                cout<<"\nAccount number: ";
                cin>>account_number;
                return (client->fetch_account(account_number));
            }
            return NULL;
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

Account* Bank::find_account(const string& iban)
{
    list<Client>::iterator it;
    Account* acc;

    for(it=clients.begin(); it!=clients.end(); it++)
    {
        acc=it->fetch_account(iban);

        if(acc!=NULL)
            return acc;
    }

    return NULL;
}

Account* Bank::find_account(Client* client)
{

}

void Bank::debit()
{
    Account* acc;
    Transaction* transaction;
    float amount, initial,final;

    cout<<"*** DEPOSIT ***"<<endl;

    acc=find_account();
    if(acc!=NULL)
    {
        initial=acc->get_balance();
        cout<<"Amount: ";
        cin>>amount;
        final=acc->deposit(amount);
        transaction=new Debit(amount,"hoje",initial,final);
        acc->add_transaction(transaction);
    }
}

void Bank::credit()
{
    Account* acc;
    Transaction* transaction;
    float amount, initial,final;

    cout<<"*** WITHDRAW ***"<<endl;

    acc=find_account();
    if(acc!=NULL)
    {
        initial=acc->get_balance();
        cout<<"Amount: ";
        cin>>amount;
        final=acc->withdraw(amount);
        transaction=new Credit(amount,"hoje",initial,final);
        acc->add_transaction(transaction);
    }
}

void Bank::transfer()
{
    Account* acc1;
    Account* acc2;
    Transaction* transaction1;
    Transaction* transaction2;
    float amount, initial1, initial2, final1, final2;

    cout<<"*** TRANSFER ***"<<endl;
    cout<<"*** FROM ***"<<endl;
    acc1=find_account();
    cout<<"*** TO ***"<<endl;
    acc2=find_account();

    if(acc1!=NULL && acc2!=NULL)
    {
        initial1=acc1->get_balance();
        initial2=acc2->get_balance();
        cout<<"Amount: ";
        cin>>amount;
        final1=acc1->withdraw(amount);
        final2=acc2->withdraw(amount);
        transaction1=new Transfer(amount,"hoje",0,initial1,final1);
        transaction2=new Transfer(amount,"hoje",1,initial2,final2);
        acc1->add_transaction(transaction1);
        acc2->add_transaction(transaction1);
    }
}

void Bank::list_transactions()
{
    Account* acc;

    cout<<"*** TRANSACTIONS ***"<<endl;

    acc=find_account();
    if(acc!=NULL)
    {
        clr_scrn();
        cout<<*acc<<endl;
        cout<<"**************************************"<<endl;
        acc->print_transactions();
    }
}

Bank::~Bank()
{}
