https://practice.geeksforgeeks.org/problems/subset-sums2234/1

///////////////////////////////////// T.C = O(2^N)+2^Nlog(2^N)[sort] || S.C = O(2^N) /////////////////////////////////////////////////////

 void func(int ind, int sum , vector<int>&arr, int N ,vector<int>&subsetSum){
        if(ind == N){
            subsetSum.push_back(sum);
            return;
        }
        func(ind+1, sum+arr[ind],arr ,N,subsetSum);
        func(ind+1, sum,arr,N,subsetSum);
    }
    
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>subsetSum;
        func(0,0,arr,N,subsetSum);
        sort(subsetSum.begin(),subsetSum.end());
        return subsetSum;
    }
