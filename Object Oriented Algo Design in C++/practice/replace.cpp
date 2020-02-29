#include<iostream>
#include<cstring>

using namespace std;

main()
{
int position;
int size;
string a;
string b;
cout<<"enter string: ";
getline(cin,a);
cout<<"\nenter word:";
getline(cin,b);
position=a.find(b);
while(a.find(b)!=string::npos)
{
a.replace(a.find(b),4,"spouse");
}
cout<<a<<endl;

return 0;
}
