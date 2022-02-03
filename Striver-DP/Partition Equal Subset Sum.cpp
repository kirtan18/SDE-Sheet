// https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

////////////////////////////////////////////////////////// Memoization || T.C = O(n * tar) || S.C = O(N*Tar) + O(N) /////////////////////////////////////////////////////

bool solve(int ind,int tar,vector<int> &arr,vector<vector<int>>&dp){
    if(tar == 0)return true;
    if(ind == 0) return (arr[0] == tar);
    if(dp[ind][tar] != -1)return dp[ind][tar];
    bool not_take = solve(ind-1,tar,arr,dp);
    bool take = false;
    if(tar >= arr[ind]){
        take = solve(ind-1,tar-arr[ind],arr,dp);
    }
    return dp[ind][tar] = take | not_take;
}


bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    int sum = 0;
    
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    if(sum % 2 != 0){
        return false;
    }
    return solve(n-1,sum/2,arr,dp);
}


///////////////////////////////////////////////////////// Tabulation || T.C = O(n * tar) || S.C = O(N*Tar) //////////////////////////////////////////////

bool subsetSumToK(int n, int k, vector<int> &arr) {
    int sum = 0;
    
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    if(sum % 2 != 0){
        return false;
    }
    
    k = sum/2;
    vector<vector<bool>>dp(n,vector<bool>(k+1,0));
    
    for(int i=0;i<n;i++) dp[i][0] = true;
    dp[0][arr[0]] = true;
    
    for(int ind=1;ind<n;ind++){
        for(int tar=1;tar<=k;tar++){
            bool not_take = dp[ind-1][tar];
            bool take = false;
            if(tar >= arr[ind]){
                take = dp[ind-1][tar-arr[ind]];
            }
            dp[ind][tar] = take | not_take;
        }
    }
    return dp[n-1][k];
}
