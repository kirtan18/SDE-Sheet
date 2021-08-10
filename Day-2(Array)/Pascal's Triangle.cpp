https://leetcode.com/problems/pascals-triangle/

question 1 : n = 5 , r = 4 then find value of in pascal so 
 
   formula  = (n-1)C(r-1)  ==  4 C 3 
   T.C = O(N)  
   S.C = O(1)
   
question 2 : find 5th row value in pascel so using above formula in factorial in row
  T.C = O(N) 
  S.C = O(N)
  
 
Optimal 
 T.C = O(N) 
 S.C = O(N)
  
  class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>v(numRows);
        
        for(int i = 0 ; i < numRows ; i++){
            
            v[i].resize(i+1);
            v[i][0] = v[i][i] = 1;
            
            for(int j = 1 ; j < i ; j++){
                v[i][j] = v[i-1][j-1] + v[i-1][j];
            }
        }
        return v;
    }
};
 
  
  
