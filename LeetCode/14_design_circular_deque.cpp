#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node * next;
    Node * prev;
    Node();
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
class MyCircularDeque {
    int size;
    int curr_size;
    Node * front;
    Node* rear;
    
public:
    MyCircularDeque(int k) {
        (*this).size = k;
        (*this).curr_size = 0;
        (*this).front = NULL;
        (*this).rear = NULL;
    }
    
    bool insertFront(int value) {
        if(curr_size<size){
            Node * n = new Node(value);
            if(front==NULL){
                front = n;
                rear = n;
                rear->next = rear;
                rear->prev= front;
                front->next=rear;
                front->prev= front;
            }
            else{
                n->next = front;
                n->prev=rear;
                front->prev = n;
                rear->next = n;
                front = n;
            }
            curr_size++;
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(curr_size<size){
            Node * n = new Node(value);
            if(front==NULL){
                front = n;
                rear = n;
                rear->next = rear;
                rear->prev=rear;
                front->next=front;
                front->prev=front;
            }
            else{
                rear->next = n;
                n->prev= rear;
                rear = n;
                rear->next = front;
            }
            curr_size++;
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(front == NULL)return false;
        if(front == rear){
            front = NULL;
            rear = NULL;
        }
        else{
            front =  front->next;
            rear->next = front;
            front->prev = rear;
        }
        curr_size--;
        return true;
    }
    
    bool deleteLast() {
        if(front == NULL)return false;
        if(front == rear){
            front = NULL;
            rear = NULL;
        }
        else{
            rear =  rear->prev;
            rear->next = front;
            front->prev = rear;
        }
        curr_size--;
        return true;
    }
    
    int getFront() {
        if(front==NULL)return -1;
        return front->val;
    }
    
    int getRear() {
        if(front==NULL)return -1;
        return rear->val;
    }
    
    bool isEmpty() {
        if(curr_size == 0)return true;
        return false;
    }
    
    bool isFull() {
        if(curr_size == size)return true;
        return false;
    }
};

int main(){
    return 0;
}