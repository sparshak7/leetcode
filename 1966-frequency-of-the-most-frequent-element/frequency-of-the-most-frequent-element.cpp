class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int start = 0, end = 0;
        long sum = 0;
        int ans = 1;
        while(end<nums.size()) {
            sum+=nums[end];
            end++;
            if(sum+k<((long)nums[end-1]*(end-start))) {
                sum-=nums[start];
                start++;
            }
            ans = max(ans, end-start);
        }
        return ans;
    }
};