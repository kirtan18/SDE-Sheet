https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#

T.C = O(NlogN)
S.C = O(1)
  
struct Item{
    int value;
    int weight;
}  
  
bool comp(Item a , Item b){
    double r1 = double(a.value) / double(a.weight);
    double r2 = double(b.value) / double(b.weight);
    return r1 > r2;
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,comp);
        
        int curWeight = 0;
        double finalValue = 0.0;
        
        for(int i = 0 ; i < n ; i++){
            
            if(curWeight + arr[i].weight <= W){
                curWeight += arr[i].weight;
                finalValue += arr[i].value;
            }
            else{
                int remain = W - curWeight;
                finalValue += ( arr[i].value / double(arr[i].weight) * (double)remain);
                break;
            }
        }
        return finalValue;
    }
        
};
