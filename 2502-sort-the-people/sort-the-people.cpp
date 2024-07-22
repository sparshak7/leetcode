class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector <pair<int,string>> v;
        vector <string> res;
        for(int i=0;i<heights.size();i++)
        {
            v.push_back({heights[i],names[i]});
        }
        sort(v.begin(),v.end());
        for(int i=v.size()-1;i>=0;i--)
        {
            res.push_back(v[i].second);
        }
        return res;
    }
};