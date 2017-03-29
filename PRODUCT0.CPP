#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<string.h>
#include<dos.h>
#include<graphics.h>
#include<time.h>
class skrill
{
int crap;
public:
void count1()
{ofstream f("count.txt",ios::out);
cin>>crap;
f<<crap;
f.close();
}
void count2();

}ex;


void skrill::count2()
{ifstream g("count.txt",ios::in);
while(!g.eof())
{g>>crap;
}
cout<<crap;
g.close();
}







class product
{
   int pno;                //product number
   char name[50];
   float price,qty,tax,discount;

  public:

       void createproduct()
       {
	 cout<<"\n\t Please Enter the Product Number of the Product: ";
	 cin>>pno;
	 cout<<"\n Please Enter the name of the Product:";
	 gets(name);
	 cout<<"\n\t Enter the Price of the Product:";
	 cin>>price;
	 cout<<"\n\t Enter Count:";
	 ex.count1();
       }
      void showproduct()
      {
	cout<<"\n\t Product number is : "<<pno;
	cout<<"\n\t The name of the Product is:";
	puts(name);
	cout<<"\n\t The price of the product is:"<<price;
	cout<<"\n\t The Stock Quantity of the product is:";
	ex.count2();
      }
   int retpno()
   {
      return pno;
   }
   char* retname()
   {
    return name;
   }
   float retprice()
   {
    return price;
    }

};

fstream fp;
product pr;

void writeproduct()
{
 fp.open("shop.txt",ios::out|ios::app);
 pr.createproduct();
 fp.write((char*)&pr,sizeof(product));
 fp.close();
 cout<<"\n\t The Product has been created";
 getch();
}

void display()
{
clrscr();
cout<<"\n\t Display All Records !!!\n";
fp.open("shop.txt",ios::in);
while(fp.read((char*)&pr,sizeof(product)))
{
pr.showproduct();
getch();
}
fp.close();
getch();
}

void displayspecific(int n)
{
int flag=0;
fp.open("shop.txt",ios::in);
while(fp.read((char*)&pr,sizeof(product)))
{
   if(pr.retpno()==n)
   {
   clrscr();
   pr.showproduct();
   flag=1;
   }
}
fp.close();
if(flag==0)
cout<<"\n\t Record does not exist";
getch();
}

void modifyproduct()
{
  int no,found=0;
  clrscr();
  cout<<"\n\t Enter the product no. of the product:";
  cin>>no;
  fp.open("shop.txt",ios::in|ios::out);
  while(fp.read((char*)&pr,sizeof(product)) && found==0)
  {
    if(pr.retpno()==no)
    {
      pr.showproduct();
      cout<<"\n\t Enter the new details of Product:"<<endl;
      pr.createproduct();
      int pos=-1*sizeof(pr);
      fp.seekp(pos,ios::cur);
      fp.write((char*)&pr,sizeof(product));
      cout<<"\\\t Record Updated:";
      found=1;
    }
  }
  fp.close();
  if(found==0)
  cout<<"\\t Record Not Found";
  getch();
}



void delete_product()
{
int no;
clrscr();
cout<<"\n\t Please Enter the product no. of the product you want to delete:";
cin>>no;
fp.open("shop.txt",ios::in|ios::out);
fstream fp2;
fp2.open("temp.txt",ios::out);
fp.seekg(0,ios::beg);
while(fp.read((char*)&pr,sizeof(product)))
{
  if(pr.retpno()!=no)
  {
    fp2.write((char*)&pr,sizeof(product));
  }
}
 fp2.close();
 fp.close();
 remove("shop.txt");
 rename("Temp.txt","Shop.txt");
 cout<<"\n\t  Record Deleted";
 getch();
}

void menu()
{
 clrscr();
 fp.open("shop.txt",ios::in);
 if(!fp)
 {
   cout<<"\n\t Error!!! File can't be opened";
   cout<<"\n\t Program is closing";
   getch();
   exit(0);
 }

 cout<<"\nProduct Menu:\n\n";
 while(fp.read((char*)&pr,sizeof(product)))
 {
   cout<<pr.retpno()<<"\t\t"<<pr.retname()<<"\t\t"<<pr.retprice()<<"\t\t";
   ex.count2();
   cout<<endl;
 }
 fp.close();
}

