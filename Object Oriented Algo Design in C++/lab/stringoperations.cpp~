/*program to perform operations on a given string*/
#include<iostream>
#include<cstring>

using namespace std;

class sentence
{
	public:
		void entersentence();
		int charactercount();
		int vowelcount();
		int articlecount();
		void replace();
		void print();
	private:
		char input[100];
		char w[50],h[50],b[50],s[50];

};



void sentence::entersentence()
{
	cout<<"\nenter the text:";
	cin.getline(input,100);
}/*to take the input sentence*/

int sentence::charactercount()
{
	int index1=0,charcount=0;
	while(input[index1]!='\0')
	{
	 if(input[index1]!=' ')
	 {
	  charcount++;
	 }
	 index1=index1+1;
	}
	return charcount;
}/*to count the number of characters in the sentence*/

int sentence::vowelcount()
{
	int index1=0,vowelcount=0;
	while(input[index1]!='\0')
	{
	 if(input[index1]=='a'||input[index1]=='e'||input[index1]=='i'||input[index1]=='o'||input[index1]=='u')
	 {
	  vowelcount++;
	 }
	 index1=index1+1;
	}
	return vowelcount;
}/*to count the number of vowels in the given sentence*/

int sentence::articlecount()
{
	int index1=0,articlecount=0;
	while(input[index1]!='\0')
	{
	 if(index1==0)
	 {
		if(input[index1]=='a'&&input[index1+1]==' '||input[index1]=='a'&&input[index1+1]=='n'&&input[index1+2]==' '||input[index1]=='t'&&input[index1+1]=='h'&&input[index1+2]=='e'&&input[index1+3]==' ')
	   articlecount++;
		if(input[index1]=='a'&&input[index1+1]=='\0'||input[index1]=='a'&&input[index1+1]=='n'&&input[index1+2]=='\0'||input[index1]=='t'&&input[index1+1]=='h'&&input[index1+2]=='e'&&input[index1+3]=='\0')
	   articlecount++;
	}
	 else if(index1!=0)
	  {
	  	if(input[index1-1]==' '&&input[index1]=='a'&&input[index1+1]==' '||input[index1-1]==' '&&input[index1]=='a'&&input[index1+1]=='n'&&input[index1+2]==' '||input[index1-1]==' '&&input[index1]=='t'&&input[index1+1]=='h'&&input[index1+2]=='e'&&input[index1+3]==' ')
	   articlecount++;
		if(input[index1-1]==' '&&input[index1]=='a'&&input[index1+1]=='\0'||input[index1-1]==' '&&input[index1]=='a'&&input[index1+1]=='n'&&input[index1+2]=='\0'||input[index1-1]==' '&&input[index1]=='t'&&input[index1+1]=='h'&&input[index1+2]=='e'&&input[index1+3]=='\0')
	   articlecount++;
	 }
	index1++;
	}
	return articlecount;
}/*to count the number of articles in the given sentence*/
	
main()
{
	int ccount,vcount,acount;
	sentence sentence1;
	sentence1.entersentence();
	ccount=sentence1.charactercount();
	cout<<"\nthe character count is "<<ccount;
	vcount=sentence1.vowelcount();
	cout<<"\nthe vowel count is "<<vcount;
	acount=sentence1.articlecount();
	cout<<"\nthe article count is "<<acount<<endl;
	return 0;
}
