https://leetcode.com/problems/combination-sum/


///////////////////////////////////////////////  T.C = O(2^N) * k || S.C = O(K*X)  ////////////////////////////////////////////


class Solution {
    
    void func(int ind,int target ,vector<int>&candidates,vector<int>&ds,vector<vector<int>>&ans){
        if(ind == candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        
        if(candidates[ind] <= target){
            ds.push_back(candidates[ind]);
            func(ind,target-candidates[ind],candidates,ds,ans);
            ds.pop_back();
        }        
        func(ind+1,target,candidates,ds,ans);
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        func(0,target,candidates,ds,ans);
        return ans;
    }
};
