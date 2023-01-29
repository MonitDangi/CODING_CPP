#include<bits/stdc++.h>
using namespace std;
class Node{
    public: 
    int key;
    int val;
    Node * prev;
    Node * next; 
    Node(int k, int v){
        key = k;
        val = v;
        prev = NULL;
        next = NULL;
    }
    
};
class LRUCache {
    Node * head;
    Node * tail;
    int size;
    int s;
    unordered_map<int,Node *>mp;
    void change(int key, int value){
        Node * node = mp[key];
        if(node == head){
            head->val = value;
            return;
        }
        else if(node == tail){
            Node * temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            temp ->next = head;
            head->prev = temp;
            head = temp;
        }
        else{
            Node * temp = node;
            temp->next->prev = temp->prev; 
            temp->prev->next = temp->next;
            temp ->next = head;
            head->prev = temp;
            head = temp;
        }
        head->val = value;
    }
public:
    LRUCache(int capacity) {
        head = NULL;
        tail = NULL;
        size = capacity;
        s = 0;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())return -1;
        Node * node = mp[key];
        if(node == head)return node->val;
        else if(node == tail){
            Node * temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            temp ->next = head;
            head->prev = temp;
            head = temp;
        }
        else{
            Node * temp = node;
            temp->next->prev = temp->prev; 
            temp->prev->next = temp->next;
            temp ->next = head;
            head->prev = temp;
            head = temp;
        }
        return head->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            change(key, value);
            return;
        }
        Node * node = new Node(key,value);
        s++;
        if(head == NULL){
            head = node;
            tail = node;
        }
        else{
            node->next = head;
            head->prev = node;
            head = node;
        }
        if(s > size){
            s--;
            mp.erase(tail->key);
            tail = tail->prev;
            tail->next = NULL;
        }
        mp[key] = node;
    }
};
int main(){
}