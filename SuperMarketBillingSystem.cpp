#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class Shopping
{
    private:
    int pcode;//product code
    float price;
    float discount;
    string pname;//product name
    public:
    void menu();
    void administrator();
    void customer();
    void add();
    void modify();
    void removep();
    void list();
    void dsiplay();
    void receipt();
};
void Shopping :: menu()
{
    int choice;
    string mail;
    string password; 
    m:
    cout<<"\t\t--------------------------------------------------------------------\t\t\n";
    cout<<"\t\t|                        Welcome to SUPERMARKET                    |\t\t\n";
    cout<<"\t\t--------------------------------------------------------------------\t\t\n";
    cout<<"\t\t                                Main Menu                           \t\t\n";
    cout<<"\t\t 1] Adminstrator\n";
    cout<<"\t\t 2] Customer\n";
    cout<<"\t\t 3] Exit\n";
    cout << "\t\t----------------------------------------------------------------------------\n";
    cout<<"\t\t Please Enter a Choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
       {
        cout<<"\n\t\t                      Administrator      \n";
        cout << "\t\t---------------------------------------------------------------------------\n";
        cout<<"\t\t Please Enter your Login Credentials :\n";
        cout<<"\t\t Email : ";
        cin>>mail;
        cout<<"\t\t Passwoed : ";
        cin>>password;
        cout<<endl;
        if(mail=="ABC@gmail.com" && password=="ABC.123")
        {
           cout<<"\t\tYou have logged in successfully.\n"; 
           administrator();
        }else
        {
            cout<<"\t\t Please enter your email/passord correctly.Credentials NOT MATCHED\n\n";
        }
       }
       break;
       case 2:
       {
         customer();
       }
       break;
       case 3:
       {
        exit(0);
       }
       break;
       default:
       cout<<"\t\t Please Enter a Valid Choice\n\n";
    }
    goto m;
}
void Shopping::administrator()
{
    int choice2;
    n:
    cout<<"\t\t                    ADMINISTRATOR MENU      \n";
    cout<<endl;
    cout<<"\t\t| 1]Add a Product     |\n\n";
    cout<<"\t\t| 2]Modify a Product  |\n\n";
    cout<<"\t\t| 3]Remove a Product  |\n\n";
    cout<<"\t\t| 4]Back to Main Menu |\n\n";
    cout<<"\t\t\tPlease Enter a Choice: ";
    cin>>choice2;
    cout<<endl;
    switch(choice2)
    {
        case 1:
        add();
        break;
        case 2:
        modify();
        break;
        case 3:
        removep();
        break;
        case 4:
        menu();
        break;
        default:
        cout<<"\t\tPlease Enter a valid Choice\n\n";
    }
    goto n;
}
void Shopping::customer()
{
    int choice;
    m:
    cout<<"\t\t\t CUSTOMER MENU\n\n";
    cout<<"\t\t 1] Buy a Product\n";
    cout<<"\t\t 2]Return to MENU\n";
    cout<<"\t\tPlease Enter a Choice: ";
    cin>>choice;
    cout<<endl;
    switch(choice)
    {
        case 1:
        receipt();
        break;
        case 2:
        menu();
        break;
        default:
        cout<<"\t\tYou have entered an invalid choice.\n\n";
        break;
    }
    goto m;
}
void Shopping:: add()
{
    fstream data;
    int c;
    int token=0;
    int d;
    int p;
    string n;
    m:
    cout<<"\t\t Enter Details of Product to be added\n\n ";
    cout<<"\t\tEnter product code: ";
    cin>>pcode;
    cout<<endl;
    cout<<"\t\tEnter product name: ";
    cin>>pname;
    cout << endl;
    cout<<"\t\tEnter product cost: ";
    cin>>price;
    cout << endl;
    cout<<"\t\tEnter Discount: ";
    cin>>discount;
    cout << endl;
    data.open("database.txt", ios::in);
    if(!data)
    {
        data.open("database.txt",ios::app | ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<endl;
        data.close();
    }
    else
    {
       data>>c>>n>>p>>d;
       while(!data.eof())
       {
       if(c==pcode)
       {
        token++;
       }
       data>>c>>n>>p>>d; 
       }
       data.close();
    if(token==1)
    {
        cout<<"\t\tproduct code already exits.\n";
        goto m;
    }else
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << discount << endl;
        data.close();
    }
    }
    cout<<"\t\t New Record Added Successfully!!\n\n";
}
void Shopping::modify()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;
    cout<<"\t\t Modify the record\n";
    cout<<"\t\t Product Code: ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
       cout<<"\t\tProduct doesn't exist.\n";
    }
    else
    {
        data1.open("database1.txt",ios::app | ios::out);
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\t\t Enter new Product code: ";
                cin >> c;
                cout << endl<< endl;
                cout << "\t\tEnter product name: ";
                cin >> n;
                cout << endl<< endl;
                cout << "\t\tEnter product cost: ";
                cin >> p;
                cout << endl<< endl;
                cout << "\t\tEnter Discount: ";
                cin >> d;
                cout << endl << endl;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<endl;
                cout<<"\t\t Record Modified Successfully!!\n\n";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<endl;
            }
            data>>pcode>>pname>>price>>discount;
        }
              data.close();
              data1.close();
              remove("database.txt");
              rename("database1.txt","database.txt");

              if(token==0)
              {
                cout<<"\t\t No such Record is Found!!"<<endl<<endl;
              }
    }
}

