#include<iostream>
using namespace std;
static int l=1;
static int p=0;
static int q=0;

class matrix
{
public:
	matrix();
	int a[100][100];
	int used[100][100];
	int middler[100];
	int middlec[100];
	int size;

	void fillmiddle(int rstart,int rend,int cstart,int cend);
	void divide(int rstart,int rend,int cstart,int cend);
	void filldiagonal(int rs,int re,int cs,int ce);
	int check(int rs,int re,int cs,int ce);
	int find(int middler[100],int middlec[100],int r,int c);
	void filldiagonal1(int rstart,int rend,int cstart,int cend,int index1,int index2);
	void filldiagonal2(int rstart,int rend,int cstart,int cend,int index1,int index2);
	void filldiagonal3(int rstart,int rend,int cstart,int cend,int index1,int index2);
	void filldiagonal4(int rstart,int rend,int cstart,int cend,int index1,int index2);
	void fill(int rs,int re,int cs,int ce);
	void fillother(int rstart,int rend,int cstart,int cend);
	void display();
	void display1();
	void display3();
};


matrix::matrix()
{
	int index1,index2;
	cout<<"\nenter the number of rows of the matrix: ";
	cin>>size;
	for(index1=1;index1<=size;index1++)
	{
	 for(index2=1;index2<=size;index2++)
	 {
	  a[index1][index2]=0;
	  used[index1][index2]=0;
	 }
	}
	if(size==4)
	{
	 used[1][1]=1;
	}
	fillmiddle(1,size,1,size);
	//cout<<"\nthe used matrix: "<<endl;
	//display1();
	divide(1,size,1,size);
	//cout<<"\nthe used matrix: "<<endl;
	//display1();
	cout<<"\nthe matrix: "<<endl;
	display();
	cout<<"the total no of triominos formed ="<<(l)<<endl;
}

void matrix::fillmiddle(int rstart,int rend,int cstart,int cend)
{
	int i,j;
	if(((rend-rstart+1)!=4)&&((cend-cstart+1)!=4))
	{
	 i=((rend-rstart+1)/2)+(rstart-1);
	 j=((cend-cstart+1)/2)+(cstart-1);

	 a[i][j]=l;
	 used[i][j]=1;
	 middler[p]=i;
	 middlec[q]=j;
	 p++;
	 q++;
	
	 a[i+1][j]=l;
	 used[i+1][j]=1;
	 middler[p]=i+1;
	 middlec[q]=j;
	 p++;
	 q++;

	 a[i][j+1]=l;
	 used[i][j+1]=1;
	 middler[p]=i;
	 middlec[q]=j+1;
	 p++;
	 q++;

	 a[i+1][j+1]=l;
	 used[i+1][j+1]=1;
	 middler[p]=i+1;
	 middlec[q]=j+1;
	 p++;
	 q++;
	 l++;
	}
	else
	return;
}
void matrix::divide(int rstart,int rend,int cstart,int cend)
{
	if((((rend-rstart)+1)==4)&&(((cend-cstart)+1)==4))
	{
	 filldiagonal(rstart,rend,cstart,cend);
	 //cout<<"returned"<<endl;
	 //cout<<"rs="<<rstart<<" "<<"re="<<rend<<" "<<"cs="<<cstart<<" "<<"ce="<<cend<<endl;
	 fill(rstart,rend,cstart,cend);
	}
	else
	{
	   //cout<<rstart<<" "<<((((rend-rstart)+1)/2)+rstart-1)<<" "<<cstart<<" "<<((((cend-cstart)+1)/2)+cstart-1)<<endl;
	   fillmiddle(rstart,((((rend-rstart)+1)/2)+rstart-1),cstart,((((cend-cstart)+1)/2)+cstart-1));		 	
	  divide(rstart,((((rend-rstart)+1)/2)+rstart-1),cstart,((((cend-cstart)+1)/2)+cstart-1));

	  //cout<<rstart<<" "<<((((rend-rstart)+1)/2)+rstart-1)<<" "<<(((cend-cstart+1)/2)+cstart)<<" "<<cend<<endl;
	  fillmiddle(rstart,((((rend-rstart)+1)/2)+rstart-1),(((cend-cstart+1)/2)+cstart),cend);
	  divide(rstart,((((rend-rstart)+1)/2)+rstart-1),(((cend-cstart+1)/2)+cstart),cend);
	 
	  //cout<<((((rend-rstart)+1)/2)+rstart)<<" "<<rend<<" "<<cstart<<" "<<((((cend-cstart)+1)/2)+cstart-1)<<endl;
	  fillmiddle(((((+rend-rstart)+1)/2)+rstart),rend,cstart,((((cend-cstart)+1)/2)+cstart-1));
	  divide(((((rend-rstart)+1)/2)+rstart),rend,cstart,((((cend-cstart)+1)/2)+cstart-1));
	   //cout<<"entered"<<endl;
	  //cout<<((((rend-rstart)+1)/2)+rstart)<<" "<<rend<<" "<<((((cend-cstart)+1)/2)+cstart)<<" "<<cend<<endl;
	  fillmiddle(((((rend-rstart)+1)/2)+rstart),rend,((((cend-cstart)+1)/2)+cstart),cend);
	  divide(((((rend-rstart)+1)/2)+rstart),rend,((((cend-cstart)+1)/2)+cstart),cend);
	 
	}
}

