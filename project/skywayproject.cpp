#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include<fstream>
#include<iomanip>
#include<windows.h>
#include <winbgim.h>

using namespace std;
static int p = 1;
class a
{
  char busn[5];
   string driver, arrival, depart;
   string from, to;
  char seat[8][4][10];
public:
  void install();
  void allotment();
  void empty();
  void show();
  void avail();
  void position(int i);
  void access();
}
bus[3];
void vline(char ch)
{
  for (int i=110;i>0;i--)
  cout<<ch;
}
void a::install()
{
	char ch='y';
	ofstream file("busdata.txt",ios::app);
  cout<<"Enter bus no: ";
  cin>>bus[p].busn;
  cout<<"\nEnter Driver's name: ";
  cin>>bus[p].driver;
  cout<<"\nArrival time: ";
  cin>>bus[p].arrival;
  cout<<"\nDeparture: ";
  cin>>bus[p].depart;
  cout<<"\nFrom: \t\t\t";
  cin>>bus[p].from;
  cout<<"\nTo: \t\t\t";
  cin>>bus[p].to;
  bus[p].empty();
  while(ch=='y'){
  	file<<bus[p].busn<<" "<<bus[p].driver<<endl;
  	file<<bus[p].arrival<<" "<<bus[p].depart<<endl;
  	file<<bus[p].from<<" "<<bus[p].to<<endl;
  	cout<<" do you wanna more install yes or no";
  	cin>>ch;
  }

  p++;
  file.close();

}

void a::allotment()
{
  int seat;
  char number[5];
  top:
  cout<<"Bus no: ";
  cin>>number;
  int n;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }
  while(n<=p)
  {
    cout<<"\nSeat Number: ";
    cin>>seat;
    if(seat>32)
    {
      cout<<"\nThere are only 32 seats available in this bus.";
    }
    else
    {
    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "------")==0)
      {
        cout<<"Enter passanger's name: ";
        cin>>bus[n].seat[seat/4][(seat%4)-1];
        break;
      }
    else
      cout<<"The seat no. is already reserved.\n";
      }
      }
    if(n>p)
    {
      cout<<"Enter correct bus no.\n";
      goto top;
    }
  }

void a::empty()
{
  for(int i=0; i<8;i++)
  {
    for(int j=0;j<4;j++)
 {
      strcpy(bus[p].seat[i][j], "------");
    }
  }
}
void a::show()
{
  int n;
  char number[5];
  cout<<"Enter bus no: ";
  cin>>number;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }
while(n<=p)
{
  vline('*');
    cout<<setw(70)<<"SKYWAYS TERMINAL\n";
    cout<<setw(20)<<"\n\tBus no: \t"<<setw(20)<<bus[n].busn<<setw(20)<<"\tDriver: \t"<<setw(20)<<bus[n].driver<<endl;
    cout<<setw(20)<<"\tArrival time: \t"<<setw(20)<<bus[n].arrival<<setw(20)<<"\tDeparture Time: \t";
    cout<<setw(20)<<bus[n].depart<<setw(20)<<"\n\tFrom: \t\t"<<setw(20)<<bus[n].from<<setw(20)<<"   To: \t\t";
    cout<<setw(20)<<bus[n].to<<"\n";
    vline('*');
    bus[0].position(n);
  int a=1;
  for (int i=0; i<8; i++)
  {
    for(int j=0;j<4;j++)
    {
      a++;
      if(strcmp(bus[n].seat[i][j],"------")!=0)
      cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
    }
  }
  getche();
  break;

  }

  if(n>p)
    cout<<"Enter correct bus no: ";
}
void a::position(int l)
{
  int s=0;p=0;
  for (int i =0;i<8;i++)
  {
    cout<<"\n\n";
    for (int j = 0;j<4; j++)
    {
      s++;
      if(strcmp(bus[l].seat[i][j], "------")==0)
        {
          cout.width(9);
          cout<<s<<":";
          cout.width(14);
          cout<<bus[l].seat[i][j];
          p++;
        }
        else
        {
        cout.width(9);
        cout<<s<<":";
        cout.width(14);
        cout<<bus[l].seat[i][j];
        }
      }
    }
  cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].busn;
  }
