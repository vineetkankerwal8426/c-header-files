#include<iostream>
using namespace std;

template<class t>
class node{
public:
    t value;
    node*next;
    node(){
        value =0;
        next = NULL;
    }
    node(t value){
        this->value = value;
        next = NULL;
    }
};

template<typename t>
class LinkedList{
    node<t> * tail;
    node<t> *head;
public:
    int size=0;
     LinkedList(){
        head =tail= NULL;
    }
    
    void push_back(t data){
        if(head==NULL){
            node<t> * newNode =new node(data);
            head = newNode;
            tail = newNode;
        }
        else{
            node<t> * newNode = new node(data);
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void push_front(t data){
        if (head ==NULL){
            node<t>* newNode = new node(data);
            head = newNode;
            tail = newNode;
        }
        else{
            node<t>* newNode = new node(data);
            newNode->next = head;
            head = newNode;
            }
            size++;
    }

    void insert_(t data,int index){
        if (index >size|| index<0){
            cout<<"out of bound"<<endl;
        }
        else if (index ==0){
            push_front(data);
        }
        else if (index == size){
            push_back(data);
        }
        else{
            node<t> *newNode = new node(data);
            node<t> * temp = head;
            for (int i =1;i<index;i++){
                temp= temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            size++;

        }
        
    }

    void delete_(int index){
        if (index >= size|| index < 0){
            cout<<"index out of bound"<<endl;
        }
        else if (index ==0){
            delete_front();
        }
        else if (index == size-1){
            delete_back();
        }
        else{
            node<t>* temp = head;
            node<t> * temp2;
            for (int i= 0;i<index-1;i++){
                temp = temp->next;
            }
            temp2 = temp->next;
            temp->next= temp->next->next;
            delete temp2;
            
        }
    }


    void delete_back(){
        if(head==tail){
            delete head;
            size--;
        }
        else if (head ==nullptr){
            cout<<"nothing to delete"<<endl;
        }
        else{
            node<t> * temp=head;
            while(temp->next->next != NULL){
                temp=temp->next;
            }
            delete tail;
            tail = temp;
            tail->next= NULL;
            size--;

        }
    }

    void delete_front(){
        if(head==tail){
            delete head;
            size--;
        }
        else if (head ==nullptr){
            cout<<"nothing to delete"<<endl;
        }
        else{
            node<t> * temp = head;
            head = temp->next;
            delete temp;
            size--;
        }
    
    }

    void get(int index){
        if (index>size-1|| index<0){
            cout<<"element at index "<<index<<" does not exists"<<endl;
        }
        else{
            node<t> *temp= head;
            for(int i =0;i<index;i++){
                temp = temp->next;
            }
            cout<<temp->value<<endl;
        }
    }

    void print(){
        if (size==0){
            cout<<"empty list"<<endl;
        }
        else{
            node<t> * i;
            for(i=head;i->next!=NULL;i=i->next){
                cout<<i->value<<" ";
            }
            cout<<i->value<<endl;
        }
    }
};



