// class Solution {
// public:
//     void solve(vector<int>& nums, vector<int> &res, set<vector<int>> &ans, unordered_map<int,int> &m) {
//         if(res.size()==nums.size()) {
//             // auto it = find(ans.begin(), ans.end(), res);
//             // if(it==ans.end()) ans.push_back(res);
//             // ans.push_back(res);
//             ans.insert(res);
//             return;
//         }
        
//         for(int i=0;i<nums.size();i++) {
//             if(m.find(nums[i])!=m.end()) continue;
//             m[nums[i]]++;
//             res.push_back(nums[i]);
//             solve(nums,res,ans,m);
//             m.erase(nums[i]);
//             res.pop_back();
//         }
        
//     }
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         vector<int> res;
//         set<vector<int>> ans;
//         unordered_map<int,int> m;
//         solve(nums,res,ans,m);
        
//         vector<vector<int>> ans1;
        
//         for(auto x: ans) {
//             ans1.push_back(x);
//         }
        
//         return ans1;
//     }
// };

class Solution {
public:

    void find(vector<int>& nums, int f[], vector<int>&ds, set<vector<int>> &ans){
        if(ds.size()==nums.size()){
            ans.insert(ds);
            return;
        }

        for(int i =0;i<nums.size();i++){
            if(f[i]==0){
                ds.push_back(nums[i]);
                f[i]=1;
                find(nums,f,ds,ans);
                ds.pop_back();
                f[i]=0;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        set<vector<int>> ans;
        vector<int> ds;
        int f[nums.size()];

        for(int i=0;i<nums.size();i++)
            f[i]=0;

        find(nums,f,ds,ans);

        vector<vector<int>>res;

        for(auto it : ans){
            res.push_back(it);
        }
        return res;
    }
};