#include<iostream>
using namespace std;

//class node for creating any individual node 
template<class t>
class node {
public:
    t value;
    node * next;
    node * prev;

    node(t value){
        this->value = value;
        next = NULL;
        prev = NULL;
    }
    node(){
        value = NULL;
        next =NULL;
        prev = NULL;
    }
};

//class linkedList for creating links between all individual nodes
template<class t>
class linkedList{
    node<t> * head;
    node<t>* tail;
    int size =0;
public:
    linkedList(){
        head = tail = NULL;
    }

    void push_back(t data){
        if (head==NULL){
            node<t> * newNode = new node(data);
            head = newNode;
            tail = newNode;
        }
        else {
            node<t> * newNode = new node(data);
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void delete_back(){
        if (tail == NULL){
            cout<<"empty list, nothing to delete";
        }
        else if (head == tail){
            delete head;
            size--;
        }
        else {
            node<t> *temp = tail;
            temp->prev->next = NULL;
            tail = temp->prev;
            delete temp;
            size--;
        }
    
    }

    void push_front(t data){
        if (head == NULL){
            node<t> *newNode = new node(data);
            head = newNode;
            tail = newNode;
        }
        else{
            node<t> *newNode = new node(data);
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }


    void delete_front(){
        if (head == NULL){
            cout<<"empty list, nothing to delete"<<endl;
        }
        else if (head == tail){
            delete head;
            size--;
        }
        else{
            node<t> *temp = head;
            temp->next->prev = NULL;
            head = temp->next;
            delete temp;
            size--;
        }
    }


    void insert(t data, int index){
        if (index>size||index<0){
            cout<<"index out of bound"<<endl;
        }
        else if(index ==0){
            push_front(data);
        }
        else if (index == size){
            push_back(data);
        }
        else{
            node<t> *newNode = new node(data);
            node<t> * temp = head;
            for (int i =1;i< index ;i++){
                temp=temp->next;
            }
            newNode->next =temp->next;
            temp->next->prev = newNode;
            newNode->prev = temp;
            temp->next = newNode;
            size++;
        }
    }

    void delete_(int index){
        if (index>=size|| index<0){
            cout<<"index out of bound"<<endl;
        }
        else if (index == 0){
            delete_front();
        }
        else if (index == size-1){
            delete_back();
        }
        else{
            node<t> * temp = head;
            for (int i =0;i<index;i++){
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            size--;
        }
        
    }

    void get(int index){
        if (size ==0){
            cout<<"empty list"<<endl;
        }
        else if(index >= size|| index<0){
            cout<<"index out of bound"<<endl;
        }
        else if (index ==0){
            cout<<head->value<<endl;
        }
        else if (index == size-1){
            cout<<tail->value;
        }
        else{
            node<t> * temp = head;
            for (int i =0;i<index;i++){
                temp =temp->next;
            }
            cout<<temp->value<<endl;
        }
    }

    void get_size(){
        cout<<size<<endl;
    }

    void print(){
        if (size==0){
            cout<<"empty list"<<endl;
        }
        else{
            node<t> * i ;
            for (i = head;i->next != NULL;i=i->next){
                cout<<i->value<<" ";
            }
            cout<<i->value<<endl;
            }
    }

    void print_rev(){
        if (size==0){
            cout<<"empty list"<<endl;
        }
        else{        
            node<t> * i;
            for(i = tail;i->prev!= NULL; i=i->prev){
                cout<<i->value<<" ";
            }
            cout<<i->value<<endl;
            }
    }


};

