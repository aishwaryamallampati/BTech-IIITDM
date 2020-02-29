/* 

Given an input array , this module performs sorting using the following functions

a. quick sort which uses last element as pivot
b. quick sort which uses middle element as pivot
c. quick sort which uses first element as pivot
d. quick sort which uses random element as pivot

  and displays the sorted array.

*/

#include "module2.h"


void module2::initialization()	// Function which gets the input array
 {
      int i;
      
      cout<<"enter the n"<<endl;
      cin>>size;

      cout<<"enter integer array"<<endl;
	 
        for(i=1;i<=size;i++)
	   {
	      cin>>array[i];
	   }
	
 }


void module2::quick(int a2[200],int p2,int r2)  // Quick sort with last element as pivot
 {
        int q;
	
        if(p2<r2)                     
	   {
	     q=parti(a2,p2,r2);
	     quick(a2,p2,q-1);
	     quick(a2,q+1,r2);
	   }
 }


void module2::quick_sort(int array[200],int size)   // Function which calls quick sort which uses last element as pivot
 {
	quick(array,1,size);
 }

void module2::quick_pivot_middle(int array[200],int size) // Quick sort with middle element as pivot
  {
	
      int temp=array[size/2];
      array[size/2]=array[size];
      array[size]=temp;

      quick(array,1,size);
  }

void module2::quick_pivot_first(int array[200],int size)   // Quick sort with first element as pivot
 {
       int temp=array[1];
       array[1]=array[size];
       array[size]=temp;

       quick(array,1,size);
		
 }	

void module2::quick_pivot_random(int array[200],int size)   // Quick sort which randomly chooses the array element as pivot 
  {
	int ran=rand()%size+1;
        int temp=array[ran];
        array[ran]=array[size];
        array[size]=temp;

        quick(array,1,size);
	
  }


int module2::parti(int a[200],int p,int r)  // Partition for quick sort
   {
       int j,x,t,t1,i,l;
       x=a[r];                  // a[r](last element) is assigned as pivot
       i=p-1;
         
       for(j=p;j<r;j++)
           {
              if(a[j]<=x)       // swap happens when a[j] is less than pivot
	        {
	          i=i+1;
	          t=a[i];
	          a[i]=a[j];
	          a[j]=t;
	        }
           }
       
       t1=a[r];                 
       a[r]=a[i+1];
       a[i+1]=t1;

       return i+1;               
  }	

void module2::display(int array[1000],int size)    // Function which displays the output 
  {
	
	cout<<"\ndisplay:"<<endl;
	
        for(int index1=1;index1<=size;index1++)
           {
	    cout << array[index1] << " ";
           }
	
        cout<<endl;
  }


/*int main()
 {
	int a,p;
	module2 o;
 

     do
        {
	
        cout<<"enter 1:quick sort\n 2:quick sort pivot as first\n 3:quick sort pivot as middle\n 4:quick sort pivot as random"<<endl;
	cin>>a;
	
                if(a==1)
		o.quick_sort();
	else 
                if(a==2)
		o.quick_pivot_first();
	else 
                if(a==3)
		o.quick_pivot_middle();
	else 
		o.quick_pivot_random();
	
        cout<<"press 1 to continue"<<endl;
	cin>>p;
        

        }while(p==1);

        return 0;
 }*/
