https://leetcode.com/problems/subsets-ii/


///////////////////////////////////////////// 1st approch ///////////////////////////////////////////////////

== > Generate all the subsets and then push into set so in set do not enter any duplicate so we use set.
     T.C = O(2^N) + M * LogM[for set push]
 
///////////////////////////////////////////// 2nd Optimal  ///////////////////////////////////////////////////
  class Solution {
    void func(int ind ,vector<int>& nums, vector<int>&ds ,vector<vector<int>>&ans){
        ans.push_back(ds);
        for(int i = ind ; i < nums.size() ; i++){
            if(i != ind && nums[i] == nums[i-1])continue;
            ds.push_back(nums[i]);
            func(i+1,nums,ds,ans);
            ds.pop_back();
        }
    } 
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        func(0,nums,ds,ans);
        return ans;
    }
};


