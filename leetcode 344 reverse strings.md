leetcode 344 reverse strings

编写一个函数，其作用是将输入的

反转字符串  将字符串反转过来。

**示例 1:**

```
输入: "hello"
输出: "olleh"

```

**示例 2:**

```
输入: "A man, a plan, a canal: Panama"
输出: "amanaP :lanac a ,nalp a ,nam A"
```

```
char* reverseString(char* s) {
    char* start=s;
    char* end=s+strlen(s)-1;
    char t;
    while(start<end)
    {
        t=*start;
        *start=*end;
        *end=t;
        start++;
        end--;
    }
    return s;
}
```

