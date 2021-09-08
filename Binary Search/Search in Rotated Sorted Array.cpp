https://leetcode.com/problems/search-in-rotated-sorted-array/


///////////////////////////// Brute - Force /// T.C = O(N) ///// S.C = O(1) //////////////////////////////////////////

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int cnt = 0;
        int flag = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == target){
                flag = 1;
                break;
            }
            cnt++;
        }
        
        if(flag == 0){
            return -1;
        }
        else{
            return cnt;
        }        
    }
};

///////////////////////////  Optimal // T.C = O(logn) // S.C = O(1) //////////////////////////////////////////

class Solution {
public:
    int search(vector<int>& nums, int target) {
         int l = 0;
         int r = nums.size()-1;
         
         while(l <= r){
             int mid = (l+r) >> 1;
             
             if(nums[mid] == target){
                 return mid;
             }
             
             else if(nums[l] <= nums[mid]){
                 if(target >= nums[l] and target < nums[mid]){
                     r = mid-1;
                 }
                 else{
                     l = mid+1;
                 }
             }
             else{
                 if(target > nums[mid] and target <= nums[r]){
                     l = mid+1;
                 }
                 else{
                     r = mid-1;
                 }
             }
         } 
        return -1;
    }
};
