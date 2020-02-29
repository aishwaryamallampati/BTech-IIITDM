#include<iostream>
using namespace std;
static int l=1;


class matrix
{
public:
	matrix();
	int a[100][100];
	int size;
	void filldiagonal();
	void display();
	void fillother(int rstart,int cstart,int rend,int cend);
};

matrix::matrix()
{
	int index1,index2;
	int rstart,cstart;
	rstart=1;
	cstart=1;	
	cout<<"\nenter the number of rows of the matrix: ";
	cin>>size;
	for(index1=1;index1<=size;index1++)
	{
	 for(index2=1;index2<=size;index2++)
	 {
	  a[index1][index2]=0;
	 }
	}
	divide();
	filldiagonal();
	cout<<"\nthe matrix: "<<endl;
	display();
	cout<<"\nthe matrix: "<<endl;
	while(rstart<size)
	{
	 cstart=1;
	 cout<<rstart<<cstart;
	 while(cstart<size)
	 {	
				
		fillother(rstart,rstart+1,cstart,cstart+1);
		l++;
		cstart=cstart+2;
	 }
	 rstart=rstart+2;
	}
	
	a[1][1]=0;
	cout<<"\nthe matrix: "<<endl;
	display();
	cout<<"the total no of triominos formed ="<<(l-2)<<endl;
}

void matrix::divide()
{
	int n,row,col,counter;
	counter=1;
	n=(size/4)*(size/4);
	cout<<"total no of 4*4 matrices:"<<n<<endl;
	while(row<=(size-3)&&(counter<=n))
	{
	 while(col<=(size-3))
	 {
	  fill(r,r+3,c,c+3);
	  c=c+4;
	 }
	 r=r+4;
	 counter++;
	}
}

void matrix::fill(int rs,int re,int cs,int ce)
{
	int rstart,cstart;
	rstart=rs;
	cstart=cs;	
	filldiagonal(rs,re,cs,ce);
	cout<<"\nthe matrix: "<<endl;
	display();
	cout<<"\nthe matrix: "<<endl;
	while(rstart<re)
	{
	 cstart=cs;
	 cout<<rstart<<cstart;
	 while(cstart<ce)
	 {	
				
		fillother(rstart,rstart+1,cstart,cstart+1);
		l++;
		cstart=cstart+2;
	 }
	 rstart=rstart+2;
	}
	
	a[1][1]=0;
	cout<<"\nthe matrix: "<<endl;
	display();
	cout<<"the total no of triominos formed ="<<(l-2)<<endl;
}
 

void matrix::filldiagonal(int rs,int re,int cs,int ce)
{	
	int index1;
	for(index1=rs;index1<=re;index1++)
	{
	  a[index1][index1-1]=l;
	  a[index1][index1]=l;
	  a[index1-1][index1]=l;
	  l++;
	}
}

void matrix::display()
{
	int index1,index2;
	for(index1=1;index1<=size;index1++)
	{
	 for(index2=1;index2<=size;index2++)
	 {
	  cout<<a[index1][index2]<<" ";
	 }
	 cout<<endl;
	}
	cout<<endl;
}

void matrix::fillother(int rstart,int rend,int cstart,int cend)
{
	int index1,index2;
	for(index1=rstart;index1<=rend;index1++)
	{
	 for(index2=cstart;index2<=cend;index2++)
	 {
	  if(a[index1][index2]==0)
	   	a[index1][index2]=l;
	 }
	}
}

main()
{
	matrix matrix1;
	return 0;
}

