/*there would be M boys and N girls in a prom night.Each boy wants a girl who is strictly shorter than him.a girl can dance only with one boy aand vice versa.check whether every boy can get a girl*/
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


class teen
{
public:
	teen();
	void sort(int a[1000],int size);

};

teen::teen()
{
	int p[1000]={0};
	int i,j,l;
	l=0;	
	boy boys1;
	girl girls1;
	i=boys1.size;
	j=girls1.size;
	if(boys1.size>girls1.size)
	 cout<<"No,every boy wont get a girl to dance"<<endl;
	else
	{
	 cout<<"\nthe sorted array in increasing order of heights for boys is: ";
	 sort(boys1.b,boys1.size);
	 cout<<"\nthe sorted array in increasing orderof height for girls is: ";
	 sort(girls1.g,girls1.size);
	 cout<<"the dancing pairs are: ";
	 while(i>0 && j>0)
	 {
	  while(j>0)
	  {
	   if(boys1.b[i]>girls1.g[j])
	   {
		cout<<"("<<boys1.b[i]<<","<<girls1.g[j]<<")"<<" ";
		i--;
		j--;
		l++;
	   }
	   else j--;
	  }
	 }
	 if(l==boys1.size)
	 cout<<"\nyes,every boy got a girl to dance"<<endl;
	 else
	 cout<<"\nno,every boy did not get a girl to dance"<<endl;
	}
}

void teen:: sort(int a[1000],int size)
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
	teen teen1;
	end=clock();
	total_time=((double)(end-start))/(CLOCKS_PER_SEC);
	cout<<"time taken by insertion sort:"<<total_time<<endl;
	return 0;
}
	





