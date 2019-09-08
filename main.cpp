
AAAAAAAAAAAAAAAAMMMMMMMMMMMMMMMMMMMMMMMMMIIIIIIIIIIIIIIIIIIITTTTTTTTTTTTTTTTTTTTTTTT









#include<iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<fstream>           // i/o operations on files
#include<stdlib.h>
using namespace std;
int i,n;
ifstream fin;                   // input operations on files
ofstream fout;                  // output operations on files
fstream fio;
void disp();
class shop
{
        char name[20],pass[10];
        float price; int quantity;

    public:
        void get();
        void get2();
        void show();
        int stock(char nm[30]);
        void withd(int qty);
        void refil(int qty);
}st;

void shop::withd(int qty)
{
	if(quantity>=qty)
	{
		quantity-=qty;
		cout<<"\n\nStock updated.\n";
		cout<<"\n\nTotal price to be paid:"<<price*qty;
    }
	else
	   cout<<"\n\nInsufficient stock";
    _getch();
}

void shop::get()
{
	cin>>name>>price>>quantity;
}

void shop::refil(int qty)
{
    quantity+=qty;
    cout<<"\n\nStock updated.";
    _getch();
}

int shop::stock(char nm[30])
{
	if(strcmp(nm,name)==0)
	 return 0;
	else
	return 1;
}

void addnew()
{
    //system("cls");
	//disp();
	//_getch();
	//system("cls");
    int counter=0;
	cout<<"\nEnter the Number of Products that you wish to add: ";
    cin>>n;


    if (n!=0)
    {
        int j,l,sum=0;
        fout.open("inventory",ios::binary|ios::app);
        for(i=0;i<n;i++)
        {
            cout<<"\n\nInput the name, price and the quantity of item respectively\n\n";
            st.get();
            fout.write((char*)&st,sizeof(st));
            cout<<"\n\nNew product is added in Inventory";
            cin.get();
        }
    }
    cout<<"\n\nInventory Updated!!";
    fout.close();
    cin.get();
    system("cls");
    disp();
}

void shop::show()
{

	cout<<"\n"<<name<<"\t\t\t"<<quantity<<"\t\t\t"<<price;
}

void shop::get2()
{
	cin>>name>>quantity;
}

void disp()
{
	int i=1;
	cout<<"\n==================================================================";
	cout<<"\n\n======================\tTHE INVENTORY\t=======================";
	cout<<"\n\n==================================================================\n";
	cout<<"\n\nPRODUCT ID\tPRODUCT\tSTOCK AVAILABLE\t\t\t PRICE";
	cout<<"\n\n============================================================\n";
	 fin.open("inventory",ios::binary);
     while(!fin.eof())
     {
        fin.read((char*)&st,sizeof(st));
        if(!fin.eof())
        {
            if(fin.tellg()<0)
            {
                i=0;
                break;
            }
            st.show();
        }
     }
     if(i==0)
     {	cout<<"\n\n\t\t\t!!Empty record room!!";
        _getch();
     }
     fin.close();

}

void withdraw()
{
	system("cls");
	char temp[100];int qty;
	int i=0;
	long pos=0;
	disp();
	cout<<"\n\nEnter the product's name \n"<<endl;
	cin>>temp;
	cout<<"\n\nEnter quantity: \n"<<endl;
	cin>>qty;
	fio.open("inventory",ios::binary|ios::out|ios::in);
     while(fio)
     {
	    pos=fio.tellp();
	    fio.read((char*)&st,sizeof(st));
	    if(st.stock(temp)==0)
	    {

		  st.withd(qty);
		  fio.seekp(pos);
		  fio.write((char*)&st,sizeof(st));
		  i++;break;
	    }
     }


     if(i!=1)
       cout<<"\n\n!!Record not found!!";
     fio.close();
    cin.get();
    system("cls");
	 disp();
	_getch();
}

