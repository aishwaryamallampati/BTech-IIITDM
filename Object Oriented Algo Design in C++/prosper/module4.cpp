/*program to do the following tasks (a)towes of honoi (b)l shaped triomino (c)ladder (d)circus*/
#include "module1.h"
# include"module4.h"
# include <math.h>


static int l=1;//used in triomino
static int p=0;//used in triomino
static int q=0;//used in triomino
static int z=0;//used in ladder
static int count_steps=0; 
static int b[1000]={0};//used in ladder
int counth=1;// used in circus
int countw=1;//used in circus
int radius[100];//used in towers of hanoi
int countmove=0;//used in towers of hanoi


/*towers of honoi:
INPUT:number of disks and their respective radius 
FUNCTION:the disks are transferred from one tower(TOWER A) to another tower(TOWER C) using an intermediate tower(TOWER B) 
OUTPUT:the movements of disks and number of moves is given as output*/
void module4::tower()
{
	cout<<"enter number of disks:";
	cin>>n;
	cout<<"\nenter radius for each disk:"<<endl;
	for(int index1=1;index1<=n;index1++)
		cin>>radius[index1];
	module1 m1;
	m1.insertion_sort_iterative(radius,1,n);
	cout<<"\n\n";
	hanoi(n,1,2,3);	
	cout<<"\n";
	cout << "The total no: of moves is:";
	cout<<countmove<<endl;
}
void module4::hanoi(int n,int from,int aux,int to)
{
	if(n==1)
	{
		cout<<"\n move disc 1 of radius " <<radius[1] << " from "<<from<<" to "<<to<<endl;
	 	countmove++;
		return;
	}
	else
	{
		
		hanoi(n-1,from,to,aux);
		cout<<"\n move disc "<<n <<" of radius " <<radius[n] << " from "<<from<<" to "<<to<<endl;
		countmove++;
		hanoi(n-1,aux,from,to);
	}
}



/*l shaped triomino:
INPUT:the number of rows of the square matrix to be filled with l shaped triomino
OUTPUT:the entire matrix with l shaped triominos and the total number of triominos that can fit in the matrix*/

void module4::matrix()
{
	int index1,index2;
	cout<<"\nenter the number of rows of the matrix: ";
	cin>>size;
	for(index1=1;index1<=size;index1++)
	{
	 for(index2=1;index2<=size;index2++)
	 {
	  a[index1][index2]=0;
	  used[index1][index2]=0;//to know the indices of middle 4 blocks filled initially
	 }
	}
	if(size==2)//if it is a 2*2 matrix, it can be filled with one triomino
	 {
	   a[1][1]=l;
	   a[1][2]=l;
	   a[2][1]=l;
	   l++;
	   display();
	   cout << "Total no: of triominos formed = " << 1 << endl; 
	   return;  
	 }
	if(size==4)//
	{
	 used[1][1]=1;
	}
	fillmiddle(1,size,1,size);
	//cout<<"\nthe used matrix: "<<endl;
	//display1();
	divide(1,size,1,size);
	//cout<<"\nthe used matrix: "<<endl;
	//display1();
	if(size==4)
	 {
	   a[1][1]=0;
	 }
	else
	 {
	   a[size/2][size/2]=0;
	 }
	cout<<"\nthe matrix: "<<endl;
	display();
	int result=count_triomino(size*size);
	cout<<"the total no of triominos formed ="<<(result)<<endl;
}

/*for the entire matrix the midlle 4 blocks are filled with one number then we divide the matrix until we get to a 4*4 matrix*/
void module4::fillmiddle(int rstart,int rend,int cstart,int cend)
{
	int i,j;
	if(((rend-rstart+1)!=4)&&((cend-cstart+1)!=4))
	{
	 i=((rend-rstart+1)/2)+(rstart-1);
	 j=((cend-cstart+1)/2)+(cstart-1);

	 a[i][j]=l;
	 used[i][j]=1;
	 //these are used to give the first input first priority when we have to choose between 2 inputs
	 middler[p]=i;//to store value of row 
	 middlec[q]=j;//to store value of column 
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

//to divide the matrix into 4 parts until it raches to size of 4*4 matrix recursively
void module4::divide(int rstart,int rend,int cstart,int cend)
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
//in the 4*4 matrix one box is already used that box is used to fill the diagonal of the 4*4 matrix
void module4::filldiagonal(int rs,int re,int cs,int ce)
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
	if(count==1)//this filling is done if only one box is used in the 4*4 matrix
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
	   //the above 4 are different possibiliities of filling the diagonal of 4*4 matrix
	  }
	 }
	}
       }
