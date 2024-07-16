class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int index = 0, maxOne = 0;
        for(int i=0;i<mat.size();i++) {
            int count = 0;
            for(int j=0;j<mat[0].size();j++) {
                count+=mat[i][j];
                
                if(count>maxOne) {
                    maxOne = count;
                    index = i;
                }
            }
        }
        return {index, maxOne};
    }
};