void matrix::filldiagonal(int rs,int re,int cs,int ce)
{
	int u,v;	
	//cout<<"\nthe used matrix: "<<endl;
	//display1();	

	//cout<<"rs="<<rs<<" "<<"re="<<re<<" "<<"cs="<<cs<<" "<<"ce="<<ce<<endl;
	int temp,k,cnt;
	
	int index1,index2;
	index1=rs;
	index2=cs;
	//cout<<"index1="<<index1<<" "<<"index2="<<index2<<endl;	
	int count=check(rs,re,cs,ce);
	//cout<<"count="<<count<<endl;
	if(count==1)
	{
	 for(index1=rs;index1<=re;index1++)
	 {
	 for(index2=cs;index2<=ce;index2++)
	 {
	  if(used[index1][index2]==1)
	  {
	   //cout<<"index1="<<index1<<" "<<"index2="<<index2<<endl;
	   if(index1==re&&index2==ce)
	   filldiagonal1(rs,re,cs,ce,index1,index2);
  	   else if(index1==re&&index2==cs)
	    filldiagonal2(rs,re,cs,ce,index1,index2);
	   else if(index1==rs&&index2==ce)
	   filldiagonal3(rs,re,cs,ce,index1,index2);
	   else if(index1==rs&&index2==cs)
	   filldiagonal4(rs,re,cs,ce,index1,index2);
	  }
	 }
	}
       }
	else if(count==2)
	{
	 //cout<<"the middle array:";
	 //display3();
	 cnt=0;
	 for(index1=rs;index1<=re;index1++)
	 {
	 for(index2=cs;index2<=ce;index2++)
	 {
	  //cout<<"index1="<<index1<<" "<<"index2="<<index2<<endl;	
	  if(used[index1][index2]==1)
	  {
	   k=find(middler,middlec,index1,index2);
	   //cout<<"k="<<k<<endl;
	   cnt++;
	  }
	  if(cnt==1)
	   temp=k;
	  else if(cnt>1&&k<temp)
	  {
	   u=middler[temp];
	   v=middlec[temp];
	   a[u][v]=0;
	   temp=k;
	   //cout<<"temp="<<temp<<endl;
	  }
	  
	 }
         }
	 
	 index1=middler[temp];
	 index2=middlec[temp];
	 //cout<<"index1="<<index1<<" "<<"index2="<<index2<<endl;
	   if(index1==re&&index2==ce)
	   {
	    
	   filldiagonal1(rs,re,cs,ce,index1,index2);
		return;
	   }
  	   else if(index1==re&&index2==cs)
	   filldiagonal2(rs,re,cs,ce,index1,index2);
	   else if(index1==rs&&index2==ce)
	   filldiagonal3(rs,re,cs,ce,index1,index2);
	   else if(index1==rs&&index2==cs)
	   filldiagonal4(rs,re,cs,ce,index1,index2);
	}
}

