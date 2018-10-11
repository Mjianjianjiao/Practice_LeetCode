leetcode 58 length-of-last-word

最后一个单词的长度

给定一个仅包含大小写字母和空格 `' '` 的字符串，返回其最后一个单词的长度。

如果不存在最后一个单词，请返回 0 。

**说明：**一个单词是指由字母组成，但不包含任何空格的字符串。

**示例:**

```
输入: "Hello World"
输出: 5
```

```
int lengthOfLastWord(char* s) {
   char* cur;
    char* start;
    int count=0;
    cur=s;
    start=cur;
    if(s==NULL||strlen(s)==0)
        return 0;
    
    while(*cur!='\0')
    {
        if(*cur!=' ')
        start=cur;
        while(*cur!=' ')
        { cur++;
         if(*cur=='\0')
             return strlen(start);
        }
        cur++;
        
    }
    while(*start!=' ')
    { count++;
     start++;
    }
    return count;
}
```

```
int lengthOfLastWord(char* s) {
  int i=0;
    int j=0;
    int len=strlen(s);

    if(s==NULL||len==0)
     return 0;
    
for(i=len-1;s[i]==' '&&i>=0;i--);
    
 
for(j=i;s[j]!=' '&&j>=0;j--);
  
    return i-j;
    
}
```

