#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            string ans = s;
            s += s;
            for (int i = 1; i < ans.size(); ++i)
                ans = min(ans, s.substr(i, size(ans)));
            return ans;
        }
        sort(begin(s), end(s));
        return s;
    }
};
int main(){
    return 0;
}