#include<iostream>
#include<cstring>

using namespace std;

main()
{
int position;
int size;
string a;
char b[50];
cout<<"enter string: ";
getline(cin,a);
b[0]='w';
b[1]='i';
b[2]='f';
b[3]='e';
b[4]='\0';
position=a.find(b);
while(a.find(b)!=string::npos)
{
a.replace(a.find(b),4,"spouse");
}
cout<<a<<endl;

return 0;
}





mb[4]='b';mb[4]='a';mb[6]='b';mb[7]='y';mb[8]='\0';
fb[6]='b';fb[7]='a';fb[8]='b';fb[9]='y';fb[10]='\0';

	
	
	
	
	
	while(input.find(d)!=string::npos)
	{
	 input.replace(input.find(d),8,"child");
	}
	
	
