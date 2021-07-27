https://leetcode.com/problems/sort-colors/submissions/

//////////////////////////////////////////////////////  T.c = O(NlogN) || S.C = O(1) //////////////////////////////////
  
      => sort the array and return 

//////////////////////////////////////////////////// using counting sort ///////////////////////////////////////////
           0 1 0 2 1 1 0
        => in this approch count all the number and put number wise like 
           1 -> 3 times
           2 -> 2 times
           0 -> 2 times
           
           so  print first  all zero -> 0 0 then all first 1 1 1  then all two 2 2  so answer = 0 0 1 1 1 2 2
        
///////////////////////////////////////////////////// Douch algo  || T.C = O(N) || S.C = O(1) //////////////////////////////////////////////////////////////////////////
        

    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return;
        
        int l = 0 , m = 0 , r = n-1;
        
        while(m <= r){            
            if(nums[m] == 0){
                swap(nums[l],nums[m]);
                l++;
                m++;
            }
           else if(nums[m] == 1){
                m++;
            }
            else{
                swap(nums[m],nums[r]);
                r--;
            }   
        }
      }