/*if two boxes are filled in a 4*4 matrix priority is given to one box and diagonal filling is done and priority is given using middler and middlec arrays*/
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

/*to check the number of boxes filled in a 4*4 matrix*/
int module4::check(int rs,int re,int cs,int ce)
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

/*to find a box row  and column index in middler and middlec arrays*/
int module4::find(int middler[100],int middlec[100],int r,int c)
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


void module4::filldiagonal1(int rstart,int rend,int cstart,int cend,int index1,int index2)
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

void module4::filldiagonal2(int rstart,int rend,int cstart,int cend,int index1,int index2)
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


void module4::filldiagonal3(int rstart,int rend,int cstart,int cend,int index1,int index2)
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

void module4::filldiagonal4(int rstart,int rend,int cstart,int cend,int index1,int index2)
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

/*after filling the diagonal the 4*4 matrix is divided into 2*2 matrices and other elements are filled using fill other function*/
void module4::fill(int rs,int re,int cs,int ce)
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


void module4::fillother(int rstart,int rend,int cstart,int cend)
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

void module4::display()
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

int module4::count_triomino(int size)
{
	if(size==4)
	  return 1;
	else
	  return (4 * count_triomino(size/4) + 1);
}

/*void module4::display1()//to display used matrix
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

void module4::display3()//to display middler and middlec
{
	int index1,index2;
	for(index1=0;index1<=(p-1);index1++)
	{
	  cout<<"("<<middler[index1]<<","<<middlec[index1]<<")"<<"   ";
	}
	 cout<<endl;
}*/


/*ladder:
INPUT:the number of steps is given
OUTPUT:the number of ways in which the steps can be climbed*/

void module4::steps()
{
	int result;
	cout<<"\nenter the number of steps:";
	cin>>size;
	cout<<"\nall possible ways of climbing the ladder: \n";
	ladder_path(size);
	cout<<"the total number of possibilities is "<<count_steps<<endl;
}

 void module4::ladder_path(int size)
    {
    	// since maximum length of string can be n
        char data[size+1];
     
        print_ladder_path(data,0,size);
    }

 void module4::print_ladder_path(char data[],int i,int size)
    {
    	// Base case 1
        if(size<0)
            return;
     
        // Base case 2, If n becomes 0, just print the answer
        if(size==0)
        {
            data[i]='\0';
            
		cout<<data<<endl;
		count_steps++;
            return;
        }
        // You can either put 1 and decrement n by 1
        data[i]='1';
        print_ladder_path(data,i+1,size-1);
  
        // Or you can put 2 and decrement n by 2
        data[i]='2';
        print_ladder_path(data,i+1,size-2);
   }


/*circus:
INPUT:the number of with their respective heights and weights
OUTPUT:the valid people who can participate in the circus*/

void module4::circus()
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
	cout<<endl;
}

//to sort the people using height condition
void module4:: sort_h(int h1[100],int w1[100],int size)
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

//to sort the people as per their weight condition
void module4:: sort_w(int h2[100],int w2[100],int size)
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


/*int main()
  {
    int c;
    module4 m4;
    do
      {
	cout << "1.towers of hanoi\n2.L shaped triomino\n3.Ladder\n4.circus\nEnter your choice:";
 	cin >> c;
	switch(c)
	    {
		case 1:m4.tower();
			break;
		case 2:
			m4.matrix();
			break;
		case 3:
			m4.steps();
			break;
		case 4:
			m4.circus();
			break;
		case 0:break;
	    }
      }while(c!=0);
   return 0;
  }*/
