#include<iostream>
#include<vector>
using namespace std;

int main(){
    int ans = 0;
    int m,n;
    cin>>m>>n;
    vector<vector<double>>p;
    vector<double>a;
    a.push_back(n);
    p.push_back(a);
    bool b = true;
    int s = 2;
    while(b){
        if(m == p.size())break;
        b = false;
        vector<double>v(s,0);
        for(int i = 0; i < s-1; i++){
            double val = p.back()[i];
            if(val>1){
                val--;
                v[i] += (val)/2;
                v[i+1] += (val)/2;
                b=true;
            }
        }
        s++;
        p.push_back(v);
    }
    for(int i = 0; i<p.size();i++){
        for(int j = 0; j<p[i].size();j++){
            if(p[i][j] >= 1)ans++;
        }
    }
    cout<<ans<<endl;
    return 0;

}