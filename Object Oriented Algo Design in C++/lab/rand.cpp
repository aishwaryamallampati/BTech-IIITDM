#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

main()
{
	int index1,size,i;
	time_t t;
	time(&t);
	srand((unsigned int)t);
	cout<<"\nenter the size of input: ";
		cin>>size;
	 cout<<"\nthe elements of size "<<(size)<<": ";
	 for(index1=0;index1<(size);index1++)
	 {
		cout<<rand()%3000<<" ";
	 }
	cout<<endl;	
	return 0;
}


