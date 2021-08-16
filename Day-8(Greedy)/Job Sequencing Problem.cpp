https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<int>ans;
        sort(arr,arr+n,compare);
        int maxi = arr[0].dead;
        for(int i = 1 ; i < n ; i++){
            maxi = max(maxi,arr[i].dead);
        }
        
        int slot[maxi+1];
        for(int i = 0 ; i <= maxi ; i++){
            slot[i] = -1;
        }
        
        int countJob = 0 , profitJob = 0;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = arr[i].dead ; j > 0 ; j--){
                if(slot[j] == -1){
                    slot[j] = i;
                    countJob++;
                    profitJob += arr[i].profit;
                    break;
                }
            }
        }
        ans.push_back(countJob);
        ans.push_back(profitJob);
        return ans;
    } 
