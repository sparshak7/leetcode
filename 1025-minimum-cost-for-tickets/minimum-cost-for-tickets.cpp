class Solution {
public:
    int sub(vector<int> &day, vector<int> &cost, int si, vector<int> &dp)
    {
        int n = day.size();
        
        if(si>=n) return 0;
        
        if(dp[si]!=-1) return dp[si];
        
        int cost_day = cost[0] + sub(day , cost , si+1, dp);
        
        int i = si;
        while(i<n && day[i]<day[si]+7) i++;
        
        // for(i = si ; i<n and day[i]<day[si]+7 ; i++);
        
        int cost_week = cost[1] + sub(day, cost, i, dp);
        
        // for(i = si ; i<n and day[i]<day[si]+30 ; i++);
        i = si;
        while(i<n && day[i]<day[si]+30) i++;
        
        int cost_month = cost[2] + sub(day, cost, i, dp);      
        
        return dp[si] = min({cost_day, cost_week , cost_month  });
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, -1);
        return sub(days,costs,0,dp);
    }
};