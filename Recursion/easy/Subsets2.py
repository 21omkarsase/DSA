# 90. Subsets II
# Solved
# Medium
# Topics
# Companies

# Given an integer array nums that may contain duplicates, return all possible
# subsets
# (the power set).

# The solution set must not contain duplicate subsets. Return the solution in any order.

 

# Example 1:

# Input: nums = [1,2,2]
# Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

# Example 2:

# Input: nums = [0]
# Output: [[],[0]]

 

# Constraints:

#     1 <= nums.length <= 10
#     -10 <= nums[i] <= 10

# Seen this question in a real interview before?
# 1/5
# Yes
# No
# Accepted
# 937.6K
# Submissions
# 1.6M
# Acceptance Rate
# 57.5%
# Topics
# Array
# Backtracking
# Bit Manipulation
# Companies
# Similar Questions
# Subsets
# Medium
# Find Array Given Subset Sums
# Hard
# Discussion (69)

class Solution:
    def generate_subsets(self, idx, n, nums, subset, all_subsets):
        if idx == n:
            all_subsets.append(subset.copy())
            return

        subset.append(nums[idx])
        self.generate_subsets(idx + 1, n, nums, subset, all_subsets)
        subset.pop()

        while idx + 1 < len(nums) and nums[idx] == nums[idx + 1]:
            idx += 1
        
        self.generate_subsets(idx + 1, n, nums, subset, all_subsets)

    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        all_subsets = []
        nums.sort()
        self.generate_subsets(0, len(nums), nums, [], all_subsets)
        
        return all_subsets