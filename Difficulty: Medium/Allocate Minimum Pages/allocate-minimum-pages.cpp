class Solution {
  public:
  
    bool isValid(vector<int> &arr, int k, long long mid){
        int n = arr.size();
        
        int student = 1;
        long long pages = 0;
        for(int i=0; i<n; i++){
            if(arr[i] > mid){
                return false;
            }
            
            if(pages + arr[i] <= mid){
                pages += arr[i];
            }
            else{
                student++;
                pages = arr[i];
            }
        }
        return student<=k;
    }
    
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(k > n) return -1;
        
        long long sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
        }
        long long st=0, end=sum;
        long long ans = -1;
        while(st<=end){
            long long mid = st + (end-st)/2;
            
            if(isValid(arr, k, mid)){
                ans = mid;
                end= mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return ans;
    }
};