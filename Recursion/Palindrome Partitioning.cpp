https://leetcode.com/problems/palindrome-partitioning/


class Solution {
    
    bool isPalindrome(string s, int start,int end){
         while(start <= end){
             if(s[start++] != s[end--]){
                 return false;
             }
         }
        return true;
    }
    
    void func(int ind,vector<string>&path,vector<vector<string>>&ans,string s){
        if(ind == s.size()){
            ans.push_back(path);
            return;
        }
        for(int i = ind ; i < s.size() ; i++){
            if(isPalindrome(s,ind,i)){
                path.push_back(s.substr(ind , i-ind+1));
                func(i+1,path,ans,s);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>path;
        func(0,path,ans,s);
        return ans;
    }
};
