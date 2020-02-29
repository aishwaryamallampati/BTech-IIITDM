/*given a string, we display all the  1-1 functions of two given functions*/
#include<iostream>
#include<cstring>

using namespace std;

int count=0;

class word
{
	public:
		word();
		//int stringlen(char a[100]);
		void permutations(int depth,int permutation[100],int used[100],int a[100],int len,int r);
		int a[100];
		int permutation[100];
		int used[100];
	
		
};

word::word()
{
	int len,i,palin,r,k;
	cout<<"\nenter the cardinality of B:";
	cin>>k;
	for(int i=0;i<k;i++)
	{
	 a[i]=i+1;
	}
	//a[k]='\0';
	//cout<<"\nenter the word :";
	//cin.getline(a,100);
	//cout<<a<<endl;
	cout<<"\n enter the cardinality of A:";
	cin>>r;
	len=k;
	//len=stringlen(a);
	for(i=0;i<len;i++)
		used[i]=0;

	//cout<<"len="<<len<<endl;
	//cout<<"the original string is "<<a<<endl;
	cout<<"the 1-1 functions from A to B are: "<<endl;

	permutations(0,permutation,used,a,len,r);
}

/*int word::stringlen(char a[100])
{
	int i=0;
	while(a[i]!='\0')
	{
	 i++;
	}
	return i;
}*/

void word::permutations(int depth,int permutation[100],int used[100],int a[100],int len,int r)
{
	if(depth==r)
	{
	count++;
	for(int i=0;i<r;i++)
	{
	cout<<permutation[i]<<" ";
	}
	cout<<endl;
	}
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
	cout<<"the total number of 1-1 functions possible are "<<count<<endl;
	return 0;
}
	
