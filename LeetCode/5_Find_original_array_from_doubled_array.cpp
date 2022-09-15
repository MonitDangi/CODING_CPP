class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int>ans;
        vector<int>empty;
        int n=0;
        map<int, int>mp;
        for(auto x : changed){
            mp[x]++;
        }
        int cnt =mp[0];
        if(cnt%2)return empty;
        cnt /= 2;
        while(cnt--)ans.push_back(0);
        mp.erase(0);
        for(auto x : mp){
            int num = x.first;
            if(mp.find(num)->second>mp.find(num*2)->second)return empty;
            int count = x.second;
            while(count--){
                ans.push_back(num);
                mp[num*2]--;
            }
        }
        return ans;
    }
};