#include<iostream>
using namespace std;
int counth=1;
int countw=1;

class circus
{
public:
	circus();
	int h[100],w[100];
	int h1[100],w1[100];
	int h2[100],w2[100];
	int size;
	void sort_h(int h1[100],int w1[100],int size);
	void sort_w(int h2[100],int w2[100],int size);
};

circus::circus()
{	
	int i=0,j=0,half,l=1;
	int index1;
	
	cout<<"enter the number of persons: ";
	cin>>size;
	for(i=1;i<=size;i++)
	{	
		cout<<i<<" ";
		cout<<"\nenter the height of the person "<<i<<": ";
		cin>>h[i];
		h1[i]=h[i];
		h2[i]=h[i];
		cout<<"\nenter the weight of the  person "<<i<<": ";
		cin>>w[i];
		w1[i]=w[i];
		w2[i]=w[i];	
	}
	cout<<"\ngiven input:"<<endl;
	for(j=1;j<=size;j++)
	{
	 cout<<"("<<h[j]<<","<<w[j]<<")"<<" ";
	}
	cout<<endl;
	sort_h(h1,w1,size);
	sort_w(h2,w2,size);
	if(counth>=countw)
	 cout<<"the largest number of people that can participate in the circus is "<<counth<<endl;
	else
	 cout<<"the largest number of people that can participate in the circus is "<<countw<<endl;
}

void circus:: sort_h(int h1[100],int w1[100],int size)
{
	int i,j,index1,key_h,key_w,result=0,index2;
	
	for(j=2;j<=size;j++)
	{
	 key_h=h1[j];
	 key_w=w1[j];
	 i=j-1;
	 while(i>0 && h1[i]>key_h)
	 {
		h1[i+1]=h1[i];
		w1[i+1]=w1[i];
		i=i-1;
	 }
	 h1[i+1]=key_h;
	 w1[i+1]=key_w;
	}
	cout<<"the sorting done as per heights:"<<endl;
	for(index1=1;index1<=size;index1++)
	 cout<<"("<<h1[index1]<<","<<w1[index1]<<")"<<" ";
	 cout<<endl;
	cout<<"the eligibile people:"<<endl;
	cout<<"("<<h1[1]<<","<<w1[1]<<")"<<" ";
	for(index1=2;index1<=size;index1++)
	{
	 for(index2=index1-1;index2>0;index2--)
	 {
	  if(w1[index1]>w1[index2])
	  {
	   result=1;
	  }
	  else result=0;
	 }
	 if(result==1)
	 {
	   cout<<"("<<h1[index1]<<","<<w1[index1]<<")"<<" ";
	   counth++;
	 }
	}
	cout<<endl;
	cout<<"the total number of people eligible="<<counth<<endl;
}

void circus:: sort_w(int h2[100],int w2[100],int size)
{
	int i,j,index1,key_h,key_w,result,index2;
	
	for(j=2;j<=size;j++)
	{
	 key_h=h2[j];
	 key_w=w2[j];
	 i=j-1;
	 while(i>0 && w2[i]>key_w)
	 {
		h2[i+1]=h2[i];
		w2[i+1]=w2[i];
		i=i-1;
	 }
	 h2[i+1]=key_h;
	 w2[i+1]=key_w;
	}
	cout<<"the sorting done as per weights:"<<endl;
	for(index1=1;index1<=size;index1++)
	 cout<<"("<<h2[index1]<<","<<w2[index1]<<")"<<" ";
	 cout<<endl;
	cout<<"the eligibile people:"<<endl;
	cout<<"("<<h2[1]<<","<<w2[1]<<")"<<" ";
	for(index1=2;index1<=size;index1++)
	{
	 for(index2=index1-1;index2>0;index2--)
	 {
	  if(h2[index1]>h2[index1-1])
	  {
	   result=1;
	  }
	  else result=0;
	 }
	 if(result==1)
	 {
	  cout<<"("<<h2[index1]<<","<<w2[index1]<<")"<<" ";
	  countw++;
	 }
	}
	cout<<endl;
	cout<<"the total number of people eligible="<<countw<<endl;
	
}

main()
{
	circus circus1;
	return 0;
}