void a::avail()
{
	system("cls");
	cout<<"\n\n\n";
	int num;
	string name,Atime,Dtime,from,to;
	ifstream file("busdata.txt",ios::in);
	while(!file.eof()){




    file>>num>>name;
  	file>>Atime>>Dtime;
  	file>>from>>to;



	vline('#');
	cout<<setw(70)<<"SKYWAYS TERMINAL\n";
	cout<<"\n\tBus no: \t"<<num<<"\tDriver: \t"<<name<<endl;
    cout<<"\tArrival time: \t"<<Atime<<"\tDeparture Time: \t";
    cout<<Dtime<<"\n\tFrom: \t\t"<<from<<"\tTo: \t\t";
    cout<<to<<"\n";
    vline('#');
    cout<<endl;
    vline('_');
    getche();
  }
  file.close();
}
void access(){

int w;
while(1)
{
	system("color 3E");
	system("cls");
	cout<<"\n\n\t\t\t\t************WELCOME TO SKYWAYS************";

  cout<<"\n\n\n\n\n";
  cout<<"\t\t\t\t\t1.Install\n\t\t\t";
  cout<<"\t\t2.Reservation\n\t\t\t";
  cout<<"\t\t3.Show\n\t\t\t";
  cout<<"\t\t4.Buses Available. \n\t\t\t";
  cout<<"\t\t5.Exit";
  cout<<"\n\t\t\tEnter your choice:-> :";
  cin>>w;
  switch(w)
  {
    case 1:
	system("cls");
	bus[p].install();
      break;
    case 2:
	system("cls");
	bus[p].allotment();
      break;
    case 3:
	system("cls");
	bus[0].show();
      break;
    case 4:
	system("cls");
	bus[0].avail();
      break;
    case 5:  exit(0);
  }
}
}
void password()
{
	int i;
	system("idp.vbs");
	string admin="3310494888767";
	char pass[5];
	char pas[5]="afii";
	string en;
	cout << "\n\n\n\t\tEnter your CNIC :\t";
	cin >> en;
	Sleep(300);
	cout << "\t\tEnter Password :\t";
	char a;// temporary char
	for(  i=0;;)
{
		a=getche();
		if(isalnum(a))
		{
			pass[i]=a;// stores a in pass
			i++;
			cout << "\b \b";
			cout << "*";

		}
		if(a=='\b'&&i>=0)// for backspace
		{
			cout << "\b \b"; //rub the character behinde the cursor.
			--i;
		}
		if(a=='\r')//if enter is pressed
		{
			pass[i]='\0';// end of of string
			break;//break loop
		}
	}
	if(i>=6 || i<=3)
	{
		cout << "\nEnter minimum 4- digit password"<<endl;
		cout << "Try Again"<<endl;
		getch();
		system("cls");
		password();

	}

	cout <<endl;
	cout << endl;

		if( en == admin  )
	{
		for(int j=0;  pass[j]!='\0'; j++)
	 {
		if( pass[j] == pas[j] )
	  {



		Sleep(500);
		cout<<"\n\n\t\tloading..";
		Sleep(500);
		cout<<"..";
		Sleep(500);
		cout<<".";
		Sleep(500);
		cout<<"."<<endl;
		system("cls");
		Sleep(300);
		system("wlcm.vbs");
		access();



		break;



	}

	else
	{

	system("cls");
		password();
	}


	  }

	 }
	 else
	{
		system("cls");
		password();

	}

	}

int main()
{
	initwindow(600,500);
	setcolor(3);
	settextstyle(6,0,3);
	outtextxy(55,20,"welcome to skyways terminal");
	settextstyle(7,0,2);
	outtextxy(180,120,"kamran subhani");
	settextstyle(6,0,1);
	outtextxy(180,160,"15-SE-71");
	delay(7000);
	closegraph();
	password();

	system("cls");


return 0;
}