void refill()
{
	system("cls");
	char temp[100];int qty;
	int i=0;
	long pos=0;
	disp();
	cout<<"\n\nEnter the products name \n"<<endl;
	cin>>temp;
	cout<<"\n\nEnter quantity: \n"<<endl;
	cin>>qty;
	fio.open("inventory",ios::binary|ios::out|ios::in);
     while(fio)
     {
	    pos=fio.tellp();
	    fio.read((char*)&st,sizeof(st));
	    if(st.stock(temp)==0)
	    {

		  st.refil(qty);
		  fio.seekp(pos);
		  fio.write((char*)&st,sizeof(st));
		  i++;break;
	    }
     }
     if(i!=1)
       cout<<"\n\n!!Record not found!!";
     fio.close();
    system("cls");
    cin.get();
	 disp(); cin.get();


}

void remove()
{
	system("cls");
	 int i=0;
     char temp[30];
     cout<<"\n\t\t\t\tDelete Record";
     cout<<"\n\nEnter the name of the product:";
     cin>>temp;
     fout.open("temp.dat",ios::binary);
     fin.open("inventory",ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&st,sizeof(st));
	  if(!fin.eof())
	    if(st.stock(temp)==0)
	    {
		  st.show();
		  cout<<"\n\n\t\tRecord deleted";
		  i++;
	    }
	    else
		  fout.write((char*)&st,sizeof(st));
     }
     if(i==0)
       cout<<"\n\n!!Record not found!!";
     fin.close();
     fout.close();
     remove("inventory");
     rename("temp.dat","inventory");
}

int main()
{
	char pass[10],pass2;
	pass2='dealer';
	int i,j;
	cout<<"\n\n|================= WELCOME TO SUPER MARKET =================|";
	//system("cls");
	cout<<"\n\n\t\t   STORE MANAGEMENT SYSTEM\n";
	cout<<"=============================================================";
	cout<<"\n\n\t\t   1. Owner Login\n\n\t\t   2. Customer Section\n\n\t\t   3. Employee Menu";
	cout<<"\n\n=============================================================\n";
	cout<<"\n\nEnter Your Choice:";
	cin>>j;
	if(j==1)
	{

        system("cls");
        cout<<"\n\n\tEnter the password letter by letter: ";
        //cin>>pass;
        for(int z=0;z<6;z++)
        {
            pass[z]=_getch();
            system("cls");
            cout<<"\n\n\tEnter the password letter by letter: ";
            for(i=1;i<=(z+1);i++)
            {
                cout<<"*";
            }
        }
        if(strcmp(pass,"dealer")==0)
        {
            system("cls");
            dealermenu:
            system("cls");
            cout<<"=================================================================";
            cout<<"\n\n\t\t\t    OWNER SECTION\n1. Add new product\n2. Display stock\n3. Refill\n4. Remove an item\n5. Exit:";
            cout<<"\n\n\n==========================END OF MENU=============================";
            cout<<"\n\n Enter your Choice :\t";
            cin>>i;
            if(i==1)
            {
                addnew();
                _getch();
                goto dealermenu;
            }

            else if(i==2)
            {
                system("cls");
                disp();
                _getch();
                goto dealermenu;
            }
            else if(i==3)
            {
                refill();
                goto dealermenu;
            }
            else if(i==4)
            {
                remove();
                _getch();
                goto dealermenu;
            }
            else
            {
                system("cls");
                cout<<"\n\n\n\t\t\tBrought To You By code-projects.org";
                _getch();
                exit(0);
            }
        }
        else
        {
            cout<<"\n\nAccess Denied! Authorised Persons Only.\n\n";
            _getch();
            exit(0);
        }
	}
    if(j==2)
	{
		custmenu:
        system("cls");
        cout<<"=================================================================";
        cout<<"\n\n\t\t\t    CUSTOMER SECTION\n1. Purchase\n2. Display stock\n3. Exit:";
        cout<<"\n\n\n==========================END OF MENU=============================";
        cout<<"\n\n Enter your Choice :\t";
        cin>>i;
        if (i==1)
        {
            withdraw();_getch();goto custmenu;
        }
        else if(i==2)
        {
            system("cls");
            disp();
            _getch();
            goto custmenu;
        }

        else
        {
            system("cls");
            cout<<"\n\n\n\t\t\tBrought To You By code-projects.org";
            _getch();
            exit(0);
        }
    }
    _getch();
}

