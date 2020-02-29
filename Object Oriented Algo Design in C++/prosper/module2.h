
// module2.h


#include<iostream>
#include<stdlib.h>

using namespace std;

     class module2
   {
	public:
		
                void initialization();
		int parti(int[],int,int);
		void display(int array[1000],int size);
		void quick(int[],int,int);
		void quick_sort(int[],int);
		void quick_pivot_first(int[],int);
		void quick_pivot_middle(int[],int);
		void quick_pivot_random(int[],int);
		int array[200],size;
  };
