/*given an array the array is sorted using (a)insertion sort iterative or (b)insertion sort recursive or (c)binary insertion sort and  (d)counting the nunber of inversions */

# include"module1.h"

/*sorting using iterative insertion sort*/
void module1::insertion_sort_iterative(int array[1000],int start,int end)
  {
     int index1,index2,key;
     for(index1=start+1;index1<=end;index1++)
	{
	    key=array[index1];
	    index2=index1-1;
	    while(index2>0 && array[index2]>key)
		{
		    array[index2+1]=array[index2];
		    index2=index2-1;
	 	    count++;
		} 
	    array[index2+1]=key;
	}
	/*for(int index1=start;index1<=end;index1++)
        {
	   cout << "display";
	    cout << array[index1] << " ";
        }*/
  }


/*sorting using recursive insertion sort*/
void module1::insertion_sort_recursive(int array[1000],int size,int n)
  {
     int index1,index;
      if(n<=size)
        {
	   int key=array[n];
	   index=n-1;
	   while(index>0 && array[index]>key)
	      {
		 array[index+1]=array[index];
		 index=index-1;
	      }
	   array[index+1]=key;
	   insertion_sort_recursive(array,size,n+1);
        }
  }

/*sorting using binary insertion sort*/
void module1::binary_insertion_sort(int array[1000],int size)
  {
	//cout<<"entered"<<endl;
	int low=1;
	int high=size;
     int index2,index1,key;
    // cout << "entering"<<endl;
     for(index2=2;index2<=size;index2++)
	{
	   index1=index2-1;
	   key=array[index2];
	   
	   int location=bin_search(array,key,1,index1);//searching for the correct positionto to place key using binary search
	  // cout<<"location="<<location<<endl;
	   while(index1>=location)
	     {
		array[index1+1]=array[index1];
		index1=index1-1;
	     } 
	   array[index1+1]=key;
	}
	//display(array,size);
  }

int module1::bin_search(int array[1000],int key,int low,int high)
  {
     if(low>=high)
     {
	if(key>=array[low])
	 return low+1;
	else
	 return low;
     }
    else
	{
	 int mid=(low+high)/2;
	 if(key==array[mid])
	  return mid;
	 else if(key<array[mid])
	  bin_search(array,key,low,mid-1);
	 else if(key>array[mid])
	  bin_search(array,key,mid+1,high);
	}
  }

/*code to find the number of counting inversions*/
void module1::counting_inversions(int array[1000],int start,int end)
  {
     count=0;
     insertion_sort_iterative(array,start,end);
     cout << "the number of counting inversions are:" << count << endl;
  }

void module1::initialization()
  {
     cout<<"\nEnter size:";
     cin>>size;
     //cout<<"size:"<<size<<endl;
     cout << "\nEnter data:";
     for(int index=1;index<=size;index++)
	{
	 //cout<<"initialisation\n";
	 cin>>array[index];
	 //cout<<"out1\n";
	}
        cout<<endl;
        //cout <<"out\n";	  	
  }

void module1::display(int array[1000],int size)
  {
	
	//cout<<"\ndisplay:"<<endl;
	 for(int index1=1;index1<=size;index1++)
        {
	    cout << array[index1] << " ";
        }
	cout<<endl;
  }

/*int main()
  {
	int c;
	module1 m1;
	
	do
	 {
	    cout << "1.insertion_sort_iterative\n2.insertion_sort_recursive\n3.binary_insertion_sort\n4.counting inversions";
	    cout << "\nEnter your choice:";
	    cin >> c;
	     //cout<<"choice"<<c<<endl;
	    switch(c)
		{
		  case 1: m1.initialization();
		         m1.insertion_sort_iterative(m1.array,1,m1.size);
			  m1.display(m1.array,m1.size);
			 break;
		  case 2:m1.initialization();
			
			 m1.insertion_sort_recursive(m1.array,m1.size,2);
			  m1.display(m1.array,m1.size);
		   	 break;
		  case 3:m1.initialization();
			cout<<"switch";
			 m1.binary_insertion_sort(m1.array,m1.size);
			 m1.display(m1.array,m1.size);
			 break;
		  case 4:m1.initialization();
			 m1.counting_inversions(m1.array,1,m1.size);
			 break;
		  case 0:break;
		}
	 }while(c!=0);
        return 0;
  }*/
  