void Shopping::removep()
{
   fstream data,data1;
   int pkey;
   int token=0;
   cout<<"\t\t Delete Record \n";
   cout<<"\t\t Enter product Code: ";
   cin>>pkey;
   data.open("database.txt",ios::in);
   if(!data)
   {
    cout<<"\t\t File doesn't exist!!\n\n";
   }
   else
   {
     data1.open("database1.txt",ios::app | ios::out);
     data>>pcode>>pname>>price>>discount;
     while(!data.eof())
     {
        if(pcode==pkey)
        {
            cout<<"\t\t Product deleted Successfully!!\n\n";
            token++;
        }
        else
        {
            data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<endl;
        }
        data>>pcode>>pname>>price>>discount;
   }
   data.close();
   data1.close();
   remove("database.txt");
   rename("database1.txt","database.txt");
   if(token == 0)
   {
    cout<<"\t\t Record not Found!!\n\n";
   }
 }
}

void Shopping::list()
{
   fstream data;
   data.open("database.txt",ios::in);
   cout<<"\t\t ------------------------------------------------------------------\n";
   cout<<"\t\t ProdNo\t\tName\t\tPrice\n\n";
   cout<<"\t\t-------------------------------------------------------------------\n";
   data>>pcode>>pname>>price>>discount;
   while(!data.eof())
   {
    cout<<"\t\t"<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<endl;
    data>>pcode>>pname>>price>>discount;
   }
   data.close();
}

void Shopping::receipt()
{
    fstream data;
    int arrC[100];
    int arrQ[100];
    char choice;
    int c=0;
    float amount=0;
    float discount=0;
    float total=0;
    cout<<endl;
    cout<<"\t\t\t\t RECEIPT \n";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\t\t Database Empty!!!\n\n";
    }
    else
    {
        data.close();
        
        list();
        cout << "\t\t--------------------------------------------------------------------\t\t\n";
        cout << "\t\t|                        Please Place an Order!!                   |\t\t\n";
        cout << "\t\t--------------------------------------------------------------------\t\t\n";
        do
        {
            m:
            cout<<"\t\t Enter the Product Code: ";
            cin>>arrC[c];
            cout<<"\t\t Enter the Quantity : ";
            cin>>arrQ[c];
            cout<<"\n";
            for(int i=0;i<c;i++)
            {
                if(arrC[c]==arrC[i])
                {
                  cout<<"\t\t Duplicate Product Code. Please try again!";
                  goto m;
                }
            }
            c++;
            cout<<"\t\t Do you want to buy another products? If yes then enter y else enter n\n\t\t";
            cin>>choice;
        } while (choice=='y');
        
        cout<<"\t\t\t\t\t\t\t\t\t RECEIPT\n\n";
        cout<<"\t\tProduct No\tProduct Name\tProduct Quantity\tPrice\t\tAmount without discount\t\tTotal\n";
        for(int i=0;i<c;i++)
        {
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>discount;
            while(!data.eof())
            {
                if(pcode==arrC[i])
                {
                    amount=price*arrQ[i];
                    discount=amount-(amount*(discount/100));
                    total=total+discount;
                    cout<<endl;
                    cout<<"\t\t"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrQ[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t\t\t"<<discount<<endl;
                }
                data>>pcode>>pname>>price>>discount;
            }
            data.close();
        }
            cout<<"\t\t--------------------------------------------------------------------------------------------------------------------------\n";
            cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\tTotal Amount= " << total << endl;
    }
}
int main()
{
    Shopping s;
    s.menu();
    return 0;
}