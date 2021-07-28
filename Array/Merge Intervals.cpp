https://leetcode.com/problems/merge-intervals/

///////////////////////////////////////////////////////////////// 1'st Approch || T.C = O(NlogN) + O(N^2) ||S.C = O(N) //////////////////////////////////////////////////////////

//  Input: intervals = [[1,3],[2,6],[8,10],[9,9],[15,18]]
// Output: [[1,6],[8,10],[15,18]]

//   i :  first of all sort all of them
//   ii : check for all interval that merge with ith interval & merge it all. a linear scan for every interval is done.
       
//     like : [[1,3],[2,6],[8,10],[9,9],[15,18]]
//            [[1,6],[8,10],[9,9],[15,18]]  => in this [2,6] overlap in [1,3] so ans = [1,6]
//            [[1,6],[8,10],[15,18]]        => in this [8,10] overlap in [9,9] so ans = [8,10]
          
//  in this approch first i = [1,3] then check all of them then i move next so T.C = O(N^2)
             
         
             
///////////////////////////////////////////////////////////// Optimal || T.C = O(NLognN) + O(N) || S.C = O(N) ///////////////////////////////////////////////////////////////
             
// i : first of all sort all of them.
// ii : itrate one by one means 
    
//    [ [1,3] , [2,4] , [2,6] , [8,9] , [8,10] ,[9,11] , [15,18] , [16,17] ]
   
//    first  : [1,3] -> then [2,4] is over lap so merge -> [1,4] -> then [2,6] overlap so merge it  [1,6] then [8,9] this one not overlap so put [1,6] in temp 
//             [8,9] -> then [8,10] is overlap so merge -> [8,10] -> then [9,11] overlap so merge it [8,11] then [15,18] this one not overlap so put [8,11] in temp
//             [15,18] -> then [16,17] is overlap so merge -> [15,18] 
            
//             so ans = [ [1,6] , [8,11] ,[15,18] ] 
     
     

     
      vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>mergeinter;
        
        if(intervals.size() == 0){
            return mergeinter;
        }
        sort(intervals.begin(),intervals.end());
        vector<int>tempinterval = intervals[0];
        
        for(auto it : intervals){
            
            if(it[0] <= tempinterval[1]){
                tempinterval[1] = max(it[1] , tempinterval[1]);
            }
            else{
                mergeinter.push_back(tempinterval);
                tempinterval = it;
            }
        }
        mergeinter.push_back(tempinterval);
        return mergeinter;
    }
    
