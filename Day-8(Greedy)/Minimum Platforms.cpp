https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#


T.C = O(NlogN) + O(2N)
S.C = O(1)
/////////////////////////////////////////////////////////////////////////////

 int findPlatform(int arr[], int dep[], int n)
    {
         sort(arr,arr+n);
         sort(dep,dep+n);
         
         int plat_need = 1 , res = 1;
         int i = 1, j = 0;
         
         while(i < n && j < n){
             if(arr[i] <= dep[j]){
                 plat_need++;
                 i++;
             }
             else if(arr[i] > dep[j]){
                 plat_need--;
                 j++;
             }
             
             if(plat_need > res){
                 res = plat_need;
             }
         }
         return res;
    }
