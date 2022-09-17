class Node{
    public:
    int index;
    vector<Node*>next;
    vector<int>list;
    Node (){
        index = -1;
        next.resize(26,NULL);
    }
};
    
class Solution {
    bool isPal(string&word,int l,int r){
        while(l<r){
            if(word[l]!=word[r])return false;
            l++;
            r--;
        }
        return true;
    }
    void insert(Node * root, int ind, string & word){
        for(int i=word.size()-1;i>=0;i--){
            int j = word[i]-'a';
            if(root->next[j]==NULL){
                Node * neu = new Node();
                root->next[j] = neu; 
            }
            if(isPal(word,0,i)){
                root->list.push_back(ind);
            }
            root = root->next[j];
        }
        root->list.push_back(ind);
        root->index = ind;
    }
    void search(string word,int i,Node * root, vector<vector<int>>&ans){
        for(int j=0;j<word.length();j++){
            if(root->index>=0 && root->index!=i&&isPal(word,j,word.length()-1)){
                ans.push_back({i,root->index});
            }
            root =  root->next[word[j]-'a'];
            if(root==NULL)return;
        }
        for(int j:root->list){
            if(j==i)continue;
            ans.push_back({i,j});
        }
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        Node * head = new Node();
        for(int i = 0; i < words.size(); i++){
            insert(head,i,words[i]);
        }
        vector<vector<int>>ans;
        for(int i=0;i<words.size();i++){
            search(words[i],i,head,ans);
        }
        return ans;
    }
};