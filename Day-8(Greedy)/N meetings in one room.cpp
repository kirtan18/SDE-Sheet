https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#

///////////////////////////////////////////////////////////////////////////////
T.C = O(NlogN)
S.C = O(N)    


bool compare(const pair<int,int> &a,const pair<int,int> &b){
    return (a.second < b.second);
}
class Solution
{   
    public:

    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> v(n);
        for(int i = 0 ; i < n ; i++){
            v[i].first = start[i];
            v[i].second = end[i];
        }
        sort(v.begin(), v.end(), compare);
        
        int ans = 1;
        int limit = v[0].second;
        
        for(int i = 1 ; i < n ; i++){
            if(v[i].first > limit){
                limit = v[i].second;
                ans++;
            }
         }
    return ans;
    }
};
