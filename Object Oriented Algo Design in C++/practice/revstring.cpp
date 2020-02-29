/*given a string, the string is reversed and checked whether it is a palindrome or not*/
#include<iostream>
#include<cstring>

using namespace std;

class word
{
	public:
		word();
		int stringlen(char a[100]);
		void revstring(char dup[100],int len);
		int checkpalin(char a[100],char dup[100]);
		char a[100];
		char dup[100];
	
		
};

word::word()
{
	int len,i,palin;
	cout<<"\nenter the word to be reversed:";
	cin.getline(a,100);
	cout<<a<<endl;
	len=stringlen(a);
	cout<<"len="<<len<<endl;
	for(i=0;i<=len;i++)
		dup[i]=a[i];
	revstring(dup,len);
	cout<<"the original string is "<<a<<endl;
	cout<<"the reversed string is "<<dup<<endl;
	palin=checkpalin(a,dup);
	if(palin==1)
	 cout<<"the given string is a palindrome"<<endl;
	else
	 cout<<"the given string is not a palindrome"<<endl;
}

int word::stringlen(char a[100])
{
	int i=0;
	while(a[i]!='\0')
	{
	 i++;
	}
	return i;
}

void word::revstring(char dup[100],int len)
{
	int start,end;
	char temp;
	for(start=0,end=len-1;start<end;start++,end--)
	{
		temp=dup[start];
		dup[start]=dup[end];
		dup[end]=temp;
	}
	dup[len]='\0';
}

int word::checkpalin(char a[100],char dup[100])
{
	int palin=0,i=0;
	while(a[i]!='\0')
	{
	 if(a[i]==dup[i])
	 palin=1;
	 else palin=0;
	 i++;
	}
	return palin;
}


main()
{
	word word1;
	return 0;
}
	
