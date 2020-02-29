/*given a string, we display all the permutations of the string*/
#include<iostream>
#include<cstring>

using namespace std;

class word
{
	public:
		word();
		int stringlen(char a[100]);
		void permutations(int depth,char permutation[100],int used[100],char a[100],int len,int r);
		char a[100];
		char permutation[100];
		int used[100];
	
		
};

word::word()
{
	int len,i,palin,r;
	cout<<"\nenter the word :";
	cin.getline(a,100);
	cout<<a<<endl;
	cout<<"\n enter the len:";
	cin>>r;
	len=stringlen(a);
	for(i=0;i<len;i++)
		used[i]=0;

	cout<<"len="<<len<<endl;
	cout<<"the original string is "<<a<<endl;
	cout<<"the permutations of the given string are: "<<endl;

	permutations(0,permutation,used,a,len,r);
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

void word::permutations(int depth,char permutation[100],int used[100],char a[100],int len,int r)
{
	if(depth==r)
	cout<<permutation<<endl;
	else
	{
	 for(int i=0;i<len;i++)
	 {
	  if(!used[i])
	  {
		used[i]=1;
		permutation[depth]=a[i];
		permutations(depth+1,permutation,used,a,len,r);
		used[i]=0;
	  }
	 }
	}
}


main()
{
	word word1;
	return 0;
}
	
