#include "module3.h"
#include "module1.h"

void module3::initialization() //Taking array input from user
{
      int k;
      cout << "Enter size of array:";
      cin >> size;
      cout << "Enter data" << endl;
      for(k=1;k<=size;k++)
	{
	   cin >> array[k];
	}
}

//Quick insertion_sort **************
void module3::quick_insertion_sort(int array[100],int size)
{
	module1 obj;
	int k;
	quick(array,1,size);
	/*cout << "before" << endl;
	for(int i=1;i<=size;i++)
	 	cout << array[i] << " ";
		cout <<endl;*/
	obj.insertion_sort_iterative(array,1,size);
}

void module3::quick(int a[100],int p,int r)
{
	int q;
	
        if(p<r)
	  {
	    if((r-p+1) <= 20) //if array size is atmost 20 return
	      {
		return;
	      }
	    else //if array size > 20 performing quick_sort
	      {
	        q=partition(a,p,r);
		/*cout << "Q:" << q << endl;
		for(int i=1;i<=r;i++)
	 	cout << a[i] << " ";
		cout <<endl;*/
	        quick(a,p,q-1);
	        quick(a,q+1,r);
	      }
	  }
}

int module3::partition(int a[100],int p,int r) //partition for quick_sort
{
	int x,i,j,l;
        x=a[r];
        i=p-1;
        for(j=p;j<r;j++)
	  {
	      if(a[j]<=x)
		{
		    i++;
		    swap(&a[i],&a[j]);
		}
	  }
	swap(&a[i+1],&a[r]);
	//cout << endl;
	/*for(l=p;l<=r;l++)
	   {
		cout << a[l] << " ";
	   }
	cout << endl;*/
        return i+1;
}

void module3::swap(int *a,int *b)
{
       int t=*a;
       *a=*b;
       *b=t;
}

//Merge insertion_sort ***********
void module3::merge_insertion_sort(int array[1000],int size)
{
	mergesort(array,1,size);    
}

void module3::mergesort(int array[100],int p,int r)
{ 
	int q;
	module1 obj;
        if(p<r)
	  {
	      q=(p+r)/2;
              if(q-p+1<=20) //if array size is atmost 20 performing insertion_sort
	        {
	           obj.insertion_sort_iterative(array,p,q);
	        }
	      else //if array size > 20 performing merge_sort
	        {
	 	   mergesort(array,p,q);
	        }
	      if(r-q<=20) //if array size is atmost 20 performing insertion_sort
	        {
		   obj.insertion_sort_iterative(array,q+1,r);
	        }
              else //if array size > 20 performing merge_sort
	        {
	           mergesort(array,q+1,r);
	        }
              merge(array,p,q,r); //calling merge function
          }
}

void module3::merge(int array[100],int p,int q,int r) //merging 2 sorted arrays
{
      int n1=q-p+1;
      int n2=r-q;
      int l1[n1],l2[n2],i,j,k;
      for(i=0;i<n1;i++)
	{
	    l1[i]=array[p+i];
	}
      for(j=0;j<n2;j++)
	{
	    l2[j]=array[q+j+1];
	}
      i=0;
      j=0;
      k=p;
      while(i<n1 && j<n2)
	{
	    if(l1[i]<=l2[j])
	      {
		array[k]=l1[i];
	        i++;
	      }
	    else
	      {
		array[k]=l2[j];
		j++;
 	      }
	    k++;
	}
      while(i<n1)
        {
	   array[k]=l1[i];
	   i++;
	   k++;
        }
      while(j<n2)
        {
	   array[k]=l2[j];
	   j++;
	   k++;
        }
}

//Variant_linear_search **********
void module3::varsearch(int array[1000],int size,int k)
{
	search(array,size,k);
}

int module3::search(int a[1000],int size,int k) //Searching key from both ends of the array alternatively
{
	int i,j,count=0;
	i=1;
	j=size;
	for(i=1;i<=(size/2)+1;i++)
	  {
	        if(a[i]==k&&count==0)
		  {
		       cout<<"element present at index "<<i<<endl;
		       count++;
		  }
		else
	          i++;
		if(j>(size/2+1)&&count==0)
		  {
		       if(a[j]==k)
			 {
			    cout<<"element present at index "<<j<<endl;
			    count++;
			 }
		       else
			 j--;
		  }
	  }
	if(count==0)
           cout<<"element is not present in the given array"<<endl;
	return 0;
}

//Display the output **********
void module3::display(int array[1000],int size)
{
	cout<<"display:"<<endl;
        for(int k=1;k<=size;k++)
	  {
	   cout << array[k] << " ";
          }
	cout<<endl;
}


/*int main()
{
	
	//operation1 obj;
	//int option;
	int k;
	int c;
	
	
	do
	 {
	    cout << "1.insertion_sort_iterative\n2.insertion_sort_recursive\n3.binary_insertion_sort\n4.counting inversions\n5:quick insertion\n 6:merge insertion \n7:variant linear search\n";
	    cout << "\nEnter your choice:";
	    cin >> c;
	     //cout<<"choice"<<c<<endl;
	    switch(c)
		{
		  case 1: 
			module1 m1;
			m1.initialization();
		         m1.insertion_sort_iterative(m1.array,1,m1.size);
			  m1.display(m1.array,m1.size);
			 break;
		  case 2:
			module1 m2;
			m2.initialization();
			
			 m2.insertion_sort_recursive(m2.array,m2.size,2);
			  m2.display(m2.array,m2.size);
		   	 break;
		  case 3:
			module1 m3;
			m3.initialization();
			 m3.binary_insertion_sort(m3.array,m3.size);
			 m3.display(m3.array,m3.size);
			 break;
		  case 4:
			module1 m4;
			m4.initialization();
			 m4.counting_inversions(m4.array,1,m4.size);
			 break;
		case 5:
		module3 o;
		 o.initialization();
		 o.quick_insertion_sort(o.array,o.size);
		 o.display(o.array,o.size);
		  break;
		case 6:
		module3 o1;
		 o1.initialization();
		 o1.merge_insertion_sort(o1.array,o1.size);
		 o1.display(o1.array,o1.size);
			break;
		case 7:
			module3 o2;
		 o2.initialization();
		 cout<<"\nenter the value to be searched"<<endl;
	         cin>>k;
		  o2.varsearch(o2.array,o2.size,k);
		break;
		
		  case 0:break;
		}
	 }while(c!=0);
        return 0;	
	
}*/
