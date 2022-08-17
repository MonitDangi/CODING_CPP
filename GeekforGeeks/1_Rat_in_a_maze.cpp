//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++



class Solution{
    vector<string>ans;
    vector<vector<int>>pos;
    int n1;
    string str;
    private:
    void solver(int i,int j){
        if(i==n1-1&&j==n1-1&&pos[i][j]==1){
            ans.push_back(str);
            return;
        }
        else if(i==n1||j==n1||i<0||j<0){
            return;
        }
        if(pos[i][j]==0)return;
        pos[i][j]=0;
        str.push_back('D');
        solver(i+1,j);
        str.pop_back();
        str.push_back('R');
        solver(i,j+1);
        str.pop_back();
        str.push_back('L');
        solver(i,j-1);
        str.pop_back();
        str.push_back('U');
        solver(i-1,j);
        str.pop_back();
        pos[i][j]=1;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        pos=m;
        n1=n;
        solver(0,0);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;