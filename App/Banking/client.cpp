#include "client.h"
#include <ctime>


Client::Client(string name, string client_code, string birth_date, unsigned int nif, string address, string zip_code)
    :name(name),
    client_code(client_code),
    birth_date(birth_date),
    nif(nif),
    address(address),
    zip_code(zip_code)
{}


Client::Client(const Client &client)
    :name(client.name),
    client_code(client.client_code),
    birth_date(client.birth_date),
    nif(client.nif),
    address(client.address),
    zip_code(client.zip_code)
{}

bool Client::find_code(string code)
{
    if(code==client_code)
        return true;

    return false;
}

int Client::age()
{
    time_t t=time(0);
    tm* now=localtime(&t);

    int year_now=now->tm_year + 1900;
    int month_now=now->tm_mon+1;
    int day_now=now->tm_mday;

    string::iterator it;
    it=birth_date.begin();
    string s_year=birth_date.substr(6,4);
    string s_month=birth_date.substr(3,2);
    string s_day=birth_date.substr(0,2);
    int year=stoi(s_year);
    int month=stoi(s_month);
    int day=stoi(s_day);

    if((month_now)<month)
        return ((year_now-1)-year);

    if((month_now)>month)
        return (year_now-year);

    if(month_now==month)
    {
        if(day_now<day)
            return ((year_now-1)-year);
        else
            return (year_now-year);
    }
}

void Client::change_add(string address)
{
    this->address=address;
}

void Client::add_account(Account *account)
{
    accounts.push_back(account);
}

ostream& operator << (ostream& os, const Client &client)
{
    os<<"Client nr "<<client.client_code<<endl;
    os<<"Name: "<<client.name<<endl;
    os<<"Birth date: "<<client.birth_date<<endl;
    os<<"NIF: "<<client.nif<<endl;
    os<<"Adress: "<<client.address<<endl;
    os<<"Zip code: "<<client.zip_code<<endl;

    return os;
}

Client::~Client()
{

}
