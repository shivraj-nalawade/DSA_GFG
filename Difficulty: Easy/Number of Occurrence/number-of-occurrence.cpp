class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int st=0, end=n-1, first=-1, last = -1;
        int result;
        while(st<=end){
            int mid = st + (end - st)/2;
            
            if(arr[mid]== target){
                first = mid;
                end = mid-1;
            }
            else if(arr[mid] < target){
                st=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        
        if(first == -1) return 0;
        
        st=0, end=n-1;
        while(st<=end){
            int mid = st + (end - st)/2;
            
            if(arr[mid]== target){
                last = mid;
                st=mid+1;
            }
            else if(arr[mid] < target){
                st=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        
        return last - first +1;
        
    }
};
