class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> sorted;

        int len1 = nums1.size(), len2 = nums2.size(), i = 0, j = 0;

        while(i < len1 && j < len2){
            if(nums1[i] <= nums2[j]) sorted.push_back(nums1[i++]);
            else sorted.push_back(nums2[j++]);
        }

        while(i < len1) sorted.push_back(nums1[i++]);
        while(j < len2) sorted.push_back(nums2[j++]);

        int mid = (len1 + len2) / 2;

        if(mid % 2 == 1 || mid == 0) return sorted[mid];
        else return (sorted[mid] + sorted[mid - 1]) / 2.0; 



        
        
    }
};