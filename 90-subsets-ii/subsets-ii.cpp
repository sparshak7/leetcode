class Solution {
public:
    void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> &res, int index) {
        if(index==nums.size()) {
            ans.push_back(res);
            return;
        }
        
        res.push_back(nums[index]);
        solve(nums,ans,res,index+1);
        res.pop_back();
        
        while(index+1 < nums.size() && nums[index]==nums[index+1]) index++;
        solve(nums,ans,res,index+1);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> res;
        solve(nums, ans, res, 0);
        return ans;
    }
};