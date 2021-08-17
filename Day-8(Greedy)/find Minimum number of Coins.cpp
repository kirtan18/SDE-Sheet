https://www.geeksforgeeks.org/greedy-algorithm-to-find-minimum-number-of-coins/

T.C = O(N)
S.C = O(1)

void solve(int v){
   int arr[] = {1,2,5,10,20,50,100,500,1000};
   int n = 9;
   vector<int>ans;
   int cnt = 0;
   for(int i = n-1 ; i >= 0 ; i--){
      
        while(v >= arr[i]){
            v -= arr[i];
            ans.pb(arr[i]);
            cnt++;
        }
   }
   cout << cnt << "\n";
}  

