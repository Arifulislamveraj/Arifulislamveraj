#include<iostream>
#include<string.h>
#include<stdio.h>
#include<cstdlib>
#include<fstream>

using namespace std;
char file[30]   = "file.txt";

class Dynam1ca
{
     int student_id;
     char name[30];
     char address[60];
     int age;
     public:
          char dept[15];
     void get();
     char *getdept()
     {
          return dept;
     }
};
void Dynam1ca::get()
{
     cout<<"\n Enter Student Id     :  ";  cin>>student_id;
     cout<<"\n Enter Name            : ";  cin>>name;
     cout<<"\n Enter Address         : ";  cin>>address;
     cout<<"\n Enter Department Name : ";  cin>>dept;
     cout<<"\n Enter Age   :  ";           cin>>age;
}
void insert()
{
     Dynam1ca e;
     
     ofstream fout;
     fout.open("file.txt",ios::in | ios::out | ios::binary | ios::app | ios::ate);
     
     if (fout.fail())
     {
          cout<<"\n Unable to Open the File!!!";
          goto error;
     }
     e.get();
     fout.write((char *)&e,sizeof(e));
     if(fout.tellp()%sizeof(e)==0)
     {
          cout<<"\n Record Inserted !!!"<<endl;
     }
     else
     {
          cout<<"\n Insertion Failed !!!";
          goto error;
     }
     error:
          fout.close();
        
}

int main()
{

    insert();

    return 0;
}
