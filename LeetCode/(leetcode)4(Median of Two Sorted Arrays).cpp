/*
문제 링크 : https://leetcode.com/problems/median-of-two-sorted-arrays/
정렬된 vector nums1과 nums2의 수를 비교하며 합쳐진 정렬된 vector merged_array를 만든다.

그런 다음 merged_array의 크기에 따라 median을 구하면 된다.
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged_array;
        int index1 = 0, index2 = 0;
        double ret;

        while (index1 < nums1.size() && index2 < nums2.size()) {
            if (nums1[index1] < nums2[index2]) {
                merged_array.push_back(nums1[index1]);
                index1++;
            }
            else {
                merged_array.push_back(nums2[index2]);
                index2++;
            }
        }

        if (index1 < nums1.size()) {
            for (int a = index1; a < nums1.size(); a++)  merged_array.push_back(nums1[a]);
        }
        if (index2 < nums2.size()) {
            for (int a = index2; a < nums2.size(); a++)  merged_array.push_back(nums2[a]);
        }

        if (merged_array.size() % 2 == 1)    ret = (double)merged_array[merged_array.size() / 2];
        else    ret = ((double)merged_array[(merged_array.size() / 2) - 1] + (double)merged_array[merged_array.size() / 2]) / 2;

        return ret;
    }
};