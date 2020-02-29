/*program to sort 100 arrays of given input size using bubble sort*/
#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;


class array
{
public:
	array();

	int a[1000];
	int size;
};/*class for array*/

array::array()
{
	int index1;
	size=20;
	for(index1=0;index1<size;index1++)
	 a[index1]=rand()%3000;
}/*constructor to initialize array by using rand() function*/

class bubblesorter
{
	public:
		bubblesorter();
};/*class for bubblesort*/

bubblesorter::bubblesorter()
{
	int pass,index1,hold;
	array array1;
	for(pass=1;pass<array1.size;pass++)
	{
	 for(index1=0;index1<array1.size-1;index1++)
	 {
	  if(array1.a[index1]>array1.a[index1+1])
	       {	
	  	hold=array1.a[index1];
		array1.a[index1]=array1.a[index1+1];
		array1.a[index1+1]=hold;
	       }
 	 }
	}
	
}/*constructor for bubble sort to sort the array*/

main()
{
	double total_time,sum=0,average;
	clock_t start,end;
	array array1;
	int index1,index2;
	double time[100];
	
	for(index1=0;index1<100;index1++)
	{
	 start=clock();
	 bubblesorter bsorter1;
	 end=clock();
	 cout<<"\nthe sorted array in increasing order is: ";
	 for(index2=0;index2<array1.size;index2++)
	 	cout<<array1.a[index2]<<" ";
	 total_time=((double)(end-start))/(CLOCKS_PER_SEC);
	 cout<<"\ntime taken for bubble sort:"<<total_time<<endl;
	 time[index1]=total_time;
	}//repeatedly create 100 random arrays and sort them
	for(index1=0;index1<100;index1++)
	{
	 sum=sum+time[index1];
	}
	average=sum/100;//to calculate average time for 100 arrays of same size
	cout<<"\naverage time taken for bubble sort:"<<average<<endl;
	return 0;
}
	
