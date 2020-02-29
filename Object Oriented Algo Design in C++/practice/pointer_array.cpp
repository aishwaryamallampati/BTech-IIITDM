//understanding pointers from array context
#include<iostream>
using namespace std;
#define max 3

int main()
{
	int i;
	int var[max];
	int *ptr;
	ptr=var;
	cout<<"\ncase 1: initializing from i=0"<<endl;
	cout<<"enter 3 elements:";
	for(i=0;i<max;i++)
	{
	 cin>>var[i];
	}
	for(i=0;i<max;i++)
	{
	 cout<<"\naddress of var["<<i<<"]=";
	 cout<<ptr;
	 cout<<"\nvalue of var["<<i<<"]=";
	 cout<<*ptr;
	 ptr++;//pointer points to next location
	} 
	
	int var1[max+1];
	int *ptr1;
	ptr1=var1;
	cout<<"\ncase 2:intializing from i=1"<<endl;
	cout<<"enter 3 elements:";
	for(i=1;i<=max;i++)
	{
	 cin>>var1[i];
	}
	for(i=1;i<=max;i++)
	{
	 cout<<"\naddress of var1["<<i<<"]=";
	 cout<<ptr1;
	 cout<<"\nvalue of var1["<<i<<"]=";
	 cout<<*ptr1;
	 ptr1++;//pointer points to next location
	}
}

//while using pointers to traverse through an array to print it the array must be initialized from i=0


