#include<bits/stdc++.h>
using namespace std;
class FrontMiddleBackQueue {
    deque<int>first;
    deque<int>second;
    int s1, s2;
public:
    
    void pushFront(int val) {
        first.push_front(val);
        s1++;
        if(s1 - s2 > 1){
            second.push_front(first.back());
            first.pop_back();
            s1--;
            s2++;
        }
    }
    
    void pushMiddle(int val) {
        if(s1==0){
            first.push_front(val);
            s1++;
        }
        else{
            if(s1 == s2){
                first.push_back(val);s1++;
            }
            else{
                int v = first.back();
                second.push_front(v);
                first.pop_back();
                first.push_back(val);
                s2++;
            }
        }
    }
    
    void pushBack(int val) {
        if(s1==0){
            first.push_front(val);
            s1++;
        }
        else{
            second.push_back(val);
            s2++;
            if(s2 - s1 > 0){
                first.push_back(second.front());
                second.pop_front();
                s1++;
                s2--;
            }
        }
    }
    
    int popFront() {
        if(first.size()==0)return -1;
        int a = first.front();
        first.pop_front();
        s1--;
        if(s2 - s1 > 0){
            first.push_back(second.front()); 
            second.pop_front();
            s2--;
            s1++;
        }
        return a;
    }
    
    int popMiddle() {
        if(first.size()==0)return -1;
        int a = first.back();
        first.pop_back();
        s1--;
        if(s2 - s1 > 0){
            first.push_back(second.front());
            second.pop_front();
            s2--;
            s1++;
        }
        return a;
    }
    
    int popBack() {
        if(first.size()==0)return -1;
        if(second.size()==0){
            int a = first.back();
            first.pop_back();
            s1--;
            return a;
        }
        int a = second.back();
        second.pop_back();
        s2--;
        if(s1 - s2 > 1){
            second.push_front(first.back());
            first.pop_back();
            s1--;
            s2++;
        }
        return a;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
int main(){
    return 0;
}