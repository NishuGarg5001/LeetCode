#include <iostream>
#include <vector>
#include <conio.h>

class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        m = len(nums1)
        n = len(nums2)
        N = m + n
        z = []
        i = j = 0

        while i < m and j < n:
            if nums1[i] <= nums2[j]:
                z.append(nums1[i])
                i += 1
            else:
                z.append(nums2[j])
                j += 1
        while i < m:
            z.append(nums1[i])
            i += 1
        while j < n:
            z.append(nums2[j])
            j += 1
        median_pos = (N + 1)//2 - 1
        if N % 2 != 0:
            result = z[median_pos]
        else:
            result = (z[median_pos] + z[median_pos + 1]) / 2.0
        return result

x = [1, 2, 2, 3, 4, 7, 10]
y = [3, 4, 5, 6]
z = [1, 2, 2, 3, 4, 7]
print(Solution().findMedianSortedArrays(x, y))
print(Solution().findMedianSortedArrays(z, y))