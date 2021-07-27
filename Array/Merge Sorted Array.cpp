https://leetcode.com/problems/merge-sorted-array/

class Solution {
public:
//     brute force 
    // time  == O(klogk)  space == O(1)
    // copy element of second array into first and sort the merged array
    
    // optimal
    // time == O(k) m+n        space = O(1)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m-1,p2 = n-1,i = m+n-1;
        
        while(p2>=0){
            if(p1>=0 && p2>=0){                     
              if( nums2[p2] > nums1[p1]){
                nums1[i--] = nums2[p2--];
              }
              else{
                nums1[i--] = nums1[p1--];
              }
            }
            else{
                nums1[i--] = nums2[p2--];
            }
        } 
    }
};
