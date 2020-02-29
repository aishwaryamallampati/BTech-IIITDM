/*given a sentence, the sentence is reversed in terms of words.ex: input:-this is cat. output:-cat is this*/
#include<iostream>
#include<cstring>

using namespace std;

class sentence
{
	public:
		sentence();
		int stringlen(char a[100]);
		void revstring(char dup[100],int start,int end);
		int checkpalin(char a[100],char dup[100]);
		char a[100];
		char dup[100];
	
		
};

sentence::sentence()
{
	int len,i,palin,wordstart,wordend;
	cout<<"\nenter the sentence to be reversed:";
	cin.getline(a,100);
	cout<<a<<endl;
	len=stringlen(a);
	cout<<"len="<<len<<endl;
	for(i=0;i<=len;i++)
		dup[i]=a[i];
	revstring(dup,0,len-1);

	cout<<"the original sentence is: "<<a<<endl;
	cout<<"the reversed sentence is: "<<dup<<endl;
	
	for(wordstart=wordend=0;wordend<len;wordend++)
	{
	 if(dup[wordend]!=' ')
	 {
	  wordstart=wordend;
	  while(dup[wordend]!=' '&&wordend<len)
	  	wordend++;
	  wordend--;
	  revstring(dup,wordstart,wordend);
	 }
	}
	cout<<"the reversed sentence in words is: "<<dup<<endl;
	palin=checkpalin(a,dup);
	if(palin==1)
	 cout<<"the given string is a palindrome"<<endl;
	else
	 cout<<"the given string is not a palindrome"<<endl;
}

int sentence::stringlen(char a[100])
{
	int i=0;
	while(a[i]!='\0')
	{
	 i++;
	}
	return i;
}

void sentence::revstring(char dup[100],int start,int end)
{
	int i,j;
	char temp;
	for(i=start,j=end;i<j;i++,j--)
	{
		temp=dup[i];
		dup[i]=dup[j];
		dup[j]=temp;
	}
	
}

int sentence::checkpalin(char a[100],char dup[100])
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
	sentence sentence1;
	return 0;
}
	
