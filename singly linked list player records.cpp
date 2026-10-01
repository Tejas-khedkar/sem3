#include<iostream>
using namespace std;

class Node
{
	public:
		int id;
		string name;
		int mob;
		int age;
		Node *next;
	
};

int main()
{
	int action, action2, n, i, input, found;
	string pn;
	Node *head = NULL;
	Node *temp;
	
	
	do{
		cout<<"\n";
		cout<<"\n1. Add player (at the end)"; //done
		cout<<"\n2. Display the list"; //done
		cout<<"\n3. Add node (Anywhere)"; //done
		cout<<"\n4. Delete node "; //already working
		cout<<"\n5. Update mobile number"; //done
		cout<<"\n6. Search player"; //done
		cout<<"\n7. Exit \n"; //already working
		
		cin>>action;
		switch(action){
		
			case 1:
			{
				
			//accept everything
				Node *NN = new Node();
				cout<<"Enter player ID: ";
				cin>>n;
				NN->id = n;
				cout<<"\nEnter player name: ";
				cin>>pn;
				NN->name=pn;
				cout<<"\nEnter mobile number: ";
				cin>>n;
				NN->mob=n;
				cout<<"\nEnter player's age: ";
				cin>>n;
				NN->age=n;
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
						cout<<"\n ";
						cout<<"\nPlayer ID: "<<temp->id;
						cout<<"\nPlayer name: "<<temp->name;
						cout<<"\nPlayer's Mobile number: "<<temp->mob;
						cout<<"\nPlayer age: "<<temp->age;
						cout<<"\n ";
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
								cout<<"Enter player ID: ";
								cin>>n;
								Node *NN = new Node();
								NN->id = n;
								cout<<"\nEnter player name: ";
								cin>>pn;
								NN->name=pn;	
								cout<<"\nEnter mobile number: ";
								cin>>n;	
								NN->mob=n;
								cout<<"\nEnter player's age: ";
								cin>>n;
								NN->age=n;	
								NN->next = head;
								head = NN;
								break;
							}
						case 2:
							{
								// search and add node after that place
								cout<<"Enter player ID to add: ";
								cin>>n;
								Node *NN = new Node();
								NN->id = n;
								cout<<"\nEnter player name: ";
								cin>>pn;
								NN->name=pn;
								cout<<"\nEnter mobile number: ";
								cin>>n;
								NN->mob=n;
								cout<<"\nEnter player's age: ";
								cin>>n;
								NN->age=n;
								cout<<"after which element do you want to add a new node?\n";
								cin>>input;
								found = 0;
								
								temp = head;
								while(temp->next!=NULL)
								{
									temp = temp->next;
									if(temp->id==input){
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
								cout<<"Enter player ID: ";
								cin>>n;
								NN->id = n;
								cout<<"\nEnter player name: ";
								cin>>pn;
								NN->name=pn;
								cout<<"\nEnter mobile number: ";
								cin>>n;
								NN->mob=n;
								cout<<"\nEnter player's age: ";
								cin>>n;
								NN->age=n;
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
					if(head==NULL)
					{
					cout<<"\nempty list \n";
					}
					else
					{
						temp = head;
						found = 0;
						while(temp->next != NULL)
						{
						
							if(temp->next->id == input)
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
					}
					
					
					break;
				}	
			
			case 5:
				{
					//update mobile number
					if (head == NULL) 
					{
						cout << "\nList is empty!\n";
					} 
					else 
					{
						int newMob;
						cout << "Enter player ID to update mobile number: ";
						cin >> n;

						temp = head;
						found = 0;

						while (temp != NULL) 
						{
							if (temp->id == n) 
							{
								found = 1;
								cout << "Enter new mobile number: ";
								cin >> newMob;
								temp->mob = newMob;
								cout << "\nMobile number updated successfully!\n";
								break;
							}
							temp = temp->next;
						}

						if (found == 0) 
						{
							cout << "\nPlayer with ID " << n << " not found in the list.\n";
						}
					}
					break;
				}	
			case 6:
				{
					//search player
					if (head == NULL) 
					{
						cout << "\nList is empty!\n";
					} 
					else
					{
						cout<<"Enter player name to search: ";
						cin>>pn;
					
						temp = head;
						found = 0;
						while(temp->next != NULL)
						{
						
							if(temp->next->name == pn)
							{
								found = 1;
								temp = temp->next;
								break;
							}
							else
							{
								temp = temp->next;
							}
						}
					
						if(found == 1)
						{
							cout<<"\nPlayer found: ";
							cout<<"\n ";
							cout<<"\nPlayer ID: "<<temp->id;
							cout<<"\nPlayer name: "<<temp->name;
							cout<<"\nPlayer's Mobile number: "<<temp->mob;
							cout<<"\nPlayer age: "<<temp->age;
							cout<<"\n ";
						
						}
						else{
							cout<<"\n"<<input<<" not found in this linked list";
						}
					}
					
					break;
					
				}
			default:
				{
					cout<<"\ninvalid choice";
					break;
				}
				
		}
	}while(action!=7);
	
}
