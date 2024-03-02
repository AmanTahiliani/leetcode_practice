"""
Leetcode 34. Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109

"""



"""
Solution:
This can be done by calculating the lower and upper bound on the sorted list.
We only move the value of first and last if we actually find the target
If we find that the first and last are the same as the one we initialized, '
it means that the given element is not present in the array at all and we 
should return [-1,-1]
"""


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        first = len(nums)
        if first == 0:
            return [-1,-1]
        l = 0
        h = len(nums) -1

        while l<=h:
            m = (l+h)//2
            # print(l,h,m)
            if nums[m]>=target:
                if nums[m]==target:
                    first = m
                h=m-1
            else:
                l=m+1
        if first == len(nums):
            return [-1,-1]
        # print(first)

        last = len(nums)-1
        l= 0
        h = len(nums) -1
        
        while l<=h:
            m = (l+h)//2
            if nums[m]>target:
                last = m-1
                h=m-1
            else:
                l = m+1
        return [first, last]
        