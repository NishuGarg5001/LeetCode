#include <iostream>
#include <conio.h>
#include <string_view>

class Solution
{
    public:
    int lengthOfLongestSubstring(std::string_view s)
    {
        int last_seen[256];
        std::fill(last_seen, last_seen + 256, -1);
        int start = 0, result_len = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if (last_seen[s[i]] >= start)
                start = last_seen[s[i]] + 1;

            last_seen[s[i]] = i;

            int len = i - start + 1;
            if (len > result_len)
                result_len = len;
        }

        return result_len;
    }
};

int main() 
{
    std::string s1 = "abcabcbb";
    std::string s2 = "haggleeeeeeeewarfonttttt";
    std::cout<<s1<<"\n"<<Solution().lengthOfLongestSubstring(s1)<<"\n";
    std::cout<<s2<<"\n"<<Solution().lengthOfLongestSubstring(s2)<<"\n";
    getch();
    return 0;
}