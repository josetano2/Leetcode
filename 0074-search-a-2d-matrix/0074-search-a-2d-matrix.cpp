class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int lenI = matrix.size(), lenJ = matrix[0].size();

        if(lenI == 0 || lenJ == 0){
            return false;
        }

        int left = 0, right = lenI * lenJ - 1;

        while(left <= right){
            int mid = left + (right - left) / 2, val = matrix[mid / lenJ][mid % lenJ];
            if(val == target){
                return true;
            }
            else if(val < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        return false;

    }
};