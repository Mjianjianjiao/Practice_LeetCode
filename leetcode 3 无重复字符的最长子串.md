leetcode 3 无重复字符的最长子串

给定一个字符串，请你找出其中不含有重复字符的 **最长子串 **的长度。

**示例 1:**

```
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

```

**示例 2:**

```
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

```

**示例 3:**

```
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
```

```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     
        if(s.empty())
            return 0;
        
        if(s.size() == 1)  //当只有一个元素时直接返回1
            return 1;
        int max = 0 , i = 0 , j = 0;
        for( i = 0;i < s.size()-1; i++)
        {
                vector<int> nums(256,0);  //为每个字串建立映射
                nums[s[i]]++;
            for( j= i + 1; j < s.size(); j++)
            {
                nums[s[j]]++;
                if(nums[s[i]] > 1||nums[s[j]] > 1)  //如果当前子串有重复，在串中间，且长度大于之前的最长字串，替换max
                {
                    if(j-i > max) //去除最后已经重复的，不用+1
                        max = j - i;
                    break;
                }
                
            }
            
            if(j == s.size() && j - i >= max)   //如果字串一直到结尾都没有重复，替换max
                max = j - i;
        }
        
        return max;
    }
};
```

