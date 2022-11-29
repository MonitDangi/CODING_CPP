#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*>st;
        ListNode * trav = head;
        while(trav){
            while(st.size() && st.top()->val < trav->val)st.pop();
            st.push(trav);
            trav = trav->next;
        }
        trav = NULL;
        while(st.size()){
            st.top()->next = trav;
            trav = st.top();
            st.pop();
        }
        return trav;
    }
};
int main(){
 
    return 0;
}