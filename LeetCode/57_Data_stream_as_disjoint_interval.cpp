#include<bits/stdc++.h>
using namespace std;
class SummaryRanges {
    set<int>s;
    int low;
public:
    SummaryRanges() {
        low = INT_MAX;
    }
    
    void addNum(int value) {
        s.insert(value);
        low = min(low, value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans;
        int start = low;
        int end = low;
        for(auto it:s){
            if(it != start){
                if(end + 1 == it){
                    end = it;
                }
                else {
                    ans.push_back({start,end});
                    start = it;
                    end = it;
                }
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};
int main(){
}