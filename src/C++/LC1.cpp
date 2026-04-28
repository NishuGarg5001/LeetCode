#include <iostream>
#include <vector>
#include <unordered_map>

class Solution 
{
    public:
        std::vector<int> twoSum(const std::vector<int>& nums, int target) const
        {
            std::unordered_map<int, int> mp;
            for(int i = 0; i < static_cast<int>(nums.size()); i++)
            {
                auto j = mp.find(target - nums[i]);
                if(j != mp.end())
                    return {i, j->second};
                mp[nums[i]] = i;
            }
            return {0, 1};
        }
};

int main()
{
    std::vector<int> nums;
    int target;
    std::vector<int> solution;

    nums = {4, 5, 1, -1, -2, 1000000000}; //1 billion is not a problem as int32 goes from -2.147 billion to 2.147 billion
    target = 1000000005;
    solution = Solution().twoSum(nums, target);
    std::cout<<solution[0]<<' '<<solution[1]<<'\n';

    nums = {3, 3};
    target = 6; //A number can be present multiple times at different indexes, provided the solution
    //to target is still unique
    solution = Solution().twoSum(nums, target);
    std::cout<<solution[0]<<' '<<solution[1]<<'\n';

    nums = {5, 3, 6, 7};
    target = 10; //cannot select 5 (same element) twice
    solution = Solution().twoSum(nums, target);
    std::cout<<solution[0]<<' '<<solution[1]<<'\n';

    nums = {1000000000, 10, 500000000};
    target = 1500000000; //two large numbers
    solution = Solution().twoSum(nums, target);
    std::cout<<solution[0]<<' '<<solution[1]<<'\n';

    nums = {3600, -500000000, 1000000000, -30};
    target = 500000000; //large negative and positive numbers
    solution = Solution().twoSum(nums, target);
    std::cout<<solution[0]<<' '<<solution[1]<<'\n';

    return 0;
}