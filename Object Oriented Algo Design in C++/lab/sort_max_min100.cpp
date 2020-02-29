/*program to sort 100 arrays of given input size calling max and min  function alternatively*/
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
	size=50;
	
	for(index1=0;index1<size;index1++)
	 a[index1]=rand()%3000;
}/*constructor to initialize array by using rand() function*/


class sorter
{
	public:
		sorter();
		void sort_max(int a[1000],int start,int size);
		void sort_min(int a[1000],int start,int size);
		int findmax(int a[1000],int start,int size);
};/*class for sorter*/

sorter::sorter()
{
	int index1,result,start,hold,end;
	array array1;
	end=(array1.size)-1;
	
	 for(start=0;start<((array1.size)/2);start++)
	 {
	
		sort_max(array1.a,start,end+1);
	 
	 	sort_min(array1.a,start+1,end+1);
		end--;
	 }	
}/*constructor for  sorter to sort the array by calling max min alternatively*/

void sorter::sort_max(int a[1000],int start,int size)
{
	int result,hold;
	result=findmax(a,start,size);	
	  hold=a[start];
	  a[start]=a[result];
	  a[result]=hold;
}/*to find max and swap it with the first position of the array*/

void sorter::sort_min(int a[1000],int start,int size)
{
	int result,hold,index1;
	for(index1=start;index1<size;index1++)
		a[index1]=-(a[index1]);
	result=findmax(a,start,size);	
	  hold=a[size-1];
	  a[size-1]=a[result];
	  a[result]=hold;
	for(index1=start;index1<size;index1++)
		a[index1]=-(a[index1]);
}/*to find min in the given array and swap it with the last element of the passed array*/

int sorter::findmax(int a[1000],int start,int size)
{
	int index1,max,max_i;
	max=a[start];
	max_i=start;
	for(index1=start+1;index1<size;index1++)
	{
	 if(max<a[index1])
	  {
	   max=a[index1];
	   max_i=index1;
	  }
	}
	return max_i;
}/*to find maximum element int he given array and return its position*/

		

main()
{
	double total_time,sum=0,average;
	clock_t start,end;
	int index1,index2;
	double time[100];
	array array1;
	for(index1=0;index1<100;index1++)
	{
	 start=clock();
	 sorter sorter1;
	 end=clock();
	 cout<<"\nthe sorted array using max and min alternatively is: ";
	 for(index2=0;index2<array1.size;index2++)
	 	cout<<array1.a[index2]<<" ";
	 total_time=((double)(end-start))/(CLOCKS_PER_SEC);
	 cout<<"time taken for sort using max and min:"<<total_time<<endl;
	 time[index1]=total_time;
	}
	for(index1=0;index1<100;index1++)
	{
	 sum=sum+time[index1];
	}
	average=sum/100;
	cout<<"\naverage time taken for sort_max_min:"<<average<<endl;
	return 0;
}//repeatedly create 100 random arrays and sort them

