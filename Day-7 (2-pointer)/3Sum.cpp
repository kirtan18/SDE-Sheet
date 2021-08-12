https://leetcode.com/problems/3sum/

////////////////////////////////////////////////////////////////////
Brute Force
T.C = O(N^3 * LogM)
S.C = O(M)  
  
using 2 for loop and a + b + c = 0 in get a,b,c value and put in set for unique then return it.
  
///////////////////////////////////////////////////////////////////
  
Better Approch
T.C = O(N^2 LogM)
S.C = O(M) + O(N)

using 2 for loop
c = -(a+b) so find a,b value using loop and check if -(a+b) is present in map then put in set.
 
///////////////////////////////////////////////////////////////////
 Optimal Approch
 T.C = O(N^2)
 S.C = O(N)
 Auxillary Space : O(1)
   
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        
        for(int i = 0 ; i < (int)nums.size()-2 ; i++){    
          
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])){
           
                int low = i+1 , high = nums.size()-1 , sum = 0 - nums[i];
                
                while(low < high){
                    if( nums[low] + nums[high] == sum){
                        
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[low]);
                        temp.push_back(nums[high]);
                        ans.push_back(temp);
                        
                        while(low < high && nums[low] == nums[low+1])low++;
                        while(low < high && nums[high] == nums[high-1])high--;
                        
                        low++,high--;
                    }
                    else if(nums[low] + nums[high] < sum) low++;

                    else high--;
                }    
            } 
        }
        return ans;
    }
};  
 
  
  
  


