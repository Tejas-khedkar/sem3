#include<iostream>
using namespace std;


class Book{
	private:
		
		int ISBN;
		string Name;
		string Auth;
		string Publisher;
		float Price;
		int action;
	
	public:
		
		void display(){
			cout<<ISBN<<"\t"<<Name<<"\t"<<Auth<<"\t"<<Price<<"\t"<<Publisher<<endl;
		}
		
		void input(){
			cout<<"\nEnter book name: ";
			cin>>Name;
			cout<<"\nEnter ISBN: ";
			cin>>ISBN;
			cout<<"\nEnter Author name: ";
			cin>>Auth;
			cout<<"\nEnter publisher name: ";
			cin>>Publisher;
			cout<<"\nEnter price: ";
			cin>>Price;	
		}
		
		void search(){
			cout<<"\n1. Search by ISBN \n2. Search by book name \n3. Search by author name \n4. Search by publisher name \n5. Search by price\n";
			cin>>action;
			
			switch(action)
			{
				case 1:
					ISBNsearch();
					break;
			}
		}
		
		void ISBNsearch(){
			//sort by ISBN first
			//then apply binery search
		}
		
};

int main(){
	Book b[50];
	int action, i, n;
	int totalBooks = 0;
	
	do{
		cout<<"\n1. Add book";
		cout<<"\n2. Search book";
		cout<<"\n3. Display all books";
		cout<<"\n4. Exit\n";
		cin>>action;
		
		switch(action)
		{
			case 1:
				b[totalBooks].input();
				totalBooks++;
				break;
			case 2:
				b[i].search();
				break;
			case 3:
				cout<<"\nSr No. \tISBN \tName \tAuthor \tPrice \tPublisher"<<endl;
				for(i=0; i<totalBooks; i++){
					cout<<i+1<<"\t";
					
					b[i].display();
				}
				break;
			default:
				cout<<"\ninvalid input\n";
		}
	}while(action != 4);
	
	
	
	
	
	
	
}
