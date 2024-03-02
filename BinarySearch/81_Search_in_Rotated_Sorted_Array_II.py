"""
81. Search in Rotated Sorted Array II
Solved
Medium
Topics
Companies
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

 

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
nums is guaranteed to be rotated at some pivot.
-104 <= target <= 104
"""


"""
Solution:
This was a slight modification over the standard search in rotated array.

This was becasue there were duplicates in this one. Hence standard check
while finding the sorted half did not work as there might be duplicates 
in the half, the ones that would be tricky would be if there are duplicates
both on the high and the low of one of the halfs
"""

class Solution:
    def isSorted(self, nums, l, h, flag=False):
        if h-l==0:
            return True
        else:
            if nums[l] <nums [h]:
                if flag:
                    return False
                return True
            elif nums[l] == nums[h]:
                return self.isSorted(nums, l, h-1, True)
            else:
                return False
        return False

    def search(self, nums: List[int], target: int) -> bool:
        l=0
        h=len(nums)-1

        while l<=h:
            m = (l+h)//2
            if nums[m]==target:
                return True
            else:
                if nums[m]>target:
                    if self.isSorted(nums, l, m): #If the left side is sorted
                        if nums[l]<=target: #If low is less or equal and full left side sorted hence def target would lie here
                            h=m-1
                        else: #otherwise target in the unsorted right half
                            l=m+1
                    else:
                        h=m-1
                else:
                    if self.isSorted(nums, m, h): #If the right side is sorted
                        if nums[h] >=target: #If side sorted and high>=target hence target def in this half
                            l=m+1
                        else: #Else target in the unsorted left half
                            h=m-1
                    else:
                        l=m+1
        return False
 