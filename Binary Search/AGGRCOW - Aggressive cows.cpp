https://www.spoj.com/problems/AGGRCOW/


T.C = O(NlogN)
S.C = O(1)
  
  
bool canPlaceCow(int a[] , int n , int cows , int dist){
    int curr = a[0];
    int cnt = 1;

    for(int i = 1 ; i < n ; i++){
        if(a[i] - curr >= dist){
            curr = a[i];
            cnt++;
        }
        if(cnt == cows){
            return true;
        }
    }
    return false;
}

void solve(){
     int n , cows;
     cin >> n >> cows;
     int a[n];
     for(int i = 0 ; i < n ; i++){
        cin >> a[i];
     }
     sort(a,a+n);
     int low = 1 , high = a[n-1] - a[0];
     int res = 0;
     while(low <= high){
        int mid = (low + high) >> 1;
        if(canPlaceCow(a,n,cows,mid) == true){
           res = max(res,mid);
           low = mid + 1;
        }
        else{
          high = mid - 1;
        }
     }
     cout << res << "\n"; 
}  
