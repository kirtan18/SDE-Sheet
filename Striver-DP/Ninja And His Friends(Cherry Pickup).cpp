// https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0


/////////////////////////////////////////// Memoization || T.C = O(N*M*M)*9 || S.C = O(N*M*M) * O(N)(Stack recusion) ////////////////////////////////////////////////


int solve(int i,int j1,int j2,int r,int c,vector<vector<int>> &grid,vector<vector<vector<int>>>&dp){
    if(j1<0 || j1 >=c || j2<0 || j2>=c )return -1e8;
    if(i == r-1){
        if(j1 == j2) return grid[i][j1];
        else{
            return grid[i][j1] + grid[i][j2];
        }
    }
    if(dp[i][j1][j2] != -1)return dp[i][j1][j2];
    int maxi = -1e8;
    for(int x = -1 ; x <= +1; x++){
        for(int y = -1 ; y <= +1 ; y++){
           int value = 0;
           if(j1 == j2) value = grid[i][j1];
           else value =  grid[i][j1] + grid[i][j2];
           value += solve(i+1,j1+x,j2+y,r,c,grid,dp);
           maxi = max(maxi,value);
        }
    }
    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return solve(0,0,c-1,r,c,grid,dp);
}

/////////////////////////////////////////// Tabulation || T.C = () || S.C = () ////////////////////////////////////////////////

int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,0)));
    
    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1 == j2) dp[n-1][j1][j2] = grid[n-1][j1];
            else{
                dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2]; 
            }
        }
    }
    
    for(int i=n-2;i>=0;i--){
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                int maxi = -1e8;
                for(int x = -1 ; x <= +1; x++){
                    for(int y = -1 ; y <= +1 ; y++){
                       int value = 0;
                       if(j1 == j2) value = grid[i][j1];
                       else value =  grid[i][j1] + grid[i][j2];
                       if(j1+x >= 0 && j1+x < m && j2+y >= 0 && j2+y < m){ 
                           value += dp[i+1][j1+x][j2+y];
                       }else{
                           value += -1e8;
                       }
                       maxi = max(maxi,value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m-1];
}

