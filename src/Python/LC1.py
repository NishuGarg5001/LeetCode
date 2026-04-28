class Solution: 
    def twoSum(self, nums, target):
        mp = {}
        for i in range(len(nums)):
            j = target - nums[i]
            if j in mp.keys():
                return i, mp[j]
            mp[nums[i]] = i
        return 0, 1

nums = [4, 5, 1, -1, -2, 1000000000] #1 billion is not a problem as int32 goes from -2.147 billion to 2.147 billion
target = 1000000005
solution = Solution().twoSum(nums, target)
print(solution[0], solution[1])

nums = [3, 3]
target = 6 #A number can be present multiple times at different indexes, provided the solution
#to target is still unique
solution = Solution().twoSum(nums, target)
print(solution[0], solution[1])

nums = [5, 3, 6, 7]
target = 10 #cannot select 5 (same element) twice
solution = Solution().twoSum(nums, target)
print(solution[0], solution[1])

nums = [1000000000, 10, 500000000]
target = 1500000000 #two large numbers
solution = Solution().twoSum(nums, target)
print(solution[0], solution[1])

nums = [3600, -500000000, 1000000000, -30]
target = 500000000 #large negative and positive numbers
solution = Solution().twoSum(nums, target)
print(solution[0], solution[1])