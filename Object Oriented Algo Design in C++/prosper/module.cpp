#include "module1.h"
#include "module2.h"
#include "module3.h"
#include "module4.h"
#include "module5.h"

int main()
{
	
	//operation1 obj;
	//int option;
	int k;
	int c;
	
	
	do
	 {
	    cout << "1.insertion_sort_iterative\n2.insertion_sort_recursive\n3.binary_insertion_sort\n4.counting inversions\n5:quick sort\n6:quick pivot middle \n7:quick pivot first\n8: quick pivot random\n9:quick insertion\n10:merge insertion\n11:variant linear search		\n12:Towers of hanoi\n13:L shaped triomino\n14:Ladder-climbing\n15:Circus\n16:Plot-Insertion-sort\n17:Plot-Quick-Sort\n18:Plot-Hybrid-sort\n19:Plot-Variant-Linear search ";
	    cout << "\nEnter your choice:";
	    cin >> c;
	     //cout<<"choice"<<c<<endl;
	    switch(c)
		{
		  case 1: 
			module1 m1;
			m1.initialization();
		         m1.insertion_sort_iterative(m1.array,1,m1.size);
			 cout<<"\nthe sorted array using insertion sort iterative:"<<endl;
			  m1.display(m1.array,m1.size);
			 break;
		  case 2:
			module1 m2;
			m2.initialization();
			 m2.insertion_sort_recursive(m2.array,m2.size,2);
		  	 cout<<"\nthe sorted array using insertion sort recursive:"<<endl;
			  m2.display(m2.array,m2.size);
		   	 break;
		  case 3:
			module1 m3;
			m3.initialization();
			 m3.binary_insertion_sort(m3.array,m3.size);
			 cout<<"\nthe sorted array using binary insertion sort :"<<endl;
			 m3.display(m3.array,m3.size);
			 break;
		  case 4:
			module1 m4;
			m4.initialization();
			 m4.counting_inversions(m4.array,1,m4.size);
			 break;
		 case 5:
			module2 m2_1;
			m2_1 .initialization();
			m2_1.quick_sort(m2_1.array,m2_1.size);
			cout<<"\nthe sorted array using quick sort taking last element as pivot:"<<endl;
			m2_1.display(m2_1.array,m2_1.size);
			break;
		case 6:
			module2 m2_2;
			m2_2 .initialization();
			m2_2.quick_pivot_middle(m2_2.array,m2_2.size);
			cout<<"\nthe sorted array using quick sort taking middle element as pivot:"<<endl;
			m2_2.display(m2_2.array,m2_2.size);
			break;
		case 7:
			module2 m2_3;
			m2_3 .initialization();
			m2_3.quick_pivot_first(m2_3.array,m2_3.size);
			cout<<"\nthe sorted array using quick sort taking first element as pivot:"<<endl;
			m2_3.display(m2_3.array,m2_3.size);
			break;	
		case 8:
			module2 m2_4;
			m2_4 .initialization();
			m2_4.quick_pivot_random(m2_4.array,m2_4.size);
			cout<<"\nthe sorted array using quick sort taking random element as pivot:"<<endl;
			m2_4.display(m2_4.array,m2_4.size);
			break;


		case 9:
			module3 m3_1;
		  	m3_1.initialization();
		  	m3_1.quick_insertion_sort( m3_1.array, m3_1.size);
		        cout<<"\nthe sorted array using quick insertion sort :"<<endl;
		  	m3_1.display( m3_1.array, m3_1.size);
		  	break;
		case 10:
			module3 m3_2;
			m3_2.initialization();
		 	m3_2.merge_insertion_sort(m3_2.array,m3_2.size);
		 	cout<<"\nthe sorted array using merge insertion sort :"<<endl;
			m3_2.display(m3_2.array,m3_2.size);
			break;
		case 11:
			module3 m3_3;
		 	m3_3.initialization();
		 	cout<<"\nenter the value to be searched"<<endl;
	         	cin>>k;
			m3_3.varsearch(m3_3.array,m3_3.size,k);
			break;
		case 12:
			module4 m4_1;
			m4_1.tower();
			break;
		case 13:
			module4 m4_2;
			m4_2.matrix();
			break;
		case 14:
			module4 m4_3;
			m4_3.steps();
			break;
		case 15:
			module4 m4_4;
			m4_4.circus();
			break;
		case 16:
			plot r;
			r.plot_m1();
			r.plot_module1();
			break;
		case 17:
			r.plot_m2();
			r.plot_quicksort();
			break;
		case 18:
			r.plot_m3();
			r.plot_module3();
			break;
		case 19:
			r.plot_m4();	
			r.plot_search();
			break;

		case 0:break;
		}
	 }while(c!=0);
        return 0;	
	
}
