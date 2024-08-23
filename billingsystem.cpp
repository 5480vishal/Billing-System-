#include<iostream>  
#include<fstream>  
#include<stdlib.h>  
#include "vishal.h"
using namespace std;  
class Billsystem  
{  
    char Itemname[50][50];  
  
public:  
    int totalitems;  
    float Quantity[5];  
    float price[5];  
    int FinalPrice[5];  
    int Intialtotal[5];  
    void input();  
    void output();  
};  
class TAX:public Billsystem  
{  
    float tax;  
public:  
    void Taxcalculation();  
    void outputs();  
    void Totalprice();  
};  
  
//**********************  
//      INPUT FUNCTION  
//**********************  
  
void Billsystem::input()  
{  
    system("CLS");  
    cout<<"\nEnter number of items= ";  
    cin>>totalitems;  
  
    for(int i=0; i<totalitems; i++)  
    {  
        cout<<"\nEnter name of item "<<i+1<<": ";  
        cin>>Itemname[i];  
        cout<<"Enter quantity: ";  
        cin>>Quantity[i];  
        cout<<"Enter price of item "<<i+1<<": ";  
        cin>>price[i];  
        Intialtotal[i]=Quantity[i]*price[i];  
    }  
}  
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *   
//     OUTPUT FUNCTION  
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *   
void Billsystem::output()  
{  
    int a;  
  
    ifstream infile("COUNT.TXT");  
    infile>>a;  
  
    ofstream outfile("COUNT.TXT");  
    a+=1;  
    outfile<<a;  
    outfile.close();  
  
    {ofstream outfile("HIS.TXT", ios::app);  
    outfile<<endl<<"Bill No.: "<<a<<endl;  
    outfile<<"------------------------------------------------------------------------"<<endl;  
cout<<"\n";  
    cout<<"Name of Item\tQuantity   Price  Total Price\n";  
    for(int i=0;i<totalitems;i++)  
    {  
        outfile<<"Name: "<<Itemname[i]<<"\tQuantity: "<<Quantity[i]<<"\tPrice: "<<Intialtotal[i]<<endl;  
        cout<<Itemname[i]<<"\t\t"<<Quantity[i]<<"\t   "<<price[i]<<"\t   "<< Intialtotal[i]<<'\n';  
    }  
  
    outfile<<"------------------------------------------------------------------------"<<endl;  
    outfile.close();  
    }  
}  
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *   
//     TAX CALCULATION  
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *   
void TAX::Taxcalculation()  
{  
    input();  
    for(int i=0;i<totalitems;i++)  
    {  
        if(price[i]<=100.00)  
        {  
            FinalPrice[i]=Intialtotal[i]+(0.03*Intialtotal[i]);  
        }  
        else  
        {  
            FinalPrice[i]=Intialtotal[i]+(0.1*Intialtotal[i]);  
        }  
    }  
}  
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *   
//      TAX OUTPUTS  
//*  * * * * * * * * * * * * * * * * * * * * ** * * * * * * * * * * * * * * * * * * * * * * * * *    
void TAX::outputs()  
{  
    output();  
  
    float cash=0,quantity=0,Sum=0,initialsum;  
  
    for(int i=0;i<totalitems;i++)  
    {  
           initialsum+=Intialtotal[i];  
           Sum+=FinalPrice[i];  
           quantity+=Quantity[i];  
    }  
    cout<<"\nTotal:";  
    cout<<"\n------------------------------------------------------------------------------";  
    cout<<"\tQuantity= "<<quantity<<"\t Totalprice = "<<initialsum<<"\tWith TAX = "<<Sum;  
    cout<<"\n------------------------------------------------------------------------------";  
  
pay:  
    
    cout<<"\n\n\t\t\t * * * * PAYMENT SUMMARY * * * * \n";  
    cout<<"\n\t\t\tTotal cash given: ";  
    cin>>cash;  
  
    if(cash>=Sum)  
        cout<<"\n\t\t\tTotal cash repaid: "<<cash-Sum<<'\n';  
          
    else  
    {   cout<<"\n\t\t\tCash given is less than total amount!!!";  
  
    goto pay;  
    }  
}  
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *   
//      PROTECTION PASSWORD  
//* * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *   
    
int main()  
{  
    system("color 9C");
    TAX object;  
    char option, ch;  
    ifstream fin;  
    char p1,p2,p3;  
    star: 
    cout<<"\n\n\n\n\n\n\t\t\tENTER THE 3 character PASSWORD: \t";  

  
    cin>>p1; 
    cout<<"\n\t\t\t\t\t\t\t\t";  
    cout<<"*";  
    cin>>p2;  
    cout<<"*";  
    cin>>p3;  
    cout<<"*\n\n\t\t\t";  
      
  
    if ((p1=='c'||p1=='C')&&(p2=='i'||p2=='I')&&(p3=='d'||p3=='D'))  {
     
     do{  
start:  
    system("PAUSE");  
    system("CLS");  
    welcome();  
     cout<<"\n\nEnter your choice: ";  
     cin>>option;  
     switch(option)  
     {  
     case'1':  
         object.Taxcalculation();  
  
         object.outputs();  
         goto start;  
     case'2':  
  
         fin.open("HIS.TXT", ios::in);  
         while(fin.get(ch))  
         {  
             cout<<ch;  
         }  
         fin.close();  
  
         goto start;  
     case'3':  
         goto end;  
     default:  
         cout<<"\a";  
     }  
  
     }while(option!=3);  
    }  
    else {
        cout<<"Wrong password try once more";  
        cout<<"\n\n\t\t\t";
        system("pause");
        system("CLS");
     goto star;
    }
     end:
     end();
    return 0;  
}