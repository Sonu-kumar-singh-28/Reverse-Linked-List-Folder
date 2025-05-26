#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->data =0;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertatfirst(Node* &start, Node* &end, int data){
    Node* newnode = new Node(data);

    if(start == NULL){
        start = newnode;
        end = newnode;
    }else{
        newnode->next = start;
        start = newnode;
    }
}

void insertatLast(Node* &start, Node* &end, int data){
    Node* newnode = new Node(data);
    if(end == NULL){
        start = newnode;
        end = newnode;
    }else{
        end->next = newnode;
        end = newnode;
    }
}

int findlen(Node* &start){
    int len =0;
    Node* temp = start;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertatMiddle(int position,Node* &start ,Node* &end , int data){
    Node* newnode = new Node(data);
    if(start == NULL){
        start = newnode;
        end = newnode;
        return;
    }


    if(position ==1){
        insertatfirst(start,end,data);
        return;
    }

    int len = findlen(start);
    if(position >= len){
        insertatLast(start,end, data);
        return;
    }

    int i=1;
    Node* prevnode = start;
    while(i<position-1){
        prevnode = prevnode->next;
        i++;
    }

    Node* curr = prevnode->next;
    prevnode->next = newnode;
    newnode->next = curr;

}

Node* reverselinkedlist(Node* &start){
    Node* prev = NULL;
    Node* curr = start;
  
    while(curr!= NULL){
        Node* Forward =curr->next;
        curr->next = prev;
        prev = curr;
        curr = Forward;
    }
    return prev;
}

void print(Node* &start){
    Node* temp = start;
    while(temp!= NULL){
        cout<< temp->data << " ";
        temp = temp->next;
    }
}


int main(){
    Node* start =NULL;
    Node* end = NULL;

    insertatfirst(start,end,100);
    insertatfirst(start,end,200);
    insertatfirst(start,end,300);
    insertatfirst(start,end,400);
    insertatfirst(start,end,500);
    insertatMiddle(3,start,end,600);
    print(start);
    
    cout<< endl;

    start = reverselinkedlist(start);
    cout<< " After Reverse Linked list - " ;
    print(start);

}