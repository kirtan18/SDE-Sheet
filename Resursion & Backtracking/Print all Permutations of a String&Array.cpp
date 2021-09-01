https://leetcode.com/problems/permutations/

/////////////////////////////////////////////////  First Approch : Using Extra Space /////////////////////////////////////
                                                   T.C = O(N!) * O(N)
                                                   S.C = O(N) + O(N)
  
class Solution {
    void Permutation(vector<int>& nums,vector<vector<int>>&ans,vector<int>&ds, int freq[]){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(!freq[i]){
                freq[i] = 1;
                ds.push_back(nums[i]);
                Permutation(nums,ans,ds,freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        int freq[nums.size()];
        for(int i = 0  ; i < nums.size() ; i++){
            freq[i] = 0;
        }
        Permutation(nums,ans,ds,freq);
        return ans;
    }
};                                    



/////////////////////////////////////////////////  Second Optimal Approch : Without Extra Space /////////////////////////////////////
                                                   T.C = O(N!) * O(N)
                                                   S.C = O(1)
                                                   A.Xx = O(N) for rec  

class Solution {
    
    void Permutations(int ind ,vector<int>& nums , vector<vector<int>>&ans){
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i = ind ; i < nums.size() ; i++){
            swap(nums[ind],nums[i]);
            Permutations(ind+1,nums,ans);
            swap(nums[ind],nums[i]);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        Permutations(0,nums,ans);
        return ans;
    }
};

 
