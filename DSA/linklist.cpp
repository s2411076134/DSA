#include<iostream>
using namespace std;

class Node {

public :
	int data;
	Node* next;

	Node(int val) {
		data = val;
		next =NULL;

	}
};

class List {
	Node* head;
	Node* tail;

public:
	List() {
		head = tail = NULL;
	}
	void push_front(int val) { //
		Node* newNode= new Node(val);// dynamic
		if ( head==NULL) { // This is when we insert 1st value , head and tail is null
			head = tail = newNode;
			return ;
		} else {
			newNode->next = head; // [*newNode.next= head ]---> when we insert second value .connect new node to current head
			head=newNode;   // move head to new node
		}
	}

	void push_back(int val) {
		Node* newNode =new Node(val);
		if(head==NULL) {
			head=tail=newNode;
			return;
		} else {
			tail->next=newNode;
			tail=newNode;
		}
	}

	void pop_front() {
		if(head==NULL) {
			cout<<"List is empty";
			return;
		}
		Node* temp = head;
		head = head->next;
		temp->next = NULL;

		delete temp;

	}

	void pop_back() {
		if(head == NULL) {
			cout<<"List is empty\n";
			return;
		}
		
		if (head == tail) { //If there is only one value ; 
        delete head;
        head = tail = NULL;
        return;
        }
        
		Node* temp = head;
		while(temp->next != tail) { // Traverse to the second-last node
			temp = temp->next;
		}
		temp->next = NULL;
		delete tail;
		tail = temp;

	}

    void insert( int val , int pos){
        if(pos<0){
            cout<<"Invalid position\n";
            return ;
        }
        
        if(pos == 0){
            push_front(val);
            return ;
        }
        
        Node* temp = head;
        for(int i=0; i<pos-1;i++){
            if(temp==NULL){ // for good cheacking 
                cout<<"Invalid position\n";
                return ;
            }
            
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    int search(int key){
        Node* temp = head;
        int indx =0;
        
        while(temp != NULL){
            if(temp->data == key){
                return indx;
            }
            temp=temp->next;
            indx++;
            
        }
        return -1;
    }

	void printLL() {
		Node* temp =head; 
        // for print list we let a node temp which equal head . 
        // It indicate haed and after print head it will point next node . temp= temp->next . last node (tail) is null . 
        // When temp found the null pointer it means this is the end of List.

		while(temp!=NULL) {
			cout<<temp->data<<"-> ";
			temp =temp->next;
		}
		cout<<"NULL"<<endl;
	}
};

int main() {
	List ll;
	ll.push_front(3);
	ll.push_front(2);
	ll.push_front(1);

	ll.push_back(4);

	ll.pop_front();
	
	ll.insert(4,1); // in linklist it start from 0 position. 
	
	ll.printLL();

	ll.pop_back();


	ll.printLL();
	
	cout<<ll.search(4);
	
	
	return 0;
}
