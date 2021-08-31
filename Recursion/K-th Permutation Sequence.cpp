https://leetcode.com/problems/permutation-sequence/

1st Approch :

== >  First of all generate all the permutation and then store in data structure and sort all the data structure and then return (k-1)th value
      T.C = O(N!) * O(N)
      S.C = O(N)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
2nd Approch :
                  Traverese * Erase   
            T.C = O(N) * O(N) = O(N^2)
            S.C = O(N)  


  class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int>numbers;
        for(int i = 1 ; i < n ; i++){
            fact = fact * i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        k = k-1;
        string ans = "";
        
        while(true){
            ans = ans + to_string(numbers[k/fact]);
            numbers.erase(numbers.begin()+k/fact);
            if(numbers.size() == 0){
                break;
            }
            k = k % fact;
            fact = fact / numbers.size();
        }
        return ans;
    }
};
  


