#include<iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>
using namespace std;

class numbers
{
	public:
		int n,i,j,temp;
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
			for(i=0;i<n-1;i++)
			{
				for(j=0;j<n-i-1;j++)
				{
					if(A[j]>A[j+1])
					{
						temp=A[j];
						A[j]=A[j+1];
						A[j+1]=temp;
					}
				}
				cout<<"\nPass "<<(i+1)<<" completed";
			}
			cout<<"\nSorted: ";
			display();
		}
		
		void inserstionSort(int n)
		{
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
				cout<<"\nPass "<<(i+1)<<" completed";
			}
			cout<<"\nSorted: ";
			display();
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
		cout<<"\n3. Exit \n";
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
				cout<<"\n Exiting...";
				break;
			default:
				cout<<"\n Invalid Input \n";	
		}
		
	}while(a!=3);
}
