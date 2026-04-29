#include <iostream>
#include <conio.h>
#include <string_view>

class Solution
{
    public:
    bool isPalindrome(std::string_view s, int l)
    {
        for(int i = 0; i < l/2; i++)
        {
            if(s[i] != s[l - 1 - i])
                return false;
        }
        return true;
    }

    std::string longestPalindrome(std::string_view s)
    {
        std::string result = "";
        std::string substring;
        int length = s.size();
        for(int i = 0; i < length; i++)
            for(int j = i; j < length; j++)
            {
                substring = s.substr(i, j - i + 1);
                int l = substring.size();
                if(isPalindrome(substring, l) && l > result.size())
                    result = substring;
            }
        return result;
    }
};

int main()
{
    std::cout<<Solution().longestPalindrome("hello")<<"\n";
    std::cout<<Solution().longestPalindrome("firefightahtenetdestroy")<<"\n";
    std::cout<<Solution().longestPalindrome("racecar-redrum-nitin");
    getch();
    return 0;
}