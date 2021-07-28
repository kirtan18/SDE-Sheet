
/////////////////////////////////////////////////////// Kadanes Algo || T.C = O(N) || S.C  = O(1) ////////////////////////////////////////////////////////

  int maxSubArray(vector<int>& nums) {
        int sum = 0 , maxi = INT_MIN;
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            sum += nums[i];
            if(sum > maxi)maxi = sum;
            if(sum < 0)sum = 0;
        }
        return maxi;
    }

/////////////////////////////////////////////////// Using DP || T.C = O(N) || S.C = O(N) ///////////////////////////////////////////////////////////////

int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        int maxi = nums[0];
        dp[0] = nums[0];
        
        for(int i = 1 ; i < n ; i++){
            dp[i] = max(nums[i] , nums[i] + dp[i-1]);
            maxi = max(dp[i],maxi);
        } 
        return maxi;
    }


