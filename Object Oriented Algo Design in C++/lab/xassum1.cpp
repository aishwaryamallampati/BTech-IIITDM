/*program to find x,y,z such that x=y+z*/
#include<iostream>
#include<cstring>

using namespace std;

class array
{
	public:
		void enterarray();
		void sortarray();
		void findarray();
		int search(int key);
		void print();
	private:
		int a[100];
		int size;
};

void array::enterarray()
{
	int index1;
	cout<<"\nenter the size of the array: ";
	cin>>size;
	cout<<"\nenter the array: ";
	for(index1=0;index1<size;index1++)
	 cin>>a[index1];
}/*to take input array*/

void array::print()
{
	int index1;
	cout<<"\nthe array is : ";
	for(index1=0;index1<size;index1++)
	 cout<<a[index1] ;
}/*to print the array*/

void array::sortarray()
{
	int pass,index1,temp;
	for(pass=0;pass<size-1;pass++)
	{
	 for(index1=0;index1<size-1;index1++)
	 {
	  if(a[index1]>a[index1+1])
	  {
	   temp=a[index1];
	   a[index1]=a[index1+1];
	   a[index1+1]=temp;
	  }
	 }
	}
}/*to sort the elements of the array in increasing order*/

void array::findarray()
{
	int index1,index2,result,key,counter=0;
	for(index1=0;index1<size;index1++)
	{
	 for(index2=0;index2<size;index2++)
	 {
		key=a[index1]+a[index2];
		result=search(key);
		if(result==1)
		{
		 cout<<a[index1]<<" "<<a[index2]<<" "<<key<<" form a pair"<<endl;
		 counter++;
		}
	 }
	}
	if(counter==0)
	cout<<"\nthere are no such pairs"<<endl;
}/*to find the x,y,z values such that x=y+z*/

int array::search(int key)
{
	int index1;
	for(index1=0;index1<size;index1++)
	{
	 if(key==a[index1])
	 return 1;
	}
	return 0;
}/*to check whether given element exists  in the array or not*/

	
main()
{
	array array1;
	array1.enterarray();
	array1.sortarray();
	array1.findarray();
	
	return 0;
}


