https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#
https://leetcode.com/problems/set-mismatch/

//////////////////////////////////////////////////////  Using Hashmap || T.C = O(2N) || S.C = O(N) //////////////////////////////////////////////

 vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,bool>mp;
        vector<int>v;
        for(int i = 0 ; i < nums.size() ; i++){
            
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]] = true;
            }
            else{
                 v.push_back(nums[i]);
            }
        }
        
        for(int i = 1 ; i <= nums.size() ; i++){
            if(mp.find(i) == mp.end()){
                v.push_back(i);
            }
        }
        return v;
    }

////////////////////////////////////////////////////////////// using math || T.C = exceed || S.C = O(N) //////////////////////////////////////////////////////////////////////

==> exam : [4,3,6,2,1,1]   output : missing : 5  || Repiting  = 1
   
  1 + 2 + 3 + 4 + 5 + 6 + ..... + n =  n * (n + 1) / 2 = s
  
    s - (4,3,6,2,1,1)
    (1,2,3,4,5,6) - (4,3,6,2,1,1)
       (5)    -       (1)        =  4
        x     -        y         =  4    
  
  
  1^2 + 2^2 + 3^2 + 4^2 + 5^2 + 6^2 + ...... N^2 = n * (n + 1) * (2n + 1) / 6 = s^2  
  
                    s^2                  -  (4^2 , 3^2 , 6^2 , 2^2 , 1^2 , 1^2) 
    
     (1^2 , 2^2 , 3^2 , 4^2 , 5^2 , 6^2) -  (4^2 , 3^2 , 6^2 , 2^2 , 1^2 , 1^2) 
             
                   (5^2)                 -          (1^2)        =   24
                    x^2                  -           y^2         =   24
    
    so 
    
    
        x - y = 4
       x^2 - y^2 = 24
       (x-y)(x+y) = 24
         4(x+y) = 24
          (x+y) = 6
           x = 6 - y
           
           x - y = 4
           (6-y) - y  = 4
           y = 1
           x = 5
    
 
  
///////////////////////////////////////////////////////////////////  T.C = O(N) || S.C = O(1) //////////////////////////////////////////////////////////
  
  first see the video : https://www.youtube.com/watch?v=5nMGY4VUoRY&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=4
    
  void getTwoElements(int arr[], int n, int* x, int* y){

    int xor1;
    int set_bit_no;

    *x = 0;
    *y = 0;

    xor1 = arr[0];
    /* Get the xor of all array elements */
    for(int i=1;i<n;i++){
        xor1 = xor1^arr[i];
    }
    
    for(int i=1;i<=n;i++){
        xor1 = xor1^i;
    }
    
    /*Get the rightmost set bit in set_bit_no*/
    set_bit_no =  xor1 & ~(xor1 - 1);

    for(int i=0; i<n ;i++){
        /*here we check rightmost is 1 or not means 4 -> 100  so 6 -> 110 and in this right most is 1 so and 3->011 this is not rightmost is 1 so */
        if(arr[i] & set_bit_no){
            *x = *x ^ arr[i];
        }
        else{
            *y = *y ^ arr[i];
        }
    }

    for(int i=1;i<=n;i++){
        if(i & set_bit_no){
            *x = *x ^ i;
        }
        else{
            *y = *y ^ i;
        }
    }
}
  
  
  
  
  
  
  
  
  
  
  
  
  
  
