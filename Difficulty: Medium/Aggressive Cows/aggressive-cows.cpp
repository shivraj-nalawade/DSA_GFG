class Solution {
  public:
    bool isPossible(vector<int> &arr, int k,int maxAllowedDist){
        int n = arr.size();
        int cows = 1, lastStallPosition = arr[0];
        for(int i=1; i<n; i++){
            if(arr[i]-lastStallPosition >= maxAllowedDist){
                cows++;
                lastStallPosition =arr[i];
            }
            if(cows == k){
            return true;
            }
        }
    return false;
        
    }
    
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(), arr.end());
        int n= arr.size();
        int st=1, end=arr[n-1]-arr[0];
        int ans=-1;
        while(st <= end){
            int mid = st +(end -st)/2;
            
            if(isPossible(arr, k, mid)){
                ans = mid;
                st = mid+1;
            }
            else{
                end= mid-1;
            }
        }
        return ans;
    }
};