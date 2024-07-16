class Solution {
public:
    bool bs(vector<int> &temp, int m, int target) {
        int l = 0;
        int h = m-1;
        while(l<=h) {
            int mid = l + (h-l)/2;
            if(temp[mid]==target) return true;
            else if(temp[mid]>target) {
                h = mid-1;
            }
            else l = mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++) {
            if(matrix[i][0]<=target && target<=matrix[i][m-1]) return bs(matrix[i], m, target);
        }
        return false;
    }
};