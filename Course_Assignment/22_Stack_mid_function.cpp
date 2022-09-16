#include<bits/stdc++.h>
using namespace std;
int m = 1;
class Node{
    public:
    int val;
    Node * prev;
    Node * next;
    Node(int val){
        this->val = val;
        prev = NULL;
        next = NULL;
    }

};
class Stack{
    Node * head =NULL;
    Node * mid = NULL;
    Node * last = NULL;
    int m = 0;
    public:
    void insert(int v){
        Node * node = new Node(v);
        if(head==NULL){
            head=node;
            mid=node;
            last = node;
        }
        else{
            last->next=node;
            node->prev = last;
            last=node;
            if(m==0){
                mid=mid->next;
                m=1;
            }
            else if(m==1){
                m=0;
            }
        }
    }

    int returnMid(){
        if(head==NULL)return -1;
        return mid->val;
    }
    void deleteMid(){
        if(head==NULL)return;
        if(head ==  mid){
            head = NULL;
            mid = NULL;
            last = NULL;
        }
        else{
            if(m==1){
                mid=mid->prev;
                if(mid->next->next==NULL){
                    mid->next=NULL;
                }
                else{
                    mid->next->next->prev = mid;
                    mid->next = mid->next->next;
                }
                m=0;
            }
            else if(m==0){
                mid->prev->next=mid->next;
                mid->prev->next->prev = mid->prev;
                m=1;
            }
        }
    }
    
    void deleteLast(){
        if(head==NULL)return;
        if(head==last){
            head=NULL;
            mid=NULL;
            last=NULL;
        }
        last=last->prev;
        last->next=NULL;
        if(m==1){
            mid=mid->prev;
            m=0;
        }
        else if(m==0){
            m=1;
        }
    }
    void print(){
        Node * h = head;
        while(h!=NULL){
            cout<<h->val<<" ";
            h=h->next;
        }
    }
    void returnM(){
        cout<<m<<endl;
    }


};
int main(){
    Stack st;
    st.insert(1);
    cout<<st.returnMid()<<endl;
    st.insert(2);
    cout<<st.returnMid()<<endl;
    st.insert(3);
    cout<<st.returnMid()<<endl;
    st.insert(4);
    cout<<st.returnMid()<<endl;
    st.print();
    cout<<endl;
    st.deleteLast();
    st.print();
    cout<<endl;
    st.returnM();
    cout<<st.returnMid()<<endl;
    st.deleteLast();
    st.print();
    cout<<"\n"<<st.returnMid();
    return 0;
}