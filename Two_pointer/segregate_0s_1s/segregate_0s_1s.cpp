class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int n = arr.size();
        int j = 1;
        int i = 0;
        while(j<n){
            if(arr[i]==1&&arr[j]==1){
                j++;
            }
            else if(arr[i]==1&&arr[j]==0){
                swap(arr[i],arr[j]);
                i++;
                j++;
            }
            else{
                i++;
                j++;
            }
        }
    }
};