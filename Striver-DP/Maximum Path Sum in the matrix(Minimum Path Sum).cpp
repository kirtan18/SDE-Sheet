   CN  : https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
   LC  : https://leetcode.com/problems/minimum-path-sum/


////////////////////////////////////// Memoization || T.C = O(N*N) || S.C = O(N) + O(N*M) /////////////////////////////////////

int getMaxUtil(int i, int j, int m, vector<vector<int>> &matrix, 
vector<vector<int> > &dp){
    
    // Base Conditions
    if(j<0 || j>=m)
        return -1e9;
    if(i==0)
        return matrix[0][j];
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int up = matrix[i][j] + getMaxUtil(i-1,j,m,matrix,dp);
    int leftDiagonal = matrix[i][j] + getMaxUtil(i-1,j-1,m,matrix,dp);
    int rightDiagonal = matrix[i][j] + getMaxUtil(i-1,j+1,m,matrix,dp);
    
    return dp[i][j]= max(up,max(leftDiagonal,rightDiagonal));
    
}

int getMaxPathSum(vector<vector<int> > &matrix){
    
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<vector<int>> dp(n,vector<int>(m,-1));
    
    int maxi = INT_MIN;
    
    for(int j=0; j<m;j++){
        int ans = getMaxUtil(n-1,j,m,matrix,dp);
        maxi = max(maxi,ans);
    }
    
    return maxi;
}


//////////////////////////////////////////// Tabulation || T.C = O(N*M) || S.C = O(N*M) ////////////////////////////////////

#include <bits/stdc++.h>
int getMaxPathSum(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<int>prev(m,0),curr(m,0);
    int ans = INT_MIN;
    
    for(int j=0; j<m; j++){
        prev[j] = mat[n-1][j];
    }
    
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<m;j++){
                int down_l = INT_MIN;
                int down = INT_MIN;
                int down_r = INT_MIN;
                
                if(j-1 >= 0) down_l = mat[i][j] + prev[j-1];
                down = mat[i][j] + prev[j];
                if(j+1 < m)down_r = mat[i][j] + prev[j+1];
                
                curr[j] = max(down_l , max(down,down_r));
            
        }
        prev = curr;
    }
    for(int i=0;i<m;i++){
        ans = max(ans,prev[i]);
    }
    return ans;
}