void place_order()
{
	char cho,card[50],card1[50],name[50],name1[50];
	int order_arr[50],quan[50],k1,l,c=0,count1,count=0;
	float amt,damt,amt1=0;
	char ch='Y';
	menu();
	ifstream o("count.txt",ios::in);
	while(!o.eof())
	{o>>count1;
	count=count1;
	}
  cout<<"\n\t Place your Order\n";
  do
  {
    cout<<"\n\t Enter the product no. of the product:";
    cin>>order_arr[c];
    cout<<"\n\t Quantity in number:";
    cin>>quan[c];
    count=count-quan[c];
    ofstream o("count.txt",ios::out);
    {o<<count;
    }
    o.close();
    c++;
    if(count<1)
    {cout<<"\n Product Is Out Of Stock \n Please Come Again Later\n Thank You\n";
    system("pause");
   // exit(0);
    }

    cout<<"\n\t Do you want to add another product?";
    cin>>ch;
   }while(ch=='y'||ch=='Y');
   cout<<"\n\t Thank you for placing order";
   getch();
   clrscr();
   srand(time(NULL));
   cout<<"\n";
   time_t t;
	time(&t);
	cout<<"\t\t\t\t\t\t"<<ctime(&t);
   cout<<"\nInvoice No.: HXHMART"<<rand() % 999999 + 1 <<"\n\n";
   cout<<"\nProduct No\tProduct Name\tQuantity\tPrice\tSubtotal\n\n";
   for(int x=0;x<=c;x++)
   {
    fp.open("Shop.txt",ios::in);
    fp.read((char*)&pr,sizeof(product));
	while(!fp.eof())
    {
      if(pr.retpno()==order_arr[x])
      {
	amt=pr.retprice()*quan[x];

	cout<<"\n"<<order_arr[x]<<"\t\t"<<pr.retname()<<"\t\t"<<quan[x]<<"\t\t"<<pr.retprice()<<"\t"<<amt;
      }
      fp.read((char*)&pr,sizeof(product));
      } amt1+=amt;
      fp.close();
    }
     cout<<"\n--------------------------------------------------------------\n";
     cout<<"Grand Total:\t(Including VAT)\t\t\t\t"<<amt1;
     cout<<"\n--------------------------------------------------------------\n";
     cout<<"\n Premium Customer Discount Included?";
     cin>>cho;
     if(cho=='y'||cho=='Y')
     {cout<<"\n Enter Card Number:";
     gets(card);
     ifstream fr("vip.txt",ios::in);
     while(!fr.eof())
     {fr>>card1;
     l=strcmp(card,card1);
     }
     ifstream zr("sharp.txt",ios::in);
     while(!zr.eof())
     {zr>>name1;
     strcpy(name,name1);
     }
     if(l==0)
     {cout<<"\n Accepted!\n Hello Mr."<<name;
     cout<<"\n---------------------------------------------------------------------\n";
     cout<<"New Grand Total:\t\t\t\t\t"<<amt1-(amt1/10);
     cout<<"\n---------------------------------------------------------------------\n";getch();
     }else
     {cout<<"\n Invalid card!";
     cout<<"\n------------------------------------------------------------------\n";
     cout<<"New Grand Total:\t\t\t\t\t\t"<<amt1;
     cout<<"\n------------------------------------------------------------------\n";getch();
     }fr.close();zr.close();
     }
     else
	{cout<<"\n Have a Nice Day!\n";
	system("pause");
	exit(0);
	}
     }
