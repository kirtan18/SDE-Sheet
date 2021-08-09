https://leetcode.com/problems/rotate-image/

// Brute force : using extra space matrix
// T.C = O(N^2)
// S.C = O(N)  

  
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        vector<vector<int>>ans;
        
        int n = matrix[0].size();
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){           
                ans[j][n-1].push_back(matrix[i][j]);
            }
            n--;
        }
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                matrix[i][j] = ans[i][j];
            }
        }
    }
};  

////////////////////////////////////////////////////////////


// Optimal 
// T.C = O(N^2)
// S.C = O(1)

  
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        for(int i = 0 ; i < n ; i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};  
  
  
