https://leetcode.com/problems/trapping-rain-water/

////////////////////////////////////////////// Brute Force //////////////////////////////////////////////
T.C = O(N^2)
S.C = O(1)

 find leftsize  max  and right side max  then  min(Left_max ,Right_max) - a[i]  

////////////////////////////////////////////using prefix & suffix////////////////////////////////////////////
//T.C. : O(n)
//S.C. : O(2n)

class Solution {
public:
    int trap(vector<int>& arr) {
     
    int n=arr.size();
        
    if(n==0) return 0;
        
    int lmax[n],rmax[n];
    
    lmax[0]=arr[0];
    rmax[n-1]=arr[n-1];
    
    int res=0;
    
    for(int i=1;i<n;i++)
        lmax[i]=max(lmax[i-1],arr[i]);
    
    for(int i=n-2;i>=0;i--)
        rmax[i]=max(arr[i],rmax[i+1]);
    
    for(int i=1;i<n-1;i++)
        res+=min(lmax[i],rmax[i])-arr[i];
        
    return res;
    }
};


////////////////////////////////////////////using 2-Pointer////////////////////////////////////////////
//T.C. : O(n)
//S.C. : O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        int left = 0 , right = n-1;
        int ans = 0;
        int maxleft = 0 , maxright = 0;
        
        while(left <= right){
            if(height[left] <= height[right]){
                
                if(height[left] >= maxleft) maxleft = height[left];
                
                else ans += maxleft - height[left];
                left++;
                
            }
            else{
                
                if(height[right] >= maxright) maxright = height[right];
                
                else ans += maxright - height[right];
                right--;
            }
        }
        return ans;
    }
};
