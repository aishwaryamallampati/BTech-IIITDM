#include<iostream>
#include<stdlib.h>
#include "module2.h"
#include<ctime>
using namespace std;

class plot
{
	public:
		plot();
		
		void plot_quicksort();
		int array[200],array2[200],n;
		double total_time1,sum1,avg1,total_time2,sum2,avg2;
		double total_time3,sum3,avg3,total_time4,sum4,avg4;
		double time1[200],time2[200],time3[200],time4[200];
		
};

plot::plot()
{
double total_time1,sum1=0,avg1=0,total_time2,sum2=0,avg2=0;
double total_time3,sum3=0,avg3=0,total_time4,sum4=0,avg4=0;
int i,j;
	srand(time(NULL));
	cout<<"enter the size"<<endl;
	cin>>n;
	for(j=1;j<=100;j++)
	{
		for(i=1;i<=n;i++)
		{
		array[i]=rand()%100+1;
		array2[i]=array[i];
		}
		plot_quicksort();
	}

for(int j=1;j<=100;j++)
{
sum1=sum1+time1[j];
sum2=sum2+time2[j];
sum3=sum3+time3[j];
sum4=sum4+time4[j];
}
avg1=sum1/100;
cout<<"avg1="<<avg1<<endl;

avg2=sum2/100;
cout<<"avg2="<<avg2<<endl;

avg3=sum3/100;
cout<<"avg3="<<avg3<<endl;

avg4=sum4/100;
cout<<"avg4="<<avg4<<endl;

}

void plot::plot_quicksort()
{
operation o1;
int i=1,k1;
clock_t t1,t2,t3,t4,t5,t6,t7,t8;

t1=clock();
	o1.quick_sort(array,n);
t2=clock();
	total_time1=double(t2-t1)/CLOCKS_PER_SEC;
	time1[i]=total_time1;

	for(k1=1;k1<=n;k1++)
	array[k1]=array2[k1];

t3=clock();
	 o1.quick_pivot_first(array,n);
t4=clock();
	total_time2=double(t4-t3)/CLOCKS_PER_SEC;
	time2[i]=total_time2;

for(k1=1;k1<=n;k1++)
	array[k1]=array2[k1];	

t5=clock();
	 o1.quick_pivot_middle(array,n);
t6=clock();
	total_time3=double(t6-t5)/CLOCKS_PER_SEC;
	time3[i]=total_time3;

for(k1=1;k1<=n;k1++)
	array[k1]=array2[k1];

t7=clock();
	o1.quick_pivot_random(array,n);
t8=clock();
	total_time4=double(t8-t7)/CLOCKS_PER_SEC;
	time4[i]=total_time4;

i++;

}

int main()
{
plot r;
return 0;
}
