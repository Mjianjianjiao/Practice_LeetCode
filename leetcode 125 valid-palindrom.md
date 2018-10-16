leetcode 125 valid-palindrom

验证回文串

给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

**说明：**本题中，我们将空字符串定义为有效的回文串。

**示例 1:**

```
输入: "A man, a plan, a canal: Panama"
输出: true

```

**示例 2:**

```
输入: "race a car"
输出: false
```

```
bool isPalindrome(char* s) {
    
    if(s==NULL)
        return true;
    
   char* start=s;
    char *end=s+strlen(s)-1;
    
    while(start<end)
    {
        if(*start==*end||((*start+32==*end)&&*start>='A')||((*start==*end+32)&&(*end>='A')))
        {
           start++;
            end--;
        }else if((*start<'0'||*start>'9')&&(*start<'A'||*start>'Y')&&(*start<'a'||*start>'y'))
            start++;
        else  if((*end<'0'||*end>'9')&&(*end<'A'||*end>'Y')&&(*end<'a'||*end>'y'))
            end--;
        else 
            return false;
    }
    
    return true;
}     //isalnum()//判断是否为字母
      //tolower()//转换为小写字母
```

