/*given a string, we display all the combinations of the string. ex:ab and ba are same so only one is displayed*/
#include<iostream>
#include<cstring>

using namespace std;

class word
{
	public:
		word();
		int stringlen(char a[100]);
		void combinations(int depth,char combination[100],int start,char a[100],int len);
		char a[100];
		char combination[100];
		
	
		
};

word::word()
{
	int len,i,palin;
	cout<<"\nenter the word :";
	cin.getline(a,100);
	cout<<a<<endl;
	len=stringlen(a);
	
	cout<<"len="<<len<<endl;
	cout<<"the original string is "<<a<<endl;
	cout<<"the combinations of the given string are: "<<endl;

	combinations(0,combination,0,a,len);
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

void word::combinations(int depth,char combination[100],int start,char a[100],int len)
{
	
	 for(int i=start;i<len;i++)
	 {
	  
		combination[depth]=a[i];
		combination[depth+1]='\0';
		cout<<combination<<endl;
		if(i<len-1)
		combinations(depth+1,combination,start+1,a,len);
	 }
	
}


main()
{
	word word1;
	return 0;
}
	
