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
        
        int cost_week = cost[1] + sub(day, cost, i, dp);
        
        i = si;
        while(i<n && day[i]<day[si]+30) i++;
        
        int cost_month = cost[2] + sub(day, cost, i, dp);      
        
        return dp[si] = min({cost_day, cost_week , cost_month  });
    }
    
    int tab(vector<int> &day, vector<int> &cost)
    {
        int n = day.size();
        
        vector<int> dp(n+1, 0);
        
        dp[n] = 0;
        
        for(int si=n-1;si>=0;si--) {
            int cost_day = cost[0] + dp[si+1];
        
            int i = si;
            while(i<n && day[i]<day[si]+7) i++;

            int cost_week = cost[1] + dp[i];

            i = si;
            while(i<n && day[i]<day[si]+30) i++;

            int cost_month = cost[2] + dp[i];  

            dp[si] = min({cost_day, cost_week , cost_month  });
        }
        return dp[0];
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, -1);
        // return sub(days,costs,0,dp);
        return tab(days, costs);
    }
};