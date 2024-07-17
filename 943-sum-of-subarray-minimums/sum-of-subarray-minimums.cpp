class Solution {
public:
    void NSE(vector<int>& arr, vector<int>& nse) {
        int n = arr.size();
        stack<pair<int,int>> s;
        for(int i=n-1;i>=0;i--) {
            while(!s.empty() && arr[i]<=s.top().first) s.pop();
            nse[i] = s.empty() ? n - i : s.top().second - i;
            s.push({arr[i], i});
        }
    }
    
    void PSE(vector<int>& arr, vector<int>& pse) {
        int n = arr.size();
        stack<pair<int,int>> s;
        for(int i=0;i<n;i++) {
            while(!s.empty() && arr[i]<s.top().first) s.pop();
            pse[i] = s.empty() ? i+1 : i - s.top().second;
            s.push({arr[i], i});
        }
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        vector<int> pse(n);
        int mod = 1e9 + 7;
        NSE(arr, nse);
        PSE(arr, pse);
        int sum = 0;
        for(int i=0;i<arr.size();i++) {
            long long prod = (pse[i]*nse[i])%mod;
            prod = (prod*arr[i])%mod;
            sum = (sum + prod)%mod;
        }
        return sum;
    }
};