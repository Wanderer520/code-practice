//
// Created by hp on 2026/8/17.
//
#include <iostream>
#include <string>
#include <unordered_map>

int lengthOfLongestSubstring(std::string s);

int main()
{
    int result = lengthOfLongestSubstring("abcabcbb");
    std::cout << result << std::endl;
    return 0;
}

int lengthOfLongestSubstring(std::string s)
{
    int ans = 0;
    std::unordered_map<char, int> charCnt;
    for (int left = 0, right = 0; right < s.length(); right++)
    {
        charCnt[s[right]]++;
        while (charCnt[s[right]] > 1)
        {
            charCnt[s[left]]--;
            left++;
        }
        ans = std::max(ans,right-left+1);
    }
    return ans;
}
