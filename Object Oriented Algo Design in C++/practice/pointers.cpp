#include<iostream>
using namespace std;

int main()
{
	int var=20;
	int *ip;
	ip=&var;
	cout<<"\nvalue of variable:";
	cout<<var;
	cout<<"\naddress stored in ip variable:";
	cout<<ip;
	cout<<"\n value stored at *ip:";
	cout<<*ip<<endl;
}
