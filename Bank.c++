#include<iostream>
#include<fstream>
#include<cstdlib>
#include <string>>

using namespace std;

class account_query
{
private:
    char account_number;
    string first_name;
    string last_name;
    float total_balance;
public:
    void read_data();
    void show_data();
    void write_rec();
    void read_rec();
    void search_rec();
    void edit_rec();
    void delete_rec();
};
void account_query::read_data()
{
    cout<<"***********Enter details of the person******************\n";
    cout<<"\nEnter Account Number: ";
    cin>>account_number;
    cout<<"Enter First Name: ";
    cin>>first_name;
    cout<<"Enter Last Name: ";
    cin>>last_name;
    cout<<"Enter Balance: ";
    cin>>total_balance;
    cout<<"\n";
}
void account_query::show_data()
{
    cout<<"Account Number: "<<account_number<<endl;
    cout<<"First Name: "<<first_name<<endl;
    cout<<"Last Name: "<<last_name<<endl;
    cout<<"Current Balance: Rs.  "<<total_balance<<endl;
    cout<<"-------------------------------"<<endl;
}
void account_query::write_rec()
{
    ofstream outfile;
    outfile.open("record.bank", ios::binary|ios::app);
    read_data();
    outfile.write(reinterpret_cast<char *>(this), sizeof(*this));
    outfile.close();
}
void account_query::read_rec()
{
    ifstream infile;
    infile.open("record.bank", ios::binary);
    if(!infile)
    {
        cout<<"Error in Opening! File Not Found!!"<<endl;
        return;
    }
    cout<<"\n ****Data from file**** \n";
    while(!infile.eof())
    {
        if(infile.read(reinterpret_cast<char*>(this), sizeof(*this))>0)
        {
            show_data();
        }
    }
    infile.close();
}
void account_query::search_rec()
{
    int n;
    ifstream infile;
    infile.open("record.bank", ios::binary);
    if(!infile)
    {
        cout<<"\nError in opening! File Not Found!!"<<endl;
        return;
    }
    infile.seekg(0,ios::end);
    int count = infile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n Enter Record Number to Search: ";
    cin>>n;
    infile.seekg((n-1)*sizeof(*this));
    infile.read(reinterpret_cast<char*>(this), sizeof(*this));
    show_data();
}
void account_query::edit_rec()
{
    int n;
    fstream iofile;
    iofile.open("record.bank", ios::in|ios::binary);
    if(!iofile)
    {
        cout<<"\nError in opening! File Not Found!!"<<endl;
        return;
    }
    iofile.seekg(0, ios::end);
    int count = iofile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n Enter Record Number to edit: ";
    cin>>n;
    iofile.seekg((n-1)*sizeof(*this));
    iofile.read(reinterpret_cast<char*>(this), sizeof(*this));
    cout<<"Record "<<n<<" has following data"<<endl;
    show_data();
    iofile.close();
    iofile.open("record.bank", ios::out|ios::in|ios::binary);
    iofile.seekp((n-1)*sizeof(*this));
    cout<<"\nEnter data to Modify "<<endl;
    read_data();
    iofile.write(reinterpret_cast<char*>(this), sizeof(*this));
}
void account_query::delete_rec()
{
    int n;
    ifstream infile;
    infile.open("record.bank", ios::binary);
    if(!infile)
    {
        cout<<"\nError in opening! File Not Found!!"<<endl;
        return;
    }
    infile.seekg(0,ios::end);
    int count = infile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n Enter Record Number to Delete: ";
    cin>>n;
    fstream refile;
    refile.open("tmpfile.bank", ios::out|ios::binary);
    infile.seekg(0);
    for(int i=0; i<count; i++)
    {
        infile.read(reinterpret_cast<char*>(this),sizeof(*this));
        if(i==(n-1))
            continue;
        refile.write(reinterpret_cast<char*>(this), sizeof(*this));
    }
    infile.close();
    refile.close();
    remove("record.bank");
    rename("refile.bank", "record.bank");
}
int main()
{
    account_query A;
    int ch;
    cout<<"*****************Account Information System****************"<<endl;
    while(true)
    {
        cout<<"Select one option below ";
        cout<<"\n 1.Add record to file \n";
        cout<<"\n 2.Show record from file \n";
        cout<<"\n 3.Search Record from file \n";
        cout<<"\n 4.Update Record \n";
        cout<<"\n 5.Delete Record \n";
        cout<<"\n 6.Quit \n";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"\n Write the record..... \n";
            A.write_rec();
            break;
        case 2:
            cout<<"\n Read the record..... \n";
            A.read_rec();
            break;
        case 3:
            cout<<"\n Search the record..... \n";
            A.search_rec();
            break;
        case 4:
            cout<<"\n Edit the record..... \n";
            A.edit_rec();
            break;
        case 5:
            cout<<"\n Delete the record..... \n";
            A.delete_rec();
            break;
        case 6:
            cout<<"\n Exit the record..... \n";
            exit(0);
            break;
        default:
            cout<<"\nEnter correct choice";
            exit(0);
        }
    }
    return 0;
}
