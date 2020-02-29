/*given points in 2-D plane we return the distance between closest pair of points*/
#include<iostream>
#include<math.h>
#include<float.h>
using namespace std;

class point
{
public:
	point();
	int x[100],y[100];
	int xi[100],yi[100];
	int size;
	void sort_x(int x[100],int y[100],int size);
	void sort_y(int x[100],int y[100],int size);
	float min_distance(int x[100],int y[100],int start,int end);
};


point::point()
{	
	int i=0,j=0,half,l=1;
	float lmin,rmin,min,min2;
	
	cout<<"enter the number of points: ";
	cin>>size;
	for(i=1;i<=size;i++)
	{	
		cout<<i<<" ";
		cout<<"\nenter the x coordinate of point "<<i<<": ";
		cin>>x[i];
		cout<<"\nenter the y coordinate of point "<<i<<": ";
		cin>>y[i];	
	}
	for(j=1;j<=size;j++)
	{
	 cout<<"("<<x[j]<<","<<y[j]<<")"<<" ";
	}
	cout<<endl;
	cout<<"the sorted poins in terms of x coordinates are:"<<endl;
	sort_x(x,y,size);

	half=size/2;
	lmin=min_distance(x,y,1,half);
	rmin=min_distance(x,y,half+1,size);
	if(lmin<rmin)
	 min=lmin;
	else
	 min=rmin;
	cout<<"lmin="<<lmin<<" "<<"min="<<min<<" "<<"rmin="<<rmin<<endl;

	for(j=1;j<=half;j++)
	{
	 if((x[half]-x[j])<min)
	 {
	  xi[l]=x[j];
	  yi[l]=y[j];
	  l++;
	 }
	}
	for(j=half+1;j<=size;j++)
	{
	 if((x[j]-x[half])<min)
	 {
	  xi[l]=x[j];
	  yi[l]=y[j];
	  l++;
	 }
	}
	cout<<"sorting the picked points in terms of y:"<<endl;
	sort_y(xi,yi,l-1);
	min2=min_distance(xi,yi,1,l-1);
	if(min2<min)
		min=min2;
	cout<<"the closest distance is :"<<min<<endl;
}

void point:: sort_x(int x[100],int y[100],int size)
{
	int i,j,index1,key_x,key_y;
	
	for(j=2;j<=size;j++)
	{
	 key_x=x[j];
	 key_y=y[j];
	 i=j-1;
	 while(i>0 && x[i]>key_x)
	 {
		x[i+1]=x[i];
		y[i+1]=y[i];
		i=i-1;
	 }
	 x[i+1]=key_x;
	 y[i+1]=key_y;
	}
	
	for(index1=1;index1<=size;index1++)
	 cout<<"("<<x[index1]<<","<<y[index1]<<")"<<" ";
	 cout<<endl;
}

void point:: sort_y(int x[100],int y[100],int size)
{
	int i,j,index1,key_x,key_y;
	
	for(j=2;j<=size;j++)
	{
	 key_x=x[j];
	 key_y=y[j];
	 i=j-1;
	 while(i>0 && y[i]>key_y)
	 {
		x[i+1]=x[i];
		y[i+1]=y[i];
		i=i-1;
	 }
	 x[i+1]=key_x;
	 y[i+1]=key_y;
	}
	
	for(index1=1;index1<=size;index1++)
	 cout<<"("<<x[index1]<<","<<y[index1]<<")"<<" ";
	 cout<<endl;
}

float point::min_distance(int x[100],int y[100],int start,int end)
{
	float distance,min;
	int i,j;
	min=sqrt((x[1]-x[2])*(x[1]-x[2])+(y[1]-y[2])*(y[1]-y[2]));
	for(i=start;i<=end;i++)
	{
	 for(j=i+1;j<=end;j++)
	 {
	  distance=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
	  if(distance<min)
	   	min=distance;
	 }
	}
	return min;
}

main()
{
	point points1;
	return 0;
}
