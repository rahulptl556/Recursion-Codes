#include <iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* prev; // Prev Node
    Node* next; //Next Node

//Constructor
Node(int data){
    this -> data = data;
    this -> next = NULL;
    this -> prev = NULL;
}
};

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data <<" ";
        temp = temp -> next;
    }
    cout << endl;
}

int getLength(Node* head){
    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}

void insertAtHead(Node* &tail, Node* &head, int d) {

    //empty list
    if(head == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }

}


void insertAtTail(Node* &tail,Node* &head, int d) {
    if(tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        tail -> next  = temp;
        temp -> prev = tail;
        tail = temp;
    }

}

void insertAtPosition(Node* & tail, Node* &head, int position, int d) {
    
    //insert at Start
    if(position == 1) {
        insertAtHead(tail,head, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(tail,head,d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert ->next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}


int main(){

    Node* head = NULL;
    Node* tail = NULL;

    print(head);
    //cout << getLength(head) << endl;

    insertAtHead(tail,head, 11);
    print(head);
    
    insertAtHead(tail,head, 13);
    print(head);
    
    insertAtHead(tail,head, 8);
    print(head);
   
    insertAtTail(tail,head, 25);
    print(head);
    
    insertAtPosition(tail, head, 2, 100);
    print(head);
   

    insertAtPosition(tail, head, 1, 101);
    print(head);

   
    return 0;
}