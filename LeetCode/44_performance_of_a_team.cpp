#define f first
#define sc second

class Solution {
    int mod = (int)(1e9+7);
public:
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        vector<pair<int,int>>eng;
        for(int i=0;i<n;i++){
            eng.push_back({e[i],s[i]});
        }
        priority_queue<int,vector<int>,greater<int>>q;
        sort(eng.rbegin(),eng.rend());
        long long int sum =0 , ans =0;
        
        for(int i=0;i<n;i++){
            sum += eng[i].sc;
            q.push(eng[i].sc);
            if(q.size()>k){
                sum -= q.top();
                q.pop();
            }
            ans = max(ans,sum*eng[i].f);
        }
        return ans%mod;
    }
};