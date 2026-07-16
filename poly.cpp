#include<iostream>
using namespace std;

struct Poly
{
	int coef;
	int exp;
}P1[10],P2[10],RP[20];



int main()
{
	int n1, n2, c, e, i, j, k, action = 0;
	cout<<"Which operation do you want to perform? \n";
	cout<<" 1. Addition \n 2. Subtraction \n";
	cin>>action;
	
	cout<<"Enter number of terms in 1st polynomial \n";
	cin>>n1;
	// enter terms for p1
	for(i=0; i<n1; i++)
	{
		cout<<"Enter coefficient \n";
		cin>>c;
		P1[i].coef = c;
		cout<<"Enter exponent \n";
		cin>>e;
		P1[i].exp = e;
		
	}
	cout<<"Enter number of terms in 2nd polynomial \n";
	cin>>n2;
	//enter terms for p2
	for(i=0; i<n2; i++)
	{
		cout<<"Enter coefficient \n";
		cin>>c;
		P2[i].coef = c;
		cout<<"Enter exponent \n";
		cin>>e;
		P2[i].exp = e;
	}
	
	i = 0;
	j = 0;
	k = 0;
	
	switch(action)
	{
		case 1:
			//addition
			while(i<n1&&j<n2)
			{
				if(P1[i].exp==P2[j].exp)
				{
					RP[k].coef=P1[i].coef+P2[j].coef;
					RP[k].exp=P1[i].exp;
					i++;
					j++;
					k++;
				}
				else if(P1[i].exp>P2[j].exp)
				{
					RP[k]=P1[i];
					i++;
					k++;
				}
				else if(P2[j].exp>P1[i].exp)
				{
					RP[k]=P2[j];
					j++;
					k++;
				}
			}
			// Copy remaining terms of P1 (if any)
    		while(i < n1)
   			{
        		RP[k] = P1[i];
        		i++;
        		k++;
    		}
    
    		// Copy remaining terms of P2 (if any)
   		 	while(j < n2)
    		{
        		RP[k] = P2[j];
        		j++;
        		k++;
    		}
    		break;
		
		case 2:
			//subtraction
			
			while(i<n1&&j<n2)
			{
				if(P1[i].exp==P2[j].exp)
				{
					RP[k].coef=P1[i].coef-P2[j].coef;
					RP[k].exp=P1[i].exp;
					i++;
					j++;
					k++;
				}
				else if(P1[i].exp>P2[j].exp)
				{
					RP[k]=P1[i];
					i++;
					k++;
				}
				else if(P2[j].exp>P1[i].exp)
				{
					RP[k]=P2[j];
					j++;
					k++;
				}
			}
	
			// Copy remaining terms of P1 (if any)
   		 	while(i < n1)
    		{
       		 RP[k] = P1[i];
       		 i++;
      		  k++;
   		 	}
    
   		 	// Copy remaining terms of P2 (if any)
   		 	while(j < n2)
   		 	{
      			RP[k] = P2[j];
      		  	j++;
      		  	k++;
   		 	}
			break;
			
		}
	
	
	//printing
	cout<<"Answer: \n";
	for(i=0; i<k; i++)
	{
		if(i!=0)
		{
			cout<<"+";
		}
		cout<<"(";
		cout<<RP[i].coef;
		cout<<"x^";
		cout<<RP[i].exp;
		cout<<")";
		
	}
}
