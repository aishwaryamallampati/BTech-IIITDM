/*program to remove gender specific words in a string*/
#include<iostream>
#include<cstring>

using namespace std;

class sentence
{
	public:
		void entersentence();
		void replace();
		void print();
	private:
		string input;
		char w[50],h[50],b[50],s[50],m[50],f[50],ap[50],am[50],x[50],d[50],mb[50],fb[50],Ap[50],Am[50],F[50],B[50],M[50],S[50];

};



void sentence::entersentence()
{
	cout<<"\nenter the text:";
	getline(cin,input);
}/*to take the input sentence*/

void sentence::print()
{
	cout<<input;
	
}/*to print the sentence*/

void sentence::replace()
{
w[0]='W';w[1]='i';w[2]='f';w[3]='e';w[4]='\0';
h[0]='H';h[1]='u';h[2]='s';h[3]='b';h[4]='a';h[5]='n';h[6]='d';h[7]='\0';
b[0]='b';b[1]='r';b[2]='o';b[3]='t';b[4]='h';b[5]='e';b[6]='r';b[7]='\0';
B[0]='B';B[1]='r';B[2]='o';B[3]='t';B[4]='h';B[5]='e';B[6]='r';B[7]='\0';
s[0]='s';s[1]='i';s[2]='s';s[3]='t';s[4]='e';s[5]='r';s[6]='\0';
S[0]='S';S[1]='i';S[2]='s';S[3]='t';S[4]='e';S[5]='r';S[6]='\0';
f[0]='f';f[1]='a';f[2]='t';f[3]='h';f[4]='e';f[5]='r';f[6]='\0';
F[0]='F';F[1]='a';F[2]='t';F[3]='h';F[4]='e';F[5]='r';F[6]='\0';
m[0]='m';m[1]='o';m[2]='t';m[3]='h';m[4]='e';m[5]='r';m[6]='\0';
M[0]='M';M[1]='o';M[2]='t';M[3]='h';M[4]='e';M[5]='r';M[6]='\0';
x[0]='s';x[1]='o';x[2]='n';x[3]='\0';
d[0]='d';d[1]='a';d[2]='u';d[3]='g';d[4]='h';d[5]='t';d[6]='e';d[7]='r';d[8]='\0';
ap[0]='a';ap[1]='p';ap[2]='p';ap[3]='a';ap[4]='\0';
Ap[0]='A';Ap[1]='p';Ap[2]='p';Ap[3]='a';Ap[4]='\0';
am[0]='a';am[1]='m';am[2]='m';am[3]='a';am[4]='\0';
Am[0]='A';Am[1]='m';Am[2]='m';Am[3]='a';Am[4]='\0';
mb[0]='m';mb[1]='a';mb[2]='l';mb[3]='e';mb[4]='\0';
fb[0]='f';fb[1]='e';fb[2]='m';fb[3]='a';fb[4]='l';fb[5]='e';fb[6]='\0';

	while(input.find(w)!=string::npos)
	{
	 input.replace(input.find(w),4,"spouse");
	}
	while(input.find(h)!=string::npos)
	{
	 input.replace(input.find(h),7,"spouse");
	}
	while(input.find(b)!=string::npos)
	{
	 input.replace(input.find(b),7,"sibling");
	}
	while(input.find(B)!=string::npos)
	{
	 input.replace(input.find(B),7,"sibling");
	}
	while(input.find(s)!=string::npos)
	{
	 input.replace(input.find(s),6,"sibling");
	}
	while(input.find(S)!=string::npos)
	{
	 input.replace(input.find(S),6,"sibling");
	}
	while(input.find(f)!=string::npos)
	{
	 input.replace(input.find(f),6,"parent");
	} 
	while(input.find(F)!=string::npos)
	{
	 input.replace(input.find(F),6,"parent");
	} 
	while(input.find(m)!=string::npos)
	{
	 input.replace(input.find(m),6,"parent");
	}
	while(input.find(M)!=string::npos)
	{
	 input.replace(input.find(M),6,"parent");
	}
	while(input.find(x)!=string::npos)
	{
	input.replace(input.find(x),3,"child");
	}
	while(input.find(d)!=string::npos)
	{
	 input.replace(input.find(d),8,"child");
	}
	while(input.find(ap)!=string::npos)
	{
	 input.replace(input.find(ap),4,"parent");
	}
	while(input.find(Ap)!=string::npos)
	{
	 input.replace(input.find(Ap),4,"parent");
	}
	while(input.find(am)!=string::npos)
	{
	 input.replace(input.find(am),4,"parent");
	}
	while(input.find(Am)!=string::npos)
	{
	 input.replace(input.find(Am),4,"parent");
	}
	while(input.find(fb)!=string::npos)
	{
	 input.replace(input.find(fb),6,"");
	}
	while(input.find(mb)!=string::npos)
	{
	 input.replace(input.find(mb),4,"");
	}	
}/*to replace gender specific words with general words in the given sentence*/

main()
{
	sentence sentence1;
	sentence1.entersentence();
	sentence1.replace();
	sentence1.print();
	return 0;
}
	