void intro()
{
 clrscr();
 gotoxy(31,11);
 cout<<"SUPER  MARKET";
 gotoxy(34,13);
 cout<<"BILLING";
 gotoxy(34,15);
 cout<<"SYSTEM";
 getch();
}
void addy()
{int k,z;
char id[50],id1[50];

aditya:clrscr();
cout<<"\n \nHello Admin!\n 1. Create Sales Person for this Particular Counter\n 2. Delete Sales Person\n 3. Exit\n Enter Your Choice:";
cin>>z;
switch(z)
{
case 1: ofstream f("sp.txt",ios::out);
	cout<<"\n Enter Unique ID:";
	gets(id);
	f<<id;
	f.close();
	cout<<"\n Created!";
	system("pause");
	goto aditya;

case 2: ifstream fz("sp.txt",ios::in);
	if(!fz)
	{cout<<"\n Error 404: File Not Found";
	exit(0);
	}cout<<"\n Enter the ID you want to delete:";
	gets(id1);
	while(!fz.eof())
	{fz>>id;
	k=strcmp(id1,id);
	}if(k==0)
	{cout<<"\n Deleted! Create New User In Order To Use This Counter\n Thank You!\n ";
	}system("pause");
	fz.close();
	remove("sp.txt");
	goto aditya;
case 3:
	break;
}
}

void adminmenu()
{
clrscr();
 int ch2;
 cout<<"\n\t==> Admin Menu<== \n\t";
 cout<<"\n\t 1.Create Product";
 cout<<"\n\t 2.Display all products";
 cout<<"\n\t 3.Query";
 cout<<"\n\t 4.Modify Products";
 cout<<"\n\t 5.Delete Products";
 cout<<"\n\t 6.View Product Menu";
 cout<<"\n\t 7.Back to main Menu";
 cout<<"\n\t 8.Sales Person Authorization";
 cout<<"\n\t Please enter your choice:";
 cin>>ch2;
 switch(ch2)
 {
   case 1:
	  writeproduct();
	  break;
   case 2:
	   display();
	   break;
   case 3:
	   int num;
	      cout<<"\n\t Please Enter the product number";
	      cin>>num;
	   displayspecific(num);
	   break;
   case 4:
	  modifyproduct();
	  break;
   case 5:
	   delete_product();
	   break;
   case 6:
	   menu();
	   break;
   case 7:
	   break;
   case 8: addy();
	   break;
    default:
	   cout<<"\n\t Wrong choice";
	   adminmenu();
}
}
void main()
{
intro();
int choice,k,choi;
char ch,pass[50],id[50],id1[50],card1[50],name[50];
do
{
   clrscr();
   A:
	time_t t;
	time(&t);
	cout<<"\t\t\t\t\t\t"<<ctime(&t);

   cout<<"\n\t Menu";
   cout<<"\n\t 1.Sales Person";
   cout<<"\n\t 2.Administrator";
   cout<<"\n\t 3.Exit";
   cout<<"\n\t Enter your choice:";
   cin>>choice;
   switch(choice)
   {
     case 1:
       {	clrscr();
	ifstream fz("sp.txt",ios::in);
	if(!fz)
	{cout<<"\n No User Login Access! Contact Admin\n ";
	system("pause");
	exit(0);
	}
	cout<<"\n Enter Your Unique ID:";
	gets(id1);
	while(!fz.eof())
	{fz>>id;
	k=strcmp(id1,id);
	}if(k==0)
	{  clrscr();
		cout<<"\n 1)Place Order\n 2)Create Premium Customer\n 3)Exit \n Enter Your Choice:";
		cin>>choi;
       switch(choi)
       {
       case 1:	{place_order();
		break;
		}
       case 2:
		{ofstream fl("vip.txt",ios::out);
		cout<<"\n Enter New Card Number:";
		gets(card1);
		fl<<card1;
		fl.close();
		ofstream z("sharp.txt",ios::out);
		cout<<"\n In The Name Of:";
		gets(name);
		z<<name;
		cout<<"\n Thank You Sir! You Are Now A Priority To Us!\n";
		system("pause");
		z.close();
		}

	case 3:	break;

		}
		}
		else
		{cout<<"\n Invalid Id\n";
		system("pause");
		break;
		}
	       }
     case 2:   { clrscr();
		gotoxy(11,11);
		cout<<"\n Enter Password:";
		gets(pass);
		fflush(stdin);
		k=strcmp(pass,"helloAdmin");
		system("pause");
		if(k==0)
		{clrscr();
		adminmenu();
		break;
		}
		else
		{cout<<"\nInvalid Password\n";
		system("pause");
		break;
		}}
     case 3:
	    { exit(0);}
     default:
	    {cout<<"\n\t Wrong Choice:";
	    goto A;}
    }
    }while(ch!='3');

    getch();

    }