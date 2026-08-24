class Solution {
    void solve(int idx,vector<int>& nums,vector<int> &curr,vector<vector<int>> &ans){
        if(0==nums.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            curr.push_back(nums[i]);
            vector<int> temp;
            for(int p=idx;p<i;p++){
                temp.push_back(nums[p]);
            }
            for(int q=i+1;q<nums.size();q++){
                temp.push_back(nums[q]);
            }
            solve(0,temp,curr,ans);

            curr.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0,nums,curr,ans);
        return ans;
    }
};