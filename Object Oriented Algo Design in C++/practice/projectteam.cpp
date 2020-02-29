/*a proffesor assigns a project and tells students to form groups of size 2.Each student has his own level of intelligence.the level of intelligence of group is sum of both. Form groups such that difference between sum of most intelligent and least intelligent is minimum*/
#include<iostream>
#include<float.h>
using namespace std;


class student
{
public:
	student();

	int s[1000];
	int size;
};

student::student()
{
	int index1;
	cout<<"\nenter the  number of students:";
	cin>>size;
	cout<<"\nenter the  knowledge level of each student: ";
	for(index1=1;index1<=size;index1++)
	 cin>>s[index1];
}


class team
{
public:
	team();
	void sort(int a[1000],int size);
	int find_max(int a[1000],int size);
	int find_min(int a[1000],int size);

};

team::team()
{
	int sum[1000]={0};
	int i,j,l,result,max,min;
	
	l=0;	
	
	student students1;
	i=1;
	j=students1.size;
	
	 cout<<"\nthe sorted array in increasing order of knowledge level of student is: ";
	 sort(students1.s,students1.size);
	 while(i<=(students1.size)/2)
	 {
		cout<<"("<<students1.s[i]<<","<<students1.s[j]<<")"<<" ";
		sum[i]=students1.s[i]+students1.s[j];
		i++;
		j--;
	 }
	 max=find_max(sum,i-1);
	 min=find_min(sum,i-1);
	 result=max-min;
	 cout<<"\nthe difference between max and min intelligent group is "<<result<<endl;
}

void team:: sort(int a[1000],int size)
{
	int i,j,index1,key;
	
	for(j=2;j<=size;j++)
	{
	 key=a[j];
	 i=j-1;
	 while(i>0 && a[i]>key)
	 {
		a[i+1]=a[i];
		i=i-1;
	 }
	 a[i+1]=key;
	}
	
	for(index1=1;index1<=size;index1++)
	 cout<<a[index1]<<" ";
	 cout<<endl;
}

int team::find_max(int a[1000],int size)
{
	int max=a[1];
	int i;
	for(i=2;i<=size;i++)
	{
		if(max<a[i])
		 max=a[i];
	}
	return max;
}

int team::find_min(int a[1000],int size)
{
	int min=a[1];
	int i;
	for(i=2;i<=size;i++)
	{
		if(min>a[i])
		 min=a[i];
	}
	return min;
}

main()
{
	double total_time;
	clock_t start,end;
	start=clock();
	team team1;
	end=clock();
	total_time=((double)(end-start))/(CLOCKS_PER_SEC);
	cout<<"time taken by insertion sort:"<<total_time<<endl;
	return 0;
}
	





