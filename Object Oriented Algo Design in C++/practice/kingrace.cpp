/*there is a swayamvar being conducted for a princess.all kings have to participate in a race to win. the race have many hurdles and each king has a limit which he can jump.the king who can cross maximum hurdle is the winner and if there is a tie the king with least id no is the winner*/
#include<iostream>
#include<float.h>
using namespace std;

class king
{
public:
	king();

	int k[1000];
	int size;
};

king::king()
{
	int index1;
	cout<<"\nenter the  number of kings:";
	cin>>size;
	cout<<"\nenter the jumping strenghts of kings in centimetres: ";
	for(index1=1;index1<=size;index1++)
	 cin>>k[index1];
}

class hurdle
{
public:
	hurdle();

	int h[1000];
	int size;
};

hurdle::hurdle()
{
	int index1;
	cout<<"\nenter the  number of hurdles:";
	cin>>size;
	cout<<"\nenter the heights of each hurdle in centimetres: ";
	for(index1=1;index1<=size;index1++)
	 cin>>h[index1];
}


class race
{
public:
	race();
	void sort(int a[1000],int size);
	int find(int a[1000],int size,int key);
};

race::race()
{
	int id[1000],hurdle_max[1000];
	int i,j,l,keyindex,winnerid,duplicate=0,m;
	l=1;	
	king kings1;
	for(i=1;i<=kings1.size;i++)
		id[i]=kings1.k[i];
	hurdle hurdles1;
	i=kings1.size;
	j=hurdles1.size;

	 cout<<"\nthe sorted array in increasing order of jumping strehths of kings is: ";
	 sort(kings1.k,kings1.size);

	 keyindex=find(id,kings1.size,kings1.k[kings1.size]);
	 cout<<"key"<<keyindex<<" ";
	 winnerid=keyindex;
	 
	 cout<<"\nthe sorted array in increasing orderof height of hurdles is: ";
	 sort(hurdles1.h,hurdles1.size);

	 cout<<"the king and hurdle pairs are: ";
	 while(i>0 && j>0)
	 {
	  m=1;
	  duplicate=0;
	   if(kings1.k[i]>hurdles1.h[j])
	   {
		cout<<"("<<kings1.k[i]<<","<<hurdles1.h[j]<<")"<<" ";
		hurdle_max[l]=hurdles1.h[j];
		l++;
		while((duplicate==0)&&(m<l-1))
	   	{	
	        	
			if(hurdle_max[l-1]==hurdle_max[1])
		 		duplicate=1;
	    		m++;
	   	}
		
		if(duplicate==1)
		{
		 keyindex=find(id,kings1.size,kings1.k[i]);
	 	 if(keyindex<winnerid)
			winnerid=keyindex;
		} 
		i--;
		
	   }
	   else j--;
	 }
	 cout<<"\nthe winner id is "<<winnerid<<endl;
}

void race:: sort(int a[1000],int size)
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

int race::find(int a[1000],int size,int key)
{
	int i;
	for(i=1;i<=size;i++)
	{
		if(key==a[i])
		return i;
	}
}

main()
{
	double total_time;
	clock_t start,end;
	start=clock();
	race race1;
	end=clock();
	total_time=((double)(end-start))/(CLOCKS_PER_SEC);
	cout<<"time taken by insertion sort:"<<total_time<<endl;
	return 0;
}
	





