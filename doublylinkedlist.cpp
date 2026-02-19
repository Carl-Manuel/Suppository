#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

Node(int value){
   this->data=value;
   this->next=nullptr;
}
};

class doublylist{ 
    Node* head;
    public:
    doublylist(){
        head=nullptr;
    }

    void frontInsert (int value){
        Node* newnode = new Node(value);
        if(head==nullptr){
            head=newnode;
            return;
        }
        newnode->next= this->head;
        this->head=newnode;

    }       

    void backInsert (int value){
        Node* newnode = new Node(value);
        if(head==nullptr){
            head=newnode;
            return;
        }
        Node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    void display(){
     Node* temp=head;
     while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    cout<<endl;
    }
};

int main(){
    doublylist listahan;
    listahan.frontInsert(20);
    listahan.frontInsert(40);
    listahan.frontInsert(60);
    listahan.backInsert(80);
    listahan.backInsert(100);   
    listahan.display();
    return 0;
}