#include<iostream>
using namespace std;

class numbers
{
	public:
		int n,i,j,temp;
		int A[10];
		numbers(int num) //constructor
		{
			n = num;
			cout<<"Enter "<<n<<" elements \n";
			for(i=0;i<n;i++)
			{
				cin>>A[i];
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
	int n, a;
	cout<<"Enter the number of elements you want to sort \n";
	cin>>n;
	numbers a1(n);
	do{
		cout<<"\nWhich sorting algorithm you want to sort the elements? ";
		cout<<"\n1. Bubble sort";
		cout<<"\n2. Inserstion sort";
		cout<<"\n3. Exit \n";
		cin>>a;
		
		switch(a){
			case 1:
				a1.bubbleSort(n);
				break;
			case 2:
				a1.inserstionSort(n);
				break;
			case 3:
				cout<<"\n Exiting...";
			default:
				cout<<"\n Invalid Input \n";	
		}
		
	}while(a!=3);
}
