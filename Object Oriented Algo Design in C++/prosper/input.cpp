#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

class input_gen
{
	public:
		input_gen();
};

input_gen::input_gen()
{
int n,i,array[200],j;
	srand(time(NULL));
	cout<<"enter the size"<<endl;
	cin>>n;
	for(j=0;j<10;j++)
	{
		for(i=0;i<n;i++)
		array[i]=rand()%100+1;
		cout<<"\n";
		for(i=0;i<n;i++)
		cout<<array[i]<<" ";
	}
}
int main()
{
input_gen r;
return 0;
}
