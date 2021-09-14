https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/


T.C = O(M+N)
S.C = O(1)
  
////////////////////////////////////////////////////////////////////////////////////////////  
  
void fill_LPS(string pat, int m , int lps[]){
    int len = 0;
    
    //lps[0] is always 0
    lps[0] = 0;

    int i = 1;
    
    while(i < m){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
           if(len != 0){
              len = lps[len-1];
           }
           else{
              lps[i] = 0;
              i++;
           }
        }
    }
}

void solve(){
    
    string txt,pat;
    cin >> txt >> pat;

    int n = txt.size();
    int m = pat.size();
    
    int lps[m];

    fill_LPS(pat,m,lps);
    
    int i = 0 , j = 0;

    while(i < n){
        if(pat[j] == txt[i]){
            i++;
            j++;
        }
        if(j == m){
            cout << "Found Pattern at index : " << i - j <<"\n";
            j = lps[j-1];
        }
        else if(i < n && pat[j] != txt[i]){
            if(j != 0){
                j = lps[j-1];
            }
            else{
                i = i + 1;
            }
        }
    } 
    
}  
