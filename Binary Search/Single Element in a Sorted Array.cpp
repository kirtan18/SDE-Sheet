https://leetcode.com/problems/single-element-in-a-sorted-array/


/////////////////////////////////////////////// Brute-Force // T.C = O(N) // S.C = O(1) ///////////////////////////////////////////////

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            ans ^= nums[i];
        }
        return ans;
    }
};


////////////////////////////////////////////// Optimal // T.C = O(logN) /// S.C = O(1) ////////////////////////////////////////////////////////

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-2;
        
        while(low <= high){
            int mid = (low+high) >> 1;
            if(nums[mid] == nums[mid^1]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return nums[low];
    }
};

