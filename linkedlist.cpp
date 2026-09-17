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
	int action, action2, n, i, input, found;
	Node *head = NULL;
	Node *temp;
	
	
	do{
		cout<<"\n";
		cout<<"\n1. Add node (at the end)";
		cout<<"\n2. Display the list";
		cout<<"\n3. Add node (Anywhere)";
		cout<<"\n4. Delete node ";
		cout<<"\n5. Exit \n";
		
		cin>>action;
		switch(action){
		
			case 1:
			{
				
			
				Node *NN = new Node();
				cout<<"Enter an integer: ";
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
			
			case 3:
				{
					cout<<"\nWhere do you want to add the node?\n";
					cout<<"1. Start, 2. Middle, 3. End\n";
					cin>>action2;
					
					switch(action2)
					{
						case 1:
							{
								// add node at start
								cout<<"Enter an integer: ";
								cin>>n;
								Node *NN = new Node();
								NN->data = n;
								NN->next = head;
								head = NN;
								break;
							}
						case 2:
							{
								// search and add node after that place
								cout<<"Enter an integer to add: ";
								cin>>n;
								Node *NN = new Node();
								NN->data = n;
								
								cout<<"after which element do you want to add a new node?\n";
								cin>>input;
								found = 0;
								
								temp = head;
								while(temp->next!=NULL)
								{
									temp = temp->next;
									if(temp->data==input){
										found = 1;
										break;
									}
								}
								if(found == 1)
								{
										NN->next=temp->next;
										temp->next=NN;
								}
								else
								{
									cout<<"\n"<<input<<" isn't in this linked list";
								}
								
								break;
							}
						case 3:
							{
								Node *NN = new Node();
								cout<<"Enter an integer: ";
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
					}
					
					break;
				}
				
			case 4:
				{
					//deletion code
					cout<<"\nWhich node you want to delete? \n";
					cin>>input;
					temp = head;
					found = 0;
					while(temp->next != NULL)
					{
						
						if(temp->next->data == input)
						{
							found = 1;
							break;
						}
						else
						{
							temp = temp->next;
						}
					}
					
					if(found == 1)
					{
						if(temp->next->next != NULL)
						{
							temp->next = temp->next->next;
							
						}
						else{
							temp->next = NULL;
						}
						
					}
					else{
						cout<<"\n"<<input<<" not found in this linked list";
					}
					
					break;
				}	
			default:
				{
					cout<<"\ninvalid choice";
					break;
				}
				
		}
	}while(action!=5);
	
}
