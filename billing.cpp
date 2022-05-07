#include<iostream>
#include<windows.h>
#include<fstream>
using namespace std;
class shopping
{
    private:
    int pcode;
    float price;
    float dis;
    string name;
    public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};
void shopping ::menu()
{
    char choice;
    string user_name;
    string password;
    string username1,password1;
    cout<<"\t\t\t\t______________________________________________ \n";
    cout<<"\t\t\t\t                                               \n";
    cout<<"\t\t\t\t            SUPER MARKET MENU                  \n";
    cout<<"\t\t\t\t                                               \n";
    cout<<"\t\t\t\t______________________________________________ \n";
    cout<<"\t\t\t\t                                               \n";
    cout<<"\t\t\t\t 1 Administrator - \n";
    cout<<"\t\t\t\t                   \n";
    cout<<"\t\t\t\t 2 Buyer -         \n";
    cout<<"\t\t\t\t                   \n";
    cout<<"\t\t\t\t 3 Exit -          \n";
    cout<<"\t\t\t\t                   \n";
    cout<<"Please select";
    cin>>choice;
    switch(choice)
    {
        case '1':
        cout<<"\t\t\t\t Please Sign Up\n";
        cout<<"\t\t\t\t Enter Username \n";
        cin>>user_name;
        cout<<"\t\t\t\t Enter password \n";
        cin>>password;
        cout<<"\n \n \t \t Your id is creating please wait";
        for(int i=0;i<4;i++)
        {
            cout<<".";
            Sleep(1000);
        }
        cout<<"\n \n \t \t Your id is created successfully"<<endl;
        system("CLS");
        cout<<"Super Market billing system";
        cout<<"\n \n \t \t LOGIN"<<endl;
        cout<<"Username:";
        cin>>username1;
        cout<<"Password:";
        cin>>password1;
        if(username1==user_name && password1==password)
        {
            administrator();
        }
        else
        {
            cout<<"Invalid email/password";
        }
        break;
        case '2':
        {
            buyer();
        }
        break;
        case '3':
        {
            exit(0);
        }
        default:
        {
            cout<<"Please select from the given options.";
        }
    }
}
void shopping ::administrator()
{  
    char choice;
    while(1)
    {
        cout<<"\t\t\t\t Administrator menu \n";
        cout<<"\t\t\t\t_____________________\n";
        cout<<"\t\t\t\t 1 Add the product_____ \n";
        cout<<"\t\t\t\t_____________________\n";
        cout<<"\t\t\t\t 2 Modify the product_____ \n";
        cout<<"\t\t\t\t_____________________\n";
        cout<<"\t\t\t\t 3 Delete the product_____ \n";
        cout<<"\t\t\t\t_____________________\n";
        cout<<"\t\t\t\t 4  Back to the menu_____ \n";

        cout<<"\t\t\t\t Please enter your choice \n";
        cin>>choice;
        switch(choice)
        {
            case '1':
            add();
            break;
            case '2':
            edit();
            break;
            case '3':
            rem();
            break;
            case '4':
            menu();
            break;
            default:
            cout<<"Invalid choice::"; 
        }
    }
}
void shopping ::buyer()
{

    char choice;
    cout<<"\t\t\t\t Buyer \n";
    cout<<"\t\t\t\t_____________________\n";
    cout<<"\t\t\t\t 1 Buy Product";
    cout<<"\t\t\t\t                     \n";
    cout<<"\t\t\t\t 2 Go Back";
    cout<<"\t\t\t\t Enter Your choice";
    cin>>choice;
    switch(choice)
    {
        case '1':
        receipt();
        break;
        case '2':
        menu();
        break;
        default:
        cout<<"Invalid choice";
    }
}
void shopping::add()
{   
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;
    cout<<"\t\t\t\t Add new product";
    cout<<"\t\t\t\t Product code of new product";
    cin>>pcode;
    cout<<"\t\t\t\t Name of the product";
    cin>>name;
    cout<<"\t\t\t\t Price of the product";
    cin>>price;
    cout<<"\t\t\t\t Discount on Product";
    cin>>dis;
    data.open("database.txt",ios::in);
    if(!data)
    {
        data.open("database.txt",ios::app| ios::out);
        data<<" "<<pcode<<" "<<name<<" "<<price<<" "<<dis; 
        data<<"\n";
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
        goto m;
    }
    else
    {
        data.open("database.txt",ios::app| ios::out);
        data<<" "<<pcode<<" "<<name<<" "<<price<<" "<<dis; 
        //data<<"\n";//
        data.close();    
    }
}
    cout<<"Record inserted";
}
void shopping::edit()
{
    fstream data,data1;
    int pkey;
    int token;
    int c;
    float p;
    float d;
    string n;

    cout<<"\t\t\t\t Modify the record";
    cout<<"\t\t\t\t product code";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\t\t\t\t File doesn't exixts";    
    }
    else
    {
        data1.open("database1.txt",ios::app| ios::out);
        data>>pcode>>name>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\t\t\t\t Product new code";
                cin>>c; 
                cout<<"\t\t\t\t Name of the product";   
                cin>>n;
                cout<<"\t\t\t\t Price!";
                cin>>p;
                cout<<"\t\t\t\t Discount";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<" ";
                cout<<"\t\t\t\t Record edited";

            }
            else
            {
                data<<" "<<pcode<<" "<<name<<" "<<price<<" "<<dis<<" ";    
            }
            data>>pcode>>name>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0)
        {
            cout<<"\t\t\t\t Record not found sorry!";   
        }
    }
}
void shopping::rem()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\t\t\t\t Delete product"; 
    cout<<"\t\t\t\t Product code:"; 
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"File doesn't exists";
    }
    else
    {
        data1.open("database1.txt",ios::app| ios::out);
        data>>pcode>>name>>price>>dis;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\t\t\t\t Product deleted succesfully";  
                token++;  
            }
            else
            {
                data1<<" "<<pcode<<" "<<name<<" "<<price<<" "<<dis<<" ";    
            }
            data>>pcode>>name>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0)
        {
            cout<<"\t\t\t\t Record not found!!";     
        }
    }
}
void shopping::list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\t\t\t\t ________________________";
    cout<<"ProNo\t\t Name \t\t Price";
    cout<<"\t\t\t\t ________________________";
    data>>pcode>>name>>price>>dis;
    while(!data.eof())
    {
        cout<<"pcode\t\tname\t\tprice\n";   
        data>>pcode>>name>>price>>dis;
    }
    data.close();
}
void shopping::receipt()
{
    m:
    fstream data;
    int arr[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;
    cout<<"\t\t\t\tRECEIPT";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\t\t\t\t Empty database";    
    }
    else
    {
        data.close();
        list();
        cout<<"\n________________________________";
        cout<<"\n                                ";
        cout<<"\n        Please Place the order        ";
        cout<<"\n                                  ";
        cout<<"\n________________________________";
        do
        {
            cout<<"\n Enter Product code";
            cin>>arr[c];   
            cout<<"\n Enter the product quantity"; 
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {
                if(arr[c]==arr[i])
                {
                    cout<<"Duplicate product code.Please try again";
                }
            }
            c++;
            cout<<"Do you want to buy another product ? if yes then press y else no.";
            cin>>choice;
        }
        while(choice=='y');
        cout<<"\n\n\t\t_____________________________RECEIPT__________________\n";
        cout<<"\nProuct no.\t product Name \t product quantity\t price\tAmount with discount";
        for(int i=0;i<c;i++)
        {
            data.open("database.txt",ios::in);
            data>>pcode>>name>>price>>dis;
            while(!data.eof())
            {
                if(pcode==arr[i])
                {
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                }
                data>>pcode>>name>>price>>dis;
            }
        }
        data.close();
    }
    cout<<"\n\n\t\t_______________________________________________\n";
    cout<<"\n Total amount:"<<total;
}
int main()
{
    shopping s;
    s.menu();

}