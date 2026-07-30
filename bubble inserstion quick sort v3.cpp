#include<iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>
#include <vector> // for pointers for quick sort
using namespace std;

class numbers
{
	public:
		int n,i,j,temp,low,high,pivot,arr,swaps;
		int A[50000];
		numbers(int num) //constructor
		{
			n = num;
			
			//cout<<"Enter "<<n<<" elements \n";
			for(i=0;i<n;i++)
			{
				A[i]=(rand() % 1000) + 1; //number = (rand() % (max-min+1)) + min
			}
		}
		
		void bubbleSort(int n)
		{
			swaps=0;
			for(i=0;i<n-1;i++)
			{
				for(j=0;j<n-i-1;j++)
				{
					if(A[j]>A[j+1])
					{
						temp=A[j];
						A[j]=A[j+1];
						A[j+1]=temp;
						swaps++;
					}
				}
				//cout<<"\nPass "<<(i+1)<<" completed";
			}
			cout<<"\nSorted: ";
			display();
			cout<<"\n "<<swaps<<" swaps required\n";
		}
		
		void inserstionSort(int n)
		{
			swaps=0;
			for(i=1;i<=(n-1);i++)
			{
				temp=A[i];
				j=i-1;
				while((j>=0)&&(A[j]>temp))
				{
					A[j+1]=A[j];
					j = j-1;
				}
				A[j+1]=temp;
				swaps++;
				//cout<<"\nPass "<<(i+1)<<" completed";
			}
			cout<<"\nSorted: ";
			display();
			cout<<"\n "<<swaps<<" swaps required\n";
		}
		
		void quickSort(int low, int high)
		{
			if (low < high)
			{
        	// Partition index
        	int pi = partition(low, high);

        	// Recursively sort elements before and after partition
        	quickSort(low, pi - 1);
        	quickSort(pi + 1, high);
    		}      
			     
		}
		
	int partition(int low, int high) //This is for quick sort method
	{
    int pivot = A[low]; // Pivot is chosen as the first element
    int i = high + 1;     // Pointer for elements smaller than/equal to pivot

    // Traverse from right to left to place elements > pivot to the right
    for (int j = high; j > low; --j) {
        if (A[j] >= pivot) {
            i--;
            swap(A[i], A[j]);
        }
    }

    // Place pivot at its correct position
    swap(A[i - 1], A[low]);
    return i - 1; // Return pivot index
	}
		
		
		void display()
		{
			cout<<"\n";
			for(i=0;i<n;i++)
			{
				cout<<A[i];
				cout<<" ";
			}
			cout<<"\n";
		}
};

int main()
{
	srand(time(0)); // this stuff is to generate random numbers
	clock_t start, end; // this and
	double time_taken; // this stuff is to measure CPU ticks
	int n, a;
	cout<<"Enter the number of elements you want to sort \n";
	cin>>n;
	numbers a1(n);
	
	cout<<"\n";
	cout<<"\n";
	cout<<"Unsorted: ";
	cout<<"\n";
	a1.display();
	
	
	do{
		cout<<"\nWhich sorting algorithm you want to sort the elements? ";
		cout<<"\n1. Bubble sort";
		cout<<"\n2. Inserstion sort";
		cout<<"\n3. Quick Sort ";
		cout<<"\n4. Exit \n";
		cin>>a;
		
		switch(a){
			case 1:
				start = clock();
				a1.bubbleSort(n);
				end = clock();
				time_taken = (end - start) / CLOCKS_PER_SEC * 1000;
				cout << "\nTime taken to sort: " << time_taken << " ms" << endl;
				break;
			case 2:
				start = clock();
				a1.inserstionSort(n);
				end = clock();
				time_taken = (end - start) / CLOCKS_PER_SEC * 1000;
				cout << "\nTime taken to sort: " << time_taken << " ms" << endl;
				break;
			case 3:
				start = clock();
				a1.quickSort(0, n-1);
				end = clock();
				cout<<"\nSorted: ";
				a1.display();
				
				time_taken = (end - start) / CLOCKS_PER_SEC * 1000;
				cout << "\nTime taken to sort: " << time_taken << " ms" << endl;
				break;
				
			case 4:
				cout<<"\n Exiting...";
				break;	
			default:
				cout<<"\n Invalid Input \n";	
		}
		
	}while(a!=4);
}
