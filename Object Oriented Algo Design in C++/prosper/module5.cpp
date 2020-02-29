#include "module5.h"
#include "module1.h"
#include "module3.h"
#include "module2.h"

//to plot (a)insertion sort iterative (b)insertion sort recursive (c)binary insertion sort (d)counting inversions
void plot::plot_m1()
{
double total_time1,sum1=0,avg1=0,total_time2,sum2=0,avg2=0;
double total_time3,sum3=0,avg3=0,total_time4,sum4=0,avg4=0;
int i,j;
	srand(time(NULL));
	cout<<"enter the size"<<"for module1"<<endl;
	cin>>n;
	for(j=1;j<=100;j++)
	{
		for(i=1;i<=n;i++)
		{
		 array[i]=rand()%100+1;
		 array2[i]=array[i];
		}
		plot_module1();
	}

for(int j=1;j<=100;j++)
{
sum1=sum1+time1[j];
sum2=sum2+time2[j];
sum3=sum3+time3[j];
sum4=sum4+time4[j];
}
avg1=sum1/100;
cout<<"avg1\t(insertion_sort_iterative)\t="<<avg1<<endl;

avg2=sum2/100;
cout<<"avg2\t(insertion recursive)\t="<<avg2<<endl;

avg3=sum3/100;
cout<<"avg3\t(binary_insertion_sort:)\t="<<avg3<<endl;

avg4=sum4/100;
cout<<"avg4\t(counting_inversions)="<<avg4<<endl;

}

void plot::plot_module1()
{
module1 m1;
int i=1,k1;
clock_t t1,t2,t3,t4,t5,t6,t7,t8;

t1=clock();
	m1.insertion_sort_iterative(array,1,n);
	//cout<<"insertion iterative:"<<endl;
	//m1.display(array,n);
t2=clock();
	total_time1=double(t2-t1)/CLOCKS_PER_SEC;
	time1[i]=total_time1;

	for(k1=1;k1<=n;k1++)
	array[k1]=array2[k1];

t3=clock();
	 m1.insertion_sort_recursive(array,n,2);
	 //cout<<"insertion recursive:"<<endl;
	 //m1.display(array,n);
t4=clock();
	total_time2=double(t4-t3)/CLOCKS_PER_SEC;
	time2[i]=total_time2;

for(k1=1;k1<=n;k1++)
	array[k1]=array2[k1];	

t5=clock();
	 m1.binary_insertion_sort(array,n);
	 //cout<<"binary_insertion_sort:"<<endl;
	 //m1.display(array,n);
t6=clock();
	total_time3=double(t6-t5)/CLOCKS_PER_SEC;
	time3[i]=total_time3;

for(k1=1;k1<=n;k1++)
	array[k1]=array2[k1];

t7=clock();
	m1.counting_inversions(array,1,n);
	//m1.display(array,n);
t8=clock();
	total_time4=double(t8-t7)/CLOCKS_PER_SEC;
	time4[i]=total_time4;

i++;

}


//to plot (a)quick sort (b) qucik sort pivot first (c)quick sort pivot middle (d)quick sort pivot random
void plot::plot_m2()
{
double total_time1,sum1=0,avg1=0,total_time2,sum2=0,avg2=0;
double total_time3,sum3=0,avg3=0,total_time4,sum4=0,avg4=0;
int i,j;
	srand(time(NULL));
	cout<<"enter the size"<<"for module2\t(quick sort and its variants)\t"<<endl;
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
cout<<"avg1\t(classical quick sort)\t="<<avg1<<endl;

avg2=sum2/100;
cout<<"avg2\t( quick sort as pivot first)\t="<<avg2<<endl;

avg3=sum3/100;
cout<<"avg3( quick sort as pivot middle)\t="<<avg3<<endl;

avg4=sum4/100;
cout<<"avg4\t( quick sort as pivot random)\t="<<avg4<<endl;

}

void plot::plot_quicksort()
{
module2 m2;
int i=1,k1;
clock_t t1,t2,t3,t4,t5,t6,t7,t8;

t1=clock();
	m2.quick_sort(array,n);
	//cout<<"sorted array using classical quick sort"<<endl;
	//m2.display(array,n);
t2=clock();
	total_time1=double(t2-t1)/CLOCKS_PER_SEC;
	time1[i]=total_time1;

	for(k1=1;k1<=n;k1++)
	array[k1]=array2[k1];

t3=clock();
	 m2.quick_pivot_first(array,n);
	 //cout<<"sorted array using quick sort as pivot first:"<<endl;
	// m2.display(array,n);
t4=clock();
	total_time2=double(t4-t3)/CLOCKS_PER_SEC;
	time2[i]=total_time2;

for(k1=1;k1<=n;k1++)
	array[k1]=array2[k1];	

t5=clock();
	 m2.quick_pivot_middle(array,n);
	// cout<<"sorted array using quick sort as pivot middle:"<<endl;
	 //m2.display(array,n);
t6=clock();
	total_time3=double(t6-t5)/CLOCKS_PER_SEC;
	time3[i]=total_time3;

for(k1=1;k1<=n;k1++)
	array[k1]=array2[k1];

t7=clock();
	m2.quick_pivot_random(array,n);
	// cout<<"sorted array using quick sort as pivotrandom:"<<endl;
	 //m2.display(array,n);
t8=clock();
	total_time4=double(t8-t7)/CLOCKS_PER_SEC;
	time4[i]=total_time4;

i++;

}


