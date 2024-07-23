// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         if (strs.size() == 0)
//             return "";
        
//         sort(strs.begin(), strs.end());
//         string first = strs[0];
//         string last = strs[strs.size() - 1];
//         int c = 0;
//         while(c < first.size())
//         {
//             if (first.at(c) == last.at(c))
//                 c++;
//             else
//                 break;
//         }
//         return c == 0 ? "" : first.substr(0, c);
//     }
// };

class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int ans = s[0].length(), n = s.size();
        for(int i=1; i<n; i++){
            int j = 0;
            while(j<s[i].length() && s[i][j]==s[0][j])j++;
            ans = min(ans, j);
        }
        return s[0].substr(0, ans);
    }
};