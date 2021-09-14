https://practice.geeksforgeeks.org/problems/longest-prefix-suffix2527/1#


##################################   suffix   ####################################

class Solution{
  public:		
	int lps(string s) {
	    int n = s.size();
        int lps[n];
        int len = 0;
        lps[0] = 0;

        int i = 1; 
    
    while(i < n){
        if(s[i] == s[len]){
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
      
      int res = lps[n-1];
      
      return res;
	}
};


################################# Prefix #############################################


int largest_prefix_suffix(const std::string
                                      &str)
{
   
  int n = str.length();
   
  // if n is less than 2
  if(n < 2) {
    return 0;
  }
 
  int len = 0;
  int i = 1;
   
  // Iterate i till n
  while(i < n)
  {
     
    // If str[i] is equal to
    // str[len]
    if(str[i] == str[len])
    {
      ++len;
      ++i;
    }
    else
    {
      i = i - len + 1;
      len = 0;
    }
  }
   
  // Return len
  return len>n/2? len/2:len;
 
}

