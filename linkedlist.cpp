#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
	
};

int main()
{
	int action, n;
	Node *head = NULL;
	Node *temp;
	
	
	do{
		cout<<"\n";
		cout<<"\n1. Add node";
		cout<<"\n2. Display the list";
		cout<<"\n3. Exit \n";
		
		cin>>action;
		switch(action){
		
			case 1:
			{
				
			
				Node *NN = new Node();
				cin>>n;
				NN->data = n;
				NN->next = NULL;
				
				if(head==NULL)
				{
					head = NN;
				}
				else{
					Node *temp = head;
					while(temp->next!=NULL)
					{
						temp = temp->next;
					}
					temp->next = NN;
				}
				break;
			}
			
			case 2:
			{
				
				
				if(head==NULL)
				{
					cout<<"\nempty list \n";
				}
				else{
					temp = head;
					cout<<"the list: \n";
					while(temp!=NULL)
					{
						cout<<"\n "<<temp->data;
						temp = temp->next;
					}
					
				}
			break;
			}
			default:
				{
					cout<<"\ninvalid choice";
				}
				
		}
	}while(action!=3);
	
	
	
}
