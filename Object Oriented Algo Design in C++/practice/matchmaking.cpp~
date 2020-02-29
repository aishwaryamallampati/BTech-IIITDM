/*A match making group selects n boys and n girls and arranges boys in decreasing order of their heigths and girls in increasing order of their heights. And if g[i]%b[i]==0 or b[i]%g[i]==0 then they are considered to be an ideal pair*/
#include<iostream>
#include<float.h>
using namespace std;

class boy
{
public:
	boy();

	int b[1000];
	int size;
};

boy::boy()
{
	int index1;
	cout<<"\nenter the  number of boys:";
	cin>>size;
	cout<<"\nenter the heights of boys in centimetres: ";
	for(index1=1;index1<=size;index1++)
	 cin>>b[index1];
}

class girl
{
public:
	girl();

	int g[1000];
	int size;
};

girl::girl()
{
	int index1;
	cout<<"\nenter the  number of girls:";
	cin>>size;
	cout<<"\nenter the heights of girls in centimetres: ";
	for(index1=1;index1<=size;index1++)
	 cin>>g[index1];
}


class match
{
public:
	match();
	void sort_asc(int a[1000],int size);
	void sort_desc(int a[1000],int size);
};

match::match()
{
	int p[1000]={0};
	int i,j,l;
	l=0;
	cout<<"\nselect equal number of boys and girls.";	
	boy boys1;
	girl girls1;
	i=boys1.size;
	j=girls1.size;
	if(boys1.size>girls1.size)
	 cout<<"No,every boy wont get a girl to dance"<<endl;
	else
	{
	 cout<<"\nthe sorted array in decreasing order of heights for boys is: ";
	 sort_desc(boys1.b,boys1.size);
	 cout<<"\nthe sorted array in increasing orderof height for girls is: ";
	 sort_asc(girls1.g,girls1.size);
	 cout<<"the matched pairs are: ";
	 while(i>0 && j>0)
	 {
	   if(boys1.b[i]%girls1.g[j]==0 || girls1.g[j]%boys1.b[i]==0)
	   {
		cout<<"("<<boys1.b[i]<<","<<girls1.g[j]<<")"<<" ";
		l++;
	   }
	   j--;
	   i--;
	 }
	 
	 cout<<"\nthe number of matched pairs are:"<<l<<endl;
	
	}
}

void match:: sort_asc(int a[1000],int size)
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

void match:: sort_desc(int a[1000],int size)
{
	int i,j,index1,key;
	
	for(j=2;j<=size;j++)
	{
	 key=a[j];
	 i=j-1;
	 while(i>0 && a[i]<key)
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
	match match1;
	end=clock();
	total_time=((double)(end-start))/(CLOCKS_PER_SEC);
	cout<<"time taken by insertion sort:"<<total_time<<endl;
	return 0;
}
	





