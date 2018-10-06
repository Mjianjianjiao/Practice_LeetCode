leetcode  434 number-of-segments-in-a-string

字符串中的单词数

统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。

请注意，你可以假定字符串里不包括任何不可打印的字符。

**示例:**

```
输入: "Hello, my name is John"
输出: 5
```

```
int countSegments(char* s) {
    char* start=s;
    char* end=s;
    int count=0;
    while(*start!='\0')
    {
        if(*start!=' ')
        {
            end=start;
            while(*end!=' '&&*end!='\0')
            {
                end++;
            }
            count++;
            start=end;
        }
            else 
            start++;
    }
    
    return count;
}
```