int matrix::check(int rs,int re,int cs,int ce)
{	
	int index1,index2,count;
	count=0;
	for(index1=rs;index1<=re;index1++)
	{
	 for(index2=cs;index2<=ce;index2++)
	 {
	  if(used[index1][index2]==1)
	  {
	   count++;
	  }
	 }
	}
	return count;
}

int matrix::find(int middler[100],int middlec[100],int r,int c)
{
	int i=0;
	while(i<=(p-1))
	{
	 if(middler[i]==r&&middlec[i]==c)
	 return i;
	 else
	 i++;
	}
}

void matrix::filldiagonal1(int rstart,int rend,int cstart,int cend,int index1,int index2)
{
	int i=index1;
	int j=index2;
	//cout<<"rs="<<rstart<<" "<<"re="<<rend<<" "<<"cs="<<cstart<<" "<<"ce="<<cend<<endl;
	//cout<<"index1="<<i<<" "<<"index2="<<j<<endl;	
	while(i>=rstart&&j>=cstart)
	{
	 i=i-1;
	 j=j-1;
	 //display();
	 a[i][j]=l;
	 a[i+1][j]=l;
	 a[i][j+1]=l;
	 l++;
	}	
}

void matrix::filldiagonal2(int rstart,int rend,int cstart,int cend,int index1,int index2)
{
	//cout<<"entered"<<endl;
	int i=index1;
	int j=index2;
	while(i>=rstart&&j<=cend)
	{
	 i=i-1;
	 j=j+1;
	 a[i][j]=l;
	 a[i][j-1]=l;
	 a[i+1][j]=l;
	 l++;
	}	
}


void matrix::filldiagonal3(int rstart,int rend,int cstart,int cend,int index1,int index2)
{
	int i=index1;
	int j=index2;
	while(i<=rend&&j>=cstart)
	{
	 i=i+1;
	 j=j-1;
	 a[i][j]=l;
	 a[i-1][j]=l;
	 a[i][j+1]=l;
	 l++;
	}	
}

void matrix::filldiagonal4(int rstart,int rend,int cstart,int cend,int index1,int index2)
{
	int i=index1;
	int j=index2;
	while(i<=rend&&j<=cend)
	{
	 i=i+1;
	 j=j+1;
	 a[i][j]=l;
	 a[i-1][j]=l;
	 a[i][j-1]=l;
	 l++;
	}	
}

void matrix::fill(int rs,int re,int cs,int ce)
{
	//cout<<"entered"<<endl;	
	
	int rstart=0,cstart=0;
	rstart=rs;
	cstart=cs;
	//cout<<"rs="<<rs<<" "<<"re="<<re<<" "<<"cs="<<cs<<" "<<"ce="<<ce<<endl;
	//cout<<"rstart="<<rstart<<endl;
	while(rstart<re&&cstart<ce)
	{
	 while(cstart<ce)
	 {		
		 fillother(rstart,rstart+1,cstart,cstart+1);
		 l++;
		cstart=cstart+2;
	 }
	 cstart=cs;
	 rstart=rstart+2;
	}
	//display();
	//cout<<"end"<<endl;
}


void matrix::fillother(int rstart,int rend,int cstart,int cend)
{
	//cout<<"entered"<<" "<<"rs="<<rstart<<" "<<"re="<<rend<<" "<<"cs="<<cstart<<" "<<"ce="<<cend<<endl;
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

void matrix::display()
{
	int index1,index2;
	for(index1=1;index1<=size;index1++)
	{
	 for(index2=1;index2<=size;index2++)
	 {
	  cout<<a[index1][index2]<<"   ";
	 }
	 cout<<endl;
	}
	cout<<endl;
}

void matrix::display1()
{
	int index1,index2;
	for(index1=1;index1<=size;index1++)
	{
	 for(index2=1;index2<=size;index2++)
	 {
	  cout<<used[index1][index2]<<"   ";
	 }
	 cout<<endl;
	}
	cout<<endl;
}

void matrix::display3()
{
	int index1,index2;
	for(index1=0;index1<=(p-1);index1++)
	{
	  cout<<"("<<middler[index1]<<","<<middlec[index1]<<")"<<"   ";
	}
	 cout<<endl;
}



main()
{
	matrix matrix1;
	return 0;
}

