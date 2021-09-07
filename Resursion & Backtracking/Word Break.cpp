https://leetcode.com/problems/word-break/

class Solution {
public:
    int dp[10001];
    bool solve(int i , string s, set<string>& wordDict){
        
        if(i == s.size()){
            return 1;
        }
        
        string temp;
        if(dp[i] != -1)return dp[i];
        for(int j = i ; j < s.size() ; j++){
            temp += s[j];
            
            if(wordDict.find(temp) != wordDict.end()){
                if(solve(j+1,s,wordDict)){
                    return dp[i] = 1;
                }
            }
        }
        return dp[i] = 0;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        set<string>ans;
        for(auto it : wordDict)ans.insert(it);
        return solve(0,s,ans);
    }
};
