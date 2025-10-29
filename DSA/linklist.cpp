#include<iostream>
using namespace std;

class Node{
    
public : 
    int data;
    Node* next;
    
    Node(int val){
        data = val;
        next =NULL;
        
    }
};
 
class List{
    Node* head;
    Node* tail;
    
    public:
    List(){
        head = tail = NULL;
    }
    void push_front(int val){
        Node* newNode= new Node(val);// dynamic
        if ( head==NULL){ // This is when we insert 1st value , head and tail is null 
            head = tail = newNode;
            return ;
        }else{
            newNode->next = head; // [*newNode.next= head ]---> when we insert second value .connect new node to current head
             head=newNode;   // move head to new node
        }
    }
    
    void printLL(){
        Node* temp =head; // for print list we let a node temp which equal head . It indicate haed and after print head it will point next node . temp= temp->next . last node (tail) is null . When temp found the null pointer it means this is the end of List.  
        
        while(temp!=NULL){
            cout<<temp->data<<"-> ";
            temp =temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    
    ll.printLL();
    return 0;
}