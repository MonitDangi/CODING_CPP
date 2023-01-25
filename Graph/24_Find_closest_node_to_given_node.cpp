#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int>distFrom1(n,-1);
        vector<int>distFrom2(n,-1);
        int dist = 0;
        queue<int>rem;
        rem.push(node1);
        while(!rem.empty()){
            int node =rem.front();
            rem.pop();
            distFrom1[node] =  dist++;
            if(edges[node] != -1 && distFrom1[edges[node]] == -1)rem.push(edges[node]);
        }
        dist = 0;
        rem.push(node2);

        while(!rem.empty()){
            int node =rem.front();
            rem.pop();
            distFrom2[node] =  dist++;
            if(edges[node] != -1 && distFrom2[edges[node]] ==-1)rem.push(edges[node]);
        }
        dist = INT_MAX;
        int ans = -1;
        for(int i = 0; i < n; i++){
            if(distFrom1[i] !=-1 && distFrom2[i] !=-1){
                int m = max(distFrom1[i], distFrom2[i]);
                if(m < dist){
                    dist = m;
                    ans = i;
                }
            }
        }
        return ans;
    }
};
int main(){
}