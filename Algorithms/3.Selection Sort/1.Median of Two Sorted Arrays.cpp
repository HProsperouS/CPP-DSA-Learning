/*
Title:
4. Median of Two Sorted Arrays

Description:
Given two sorted arrays nums1 and nums2 of size m and n respectively, 
return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

Example 1:
	Input: nums1 = [1,3], nums2 = [2]
	Output: 2.00000
	Explanation: merged array = [1,2,3] and median is 2.

Example 2:
    Input: nums1 = [1,2], nums2 = [3,4]
	Output: 2.50000
	Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
	
Constraints:
	nums1.length == m
	nums2.length == n
	0 <= m <= 1000
	0 <= n <= 1000
	1 <= m + n <= 2000
	-106 <= nums1[i], nums2[i] <= 106
*/
class Solution {
private:
    void selectionSort(vector<int>& array){
        for(int i=0; i<array.size()-1; i++){
            int minIndex = i;
            for(int j=i+1; j<array.size(); j++){
                if(array[j] < array[minIndex]){
                    minIndex = j;
                }
            }
            swap(array[i], array[minIndex]);
        }
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(auto num:nums2){
            nums1.push_back(num);
        }

        selectionSort(nums1);
        int n = nums1.size();

        if(n%2){
            return nums1[n/2];
        }else{
            return (nums1[n/2-1] + nums1[n/2]) / 2.0;
        }
    }
};