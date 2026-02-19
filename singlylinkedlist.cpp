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

class linkedlist{ 
    Node* head;
    public:
    linkedlist(){
        head=nullptr;
    }
    void insert (int value){
        Node* newnode = new Node(value);
        if(head==nullptr){
            head=newnode;
            return;
        }
        newnode->next= this->head;
        this->head=newnode;

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
        linkedlist listahan;
        listahan.insert(20);
        listahan.insert(30);
        listahan.insert(40);
        listahan.insert(50);
        listahan.insert(60);
        listahan.insert(70);
        listahan.insert(80);
        listahan.insert(90);    
        listahan.insert(100);   
        listahan.display();


}