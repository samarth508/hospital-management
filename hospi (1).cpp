#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iomanip.h>

class hospital
{
char department[20];
public:
void getdata()
{
cout<<"\nEnter Department:\t";
gets(department);
}
void show()
{
cout<<"Name of the department:\t"<<department;
}
};

class patient:public hospital
{
hospital h;
public:
char bloodgp[5];
char name[20];
long int id;
int a;
long int ph;
void patientrec();
void showdata();
};

void patient::patientrec()
{
cout<<"\n";
cout<<"\t\t\t\tCREATE NEW RECORD OF PATIENT";
cout<<"\n";
cout<<"\nEnter Id of patient:\n";
cin>>id;
cout<<"\nEnter name of patient:\n";
cin>>name;
cout<<"\nEnter Blood group of patient:\n";
cin>>bloodgp;
cout<<"\nEnter phone no. of patient:\n";
cin>>ph;
h.getdata();
}

void patient::showdata()
{
cout<<"\nPatient id:\t"<<id;
cout<<"\nName of patient:\t"<<name;
cout<<"\nBlood group:\t"<<bloodgp;
cout<<"\nPhone no. of patient:\t"<<ph<<"\n";
h.show();
}

void main()
{
clrscr();
gotoxy(2,2);
cout<<"\t\t\tCITY HOSPITAL";
gotoxy(4,4);
cout<<"\nPRESS ANY KEY TO CONTINUE:";
getch();
clrscr();
char s;
patient obj;
z:
fstream f;
f.open("patient",ios::in|ios::out|ios::app|ios::ate|ios::binary);
cout<<"\n";
cout<<"MAIN MENU\n"<<"\n";
cout<<"\n(1)Enter record of patient:";
cout<<"\n(2)View patient record:";
cout<<"\n(3)Modify patient record:";
cout<<"\n(4)Search patient record:";
cout<<"\n(5)Delete record:";
cout<<"\n(6)Exit:";
int a;
cout<<"\n\t Enter your choice:";
f.seekg(0);
cin>>a;
char x;
switch(a)
{
case 1:clrscr();
fstream f;
f.open("patient",ios::in|ios::out|ios::app|ios::ate|ios::binary|ios::trunc);
char ans;
obj.patientrec();
f.write((char*)&obj,sizeof(obj));
getch();
cout<<"\nWANT TO CONTINUE?(yes or no):";
ans=getchar();
if (ans=='y'||ans=='Y')
goto z;
else
break;

case 2:
{
fstream f;
f.open("patient",ios::in|ios::out|ios::ate|ios::app|ios::binary);
char ans;
f.seekg(0);
int ctr=0;
while(f.read((char*)&obj,sizeof(obj)))
{
ctr=ctr+1;
if(ctr==8)
{
getchar();
clrscr();
ctr=0;
}
obj.showdata();
if(f.eof()==1)
{
break;
}
}
f.close();
cout<<"\n\nWANT TO CONTINUE?(yes or no):";
cin>>ans;
if(ans=='y'||ans=='Y')
goto z;
else
{
exit(1);
}
}break;

case 3:
{
char ans;
fstream f;
patient obj;
char name[20];
char bloodgp[5];
long int ph;
int id;
f.open("patient",ios::in|ios::binary);
cout<<"\nModify patient record:";
cout<<"\nEnter name of the patient:";
cin>>name;
do
{
f.read((char*)&obj,sizeof(obj));
if(f.eof()==1)
{
break;
}
if(strcmp(obj.name,name)==0)
{
cout<<"\nName of patient:\t"<<obj.name;
cout<<"\nBlood group:\t"<<obj.bloodgp;
cout<<"\nPhone no. of patient:\t"<<obj.ph;
getchar();
cout<<endl;
cout<<endl;
cout<<"\nEnter New Database:";
cout<<"\nEnter patient name:\t";
cin>>name;
cout<<"\nEnter id of patient:\t";
cin>>id;
cout<<"\nBlood group:";
cin>>bloodgp;
cout<<"\nEnter phone no. of patient:\t";
cin>>ph;
cout<<"\n";
strcpy(obj.name,name);
strcpy(obj.bloodgp,bloodgp);
obj.a=a;
int l=f.tellg();
f.close();
f.open("patient",ios::out|ios::binary|ios::ate);
f.seekg(l-sizeof(obj));
f.write((char*)&obj,sizeof(obj));
}
}
while(f);
f.close();
cout<<"\n\nWANT TO CONTINUE?(yes or no):";
ans=getchar();
if(ans=='y'||ans=='Y')
{
goto z;
}
else
break;}

case 4:
{
clrscr();
char ans;
fstream f;
patient obj;
char name[20];
char bloodgp[5];
long int ph;
int id;
f.open("patient",ios::in|ios::binary);
cout<<"\n";
cout<<"\nSearch Patient Database";
cout<<"\nEnter patient name:";
cin>>name;
do
{
f.read((char*)&obj,sizeof(obj));
if(f.eof()==1)
{break;}
if(strcmp(obj.name,name)==0)
{
cout<<"\nPatient name:\t"<<obj.name;
cout<<"\nPatient id:\t"<<obj.id;
cout<<"\nBlood group:\t"<<obj.bloodgp;
cout<<"\nPhone of patient:\t"<<obj.ph;
getchar();
cout<<endl;
strcpy(obj.name,name);
strcpy(obj.bloodgp,bloodgp);
obj.a=a;
int l=f.tellg();
f.close();
f.open("patient",ios::out|ios::binary|ios::ate);
f.seekg(l-sizeof(obj));
f.write((char*)&obj,sizeof(obj));
}
else
{
cout<<"\nPATIENT DOESN'T EXIST";
}
}
while(f);
f.close();
cout<<"\n\nWANT TO CONTINUE?(yes or no):";
ans=getchar();
if(ans=='y'||ans=='Y')
{goto z;}
else
break;}

case 5:
{
fstream f1,f2;patient obj;
int rec,found=0;int cnt=0;
cout<<"\nEnter desired record no.";
cin>>rec;
f1.open("patient",ios::in|ios::binary);
f2.open("temp",ios::out|ios::binary);
while(f1.read((char*)&obj,sizeof(obj)))
{
cnt++;
if(rec==cnt)
{
obj.showdata();
cout<<"\nDELETED";
found++;
}
else
f2.write((char*)&obj,sizeof(obj));
}
f1.close();f2.close();
remove("patient");rename("pat","patient");
cout<<found<<"\nRECORDS DELETED";
}

case 6:
{
exit(1);}
default:
{
cout<<"\nINPUT IS WRONG";}
cout<<"\n\nWANT TO CONTINUE?(yes or no):";
ans=getchar();
clrscr();
if(ans=='y'||ans=='Y')
{goto z;}
else
break;
}
getch();
}






