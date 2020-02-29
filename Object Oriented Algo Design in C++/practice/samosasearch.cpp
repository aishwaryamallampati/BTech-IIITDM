/*A boy has k units of money.he wants to eat samosa.There are n shops in a street and each has only one samosa.Find the maximum number of samosas the boy can eat*/
#include<iostream>
#include<float.h>
using namespace std;

class boy
{
public:
	boy();

	
	int amount;
};

boy::boy()
{
	int index1;
	cout<<"\nenter the  amount that boy has:";
	cin>>amount;
}

class shop
{
public:
	shop();

	int s[1000];
	int size;
};

shop::shop()
{
	int index1;
	cout<<"\nenter the  number of shops:";
	cin>>size;
	cout<<"\nenter the  cost of samosa in each shop: ";
	for(index1=1;index1<=size;index1++)
	 cin>>s[index1];
}


class samosa
{
public:
	samosa();
	void sort(int a[1000],int size);

};

samosa::samosa()
{
	int p[1000]={0};
	int i,j,l,sum;
	sum=0;
	l=0;	
	boy boy1;
	shop shops1;
	
	j=shops1.size;
	
	 cout<<"\nthe sorted array in increasing order of cost of samosa in each shop is: ";
	 sort(shops1.s,shops1.size);
	 for(i=0;i<=j;i++)
		sum=sum+shops1.s[i];
	 
	 while(sum>0 && j>0)
	 {
	   if(boy1.amount>=sum)
	   {
		cout<<"total no of samosas boy can eat: "<<j<<endl;
		break;
	   }
	   else 
	   {	
		sum=sum-shops1.s[j];
		j--;
	   }			  
	 }
}

void samosa:: sort(int a[1000],int size)
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

main()
{
	double total_time;
	clock_t start,end;
	start=clock();
	samosa samosa1;
	end=clock();
	total_time=((double)(end-start))/(CLOCKS_PER_SEC);
	cout<<"time taken by insertion sort:"<<total_time<<endl;
	return 0;
}
	




