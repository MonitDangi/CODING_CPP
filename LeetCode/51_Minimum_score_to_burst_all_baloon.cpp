#include<bits/stdc++.h>
using namespace std;
class Solution {
    static bool comp(vector<int>&a, vector<int>&b){
        return b[1] > a[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
        int count  = 1;
        int prev = points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0] <= prev){
                continue;
            }
            else {
                count++;
                prev = points[i][1];
            }
        }
        return count;
    }
};
int main(){
}