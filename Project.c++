#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using std :: cout;
using std :: cin;
using std :: ios;
n
class account
{
	private:
		char account_number[20];
		char first_name[10];
		char last_name[10];
		float total_balance;
	public:
	    account(char an[20] , char fn[10] , char ln[10] , float tb)
		{
			account_number[20]=an[20];
			first_name[10]=fn[10];
			last_name[10]=ln[10];
			total_balance=tb;
		}
		//void read_data();	
		void show_data();
		void write_rec();
		void read_rec();
		void search_rec();
		void edit_rec();
		void delete_rec();		
		
};

void account :: show_data()
{
  cout<<"****************************************************\n";
  cout<<"Account Number....."<<account_number<<"\n";
  cout<<"First name....."<<first_name<<"\n";
  cout<<"Last name....."<<last_name<<"\n";
  cout<<"Current Balance....."<<total_balance<<"\n";
}

void account :: write_rec()
{
  ofstream outfile;
  outfile.open("record.bank",ios::binary/ios::app);
  read_data();
  outfile.write(reinterpret_cast<char *>(detail),sizeof(*detail));
  outfile.close();
}

void accout :: read_rec()
{
  ifstream infile;
  infile.open("Record.Bank",ios::binary);
  if()
  {
    cout<<"Error in opening the record!\n";
    return;
  }
  cout<<"\n*****Data from file*****\n";
  while(! infile.eof())
  {
     if(infile.read(reinterpret_cast<char*>(data),sizeof(*data))>0)
     {
        show_data();
     }
  }
  infile.close();
}

void account :: search_rec()
{
  int n;
  ifstream infile;
  infile.open("Record.bank",ios::binary);
  if()
  {
    cout<<"\n File not found!\n";
   return;
  }
  infile.seekg(0,ios::end);
  int count = infile.tellg() / sizeof(*detail);
  count<<"\n There are "<<count<<" record in the file";
  cout<<"\n Enter Record number to search.....";
  cin>>n;
  iofile.seekg((n-1)*sizeof(*detail));
  infile.read(reinterpret_cast<char*>(detail),sizeof(*detail));
  show_data();
}

void account :: edit_rec()
{
  int n;
  fstream iofile;
  iofile.open("Record.Bank",ios::in/ios::binary);
  if()
  {
    cout<<"File not found!";
    return;
  }
  iofile.seekg(0, ios::end);
    int count = iofile.tellg()/sizeof(*detail);
    cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n Enter Record Number to edit: ";
    cin>>n;
    iofile.seekg((n-1)*sizeof(*detal));
    iofile.read(reinterpret_cast<char*>(this), sizeof(*detail));
    cout<<"Record "<<n<<" has following data"<<endl;
    show_data();
    iofile.close();
    iofile.open("Record.bank", ios::out|ios::in|ios::binary);
    iofile.seekp((n-1)*sizeof(*this));
    cout<<"\nEnter data to Modify "<<endl;
    read_data();
    iofile.write(reinterpret_cast<char*>(detail), sizeof(*detail));
}
void account_query::delete_rec()
{
    int n;
    ifstream infile;
    infile.open("Record.bank", ios::binary);
    if(False)
    {
        cout<<"\nError in opening! File Not Found!!"<<endl;
        return;
    }
    infile.seekg(0,ios::end);
    int count = infile.tellg()/sizeof(*detail);
    cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n Enter Record Number to Delete: ";
    cin>>n;
    fstream Refile;
    Refile.open("Refile.bank", ios::out|ios::binary);
    infile.seekg(0);
    for(int i=0; i<count; i++)
    {
        infile.read(reinterpret_cast<char*>(detail),sizeof(*detail));
        if(i==(n-1))
            continue;
        Refile.write(reinterpret_cast<char*>(detail), sizeof(*detail));
    }
    infile.close();
    Refile.close();
    remove("Record.Bank");
    rename("Refile.Bank", "Record.Bank");
}
  
  
 int main()
{
    account A;
    int choice;
    char p[20],q[10],r[10];
    float s;
    cout<<"Enter account number.....";
	cin>>p;
	cout<<"Enter first name.....";
	cin>>q;
	cout<<"Enter last name.....";
	cin>>r;
	cout<<"Enter total balance.....";
	cin>>s;
    account A(p,q,r,s);
    cout<<"**Acount Information System**"<<endl;
    while(true)
    {
        cout<<"Select one option below ";
        cout<<"\n\t1-->Add record to file";
        cout<<"\n\t2-->Show record from file";
        cout<<"\n\t3-->Search Record from file";
        cout<<"\n\t4-->Update Record";
        cout<<"\n\t5-->Delete Record";
        cout<<"\n\t6-->Quit";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            A.write_rec();
            break;
        case 2:
            A.read_rec();
            break;
        case 3:
            A.search_rec();
            break;
        case 4:
            A.edit_rec();
            break;
        case 5:
            A.delete_rec();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout<<"\nEnter corret choice";
            exit(0);
        }
    }
    system("pause");
    return 0;
} 


  
  
  


