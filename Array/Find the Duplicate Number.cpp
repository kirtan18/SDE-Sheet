//https://leetcode.com/problems/find-the-duplicate-number/solution/

/////////////////////////////////Sorting method/////////////////////////////
//T.C. : O(nlogn)
//S.C. : O(n)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])
                return nums[i];
        }
        return -1;
    }
};

/////////////////////////////////Set method/////////////////////////////
//T.C. : O(n)
//S.C. : O(n)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        
        for (auto a : nums) {
            if (st.find(a) != st.end()){
                return a;
            }
            st.insert(a);
        }
        return -1;
    }
};

/////////////////////////////////Tortoise method/////////////////////////////
//T.C. : O(n)
//S.C. : O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
          
        do{
            slow = nums[slow]; 
            fast = nums[nums[fast]]; 
        }while(slow != fast);
        
        fast = nums[0];
        
        while(slow != fast){
             slow = nums[slow]; 
             fast = nums[fast]; 
        }
                       
        return slow;
    }
};

© 2021 GitHub, Inc.
