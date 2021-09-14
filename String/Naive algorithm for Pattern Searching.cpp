
Best = T.C = O(N)
Worst = T.C = O(m * (n-m+1))
S.C = O(1)
  
  
void solve(){
    string s1,s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    for(int i = 0 ; i <= n-m ; i++){

        int j;
        for(j = 0 ; j < m ; j++){
            if(s1[i+j] != s2[j]){
                break;
            }
        }
        if(j == m){
            cout << "Pattern found at index =" <<" "<< i <<"\n";
        }
    } 
}
  
