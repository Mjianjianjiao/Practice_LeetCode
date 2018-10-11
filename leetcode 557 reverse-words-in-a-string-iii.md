leetcode 557 reverse-words-in-a-string-iii

反转字符串中的单词

给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

**示例 1:**

```
输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc" 

```

**注意：**在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。

```
void reverse(char* start,char* end)
{
    assert(start&&end);
    char tmp;
    while(start<end)
    {
        tmp=*start;
        *start=*end;
        *end=tmp;
        start++;
    end--;
    }
    
}
char* reverseWords(char* s) {
    
    char* cur;
    char* start;
    char* end;
    cur=s;
    while(*cur!='\0')
    {
        
        start=cur;
        if(*start==' ')
           start++;
       while(*(cur+1)!=' '&&*(cur+1)!='\0')
            cur++;
        end=cur;
        reverse(start,end);
        cur++;
    }
    
    return s;
}
```

