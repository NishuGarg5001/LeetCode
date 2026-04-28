#include <iostream>
#include <vector>
#include <conio.h>

class Solution
{
    public:
    double findMedianSortedArrays(const std::vector<int>& nums1, const std::vector<int>& nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        int N = m + n;
        std::vector<int> z;
        z.reserve(N);
        int i = 0, j = 0;
        double result;

        while(i < m && j < n)
        {
            if(nums1[i] <= nums2[j])
                z.push_back(nums1[i++]);
            else
                z.push_back(nums2[j++]);
        }
        while(i < m)
            z.push_back(nums1[i++]);
        while(j < n)
            z.push_back(nums2[j++]);
        int median_pos = (N + 1)/2 - 1;
        if(N % 2 != 0)
            result = z[median_pos];
        else
            result = (z[median_pos] + z[median_pos + 1]) / 2.0;
        return result;
    }
};

int main()
{
    std::vector<int> x = {1, 2, 2, 3, 4, 7, 10};
    std::vector<int> y = {3, 4, 5, 6};
    std::vector<int> z = {1, 2, 2, 3, 4, 7};
    std::cout<<Solution().findMedianSortedArrays(x, y)<<"\n";
    std::cout<<Solution().findMedianSortedArrays(z, y);
    getch();
    return 0;
}