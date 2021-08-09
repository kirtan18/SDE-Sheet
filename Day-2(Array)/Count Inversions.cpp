https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#

Brute Force 
T.C = O(N^2)
S.C = O(1)
 
 long long int inversionCount(long long arr[], long long N)
    {
        long long int cnt = 0;
        
        for(long long int i = 0 ; i < N ; i++){
            for(long long int j = i ; j < N ; j++){
                if(arr[i] > arr[j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Optimal 
T.C = O(NlogN)
S.C = O(N)
  
  

long long int merge(long long arr[], long long temp[], long long left, long long mid,long long right)
{
    long long i, j, k;
    long long inv_count = 0;
 
    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
 
            /* this is tricky -- see above
            explanation/diagram for merge()*/
            inv_count = inv_count + (mid - i);
        }
    }
 
    /* Copy the remaining elements of left subarray
(if there are any) to temp*/
    while (i <= mid - 1)
        temp[k++] = arr[i++];
 
    /* Copy the remaining elements of right subarray
       (if there are any) to temp*/
    while (j <= right)
        temp[k++] = arr[j++];
 
    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
} 
    
long long int _mergesort(long long arr[] , long long temp[] , long long left, long long right){
    long long mid , count = 0;
    if(right > left){

       mid = (left+right)/2;

       count += _mergesort(arr,temp,left,mid);
       count += _mergesort(arr,temp,mid+1,right);

       count += merge(arr,temp,left,mid,right);
    }
        return count;
    }
    
long long int inversionCount(long long arr[], long long N){
       
        long long temp[N];
        return  _mergesort(arr,temp,0,N-1);
         
    }

};
  