//to plot (a)insertion iterative (b)quick sort (c)quick insertion sort (d)merge insertion sort		
void plot::plot_m3()
{
double total_time1,sum1=0,avg1=0,total_time2,sum2=0,avg2=0;
double total_time3,sum3=0,avg3=0,total_time4,sum4=0,avg4=0;
int i,j;
	srand(time(NULL));
	cout<<"enter the size"<<"for module3:"<<endl;
	cin>>n;
	for(j=1;j<=100;j++)
	{
		for(i=1;i<=n;i++)
		{
		array[i]=rand()%100+1;
		array2[i]=array[i];
		}
		plot_module3();
	}

for(int j=1;j<=100;j++)
{
sum1=sum1+time1[j];
sum2=sum2+time2[j];
sum3=sum3+time3[j];
sum4=sum4+time4[j];
}
avg1=sum1/100;
cout<<"avg1\t(insertion sort iterative)\t="<<avg1<<endl;

avg2=sum2/100;
cout<<"avg2\t(classical quick sort )\t="<<avg2<<endl;

avg3=sum3/100;
cout<<"avg3\t(quick_insertion_sort)\t="<<avg3<<endl;

avg4=sum4/100;
cout<<"avg4\t(merge_insertion_sort)\t="<<avg4<<endl;

}

void plot::plot_module3()
{
module3 m3;
module1 m1;
module2 obj;
int i=1,k1;
clock_t t1,t2,t3,t4,t5,t6,t7,t8;

t1=clock();
	m1.insertion_sort_iterative(array,1,n);
	//cout<<"sorted array using insertion sort iterative:"<<endl;
	//m1.display(array,n);
t2=clock();
	total_time1=double(t2-t1)/CLOCKS_PER_SEC;
	time1[i]=total_time1;

	for(k1=1;k1<=n;k1++)
	array[k1]=array2[k1];

t3=clock();
	obj.quick_sort(array,n);
	 //cout<<"sorted array using classical quick sort :"<<endl;
	 //obj.display(array,n);
t4=clock();
	total_time2=double(t4-t3)/CLOCKS_PER_SEC;
	time2[i]=total_time2;

for(k1=1;k1<=n;k1++)
	array[k1]=array2[k1];	

t5=clock();
	m3.quick_insertion_sort(array,n);
	//cout<<"sorted array using quick_insertion_sort:"<<endl;
	 //m3.display(array,n);
	
t6=clock();
	total_time3=double(t6-t5)/CLOCKS_PER_SEC;
	time3[i]=total_time3;

for(k1=1;k1<=n;k1++)
	array[k1]=array2[k1];

t7=clock();
	 m3.merge_insertion_sort(array,n);
	 //cout<<"sorted array using merge_insertion_sort:"<<endl;
	 //m3.display(array,n);
t8=clock();
	total_time4=double(t8-t7)/CLOCKS_PER_SEC;
	time4[i]=total_time4;

i++;

}


//to plot (a)varient search (b)linear search		

void plot::plot_m4()
{
double total_time1,sum1=0,avg1=0,total_time2,sum2=0,avg2=0;
int i,j;
	srand(time(NULL));
	cout<<"enter the size"<<"for linear search plotting"<<endl;
	cin>>n;
	for(j=1;j<=100;j++)
	{
		for(i=1;i<=n;i++)
		{
		array[i]=rand()%100+1;
		array2[i]=array[i];
		}
		plot_search();
	}

for(int j=1;j<=10;j++)
{
sum1=sum1+time1[j];
sum2=sum2+time2[j];
}
avg1=sum1/10;
cout<<"avg1\t(varsearch)\t="<<avg1<<endl;

avg2=sum2/10;
cout<<"avg2\t(linear search)\t="<<avg2<<endl;

}

void plot::plot_search()
{
module3 obj1;
int i=1,k1,k;
	int j;
clock_t t1,t2,t3,t4,t5,t6,t7,t8;
int key=rand()%100 +1;
t1=clock();
	obj1.varsearch(array,n,key);
	 
t2=clock();
	total_time1=double(t2-t1)/CLOCKS_PER_SEC;
	time1[i]=total_time1;

	for(k1=1;k1<=n;k1++)
	array[k1]=array2[k1];
	 
	

t3=clock();
	for(int j=1;j<=n;j++)
	  {
	     if(key==array[j]);
		break;
	  }
	
t4=clock();
	total_time2=double(t4-t3)/CLOCKS_PER_SEC;
	time2[i]=total_time2;
	

i++;

}

/*int main()
{
plot r;
	r.plot_m1();
	r.plot_module1();
	r.plot_m2();
	r.plot_quicksort();
	r.plot_m3();
	r.plot_module3();
	r.plot_m4();	
	r.plot_search();
return 0;
}*/



