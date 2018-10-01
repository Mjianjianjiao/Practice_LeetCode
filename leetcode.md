编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 `""`。

**示例 1:**

```
输入: ["flower","flow","flight"]
输出: "fl"

```

**示例 2:**

```
输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。

```

**说明:**

所有输入只包含小写字母 `a-z` 。

```
char* longestCommonPrefix(char** strs, int strsSize) {
     char* pub=malloc(sizeof(char)*10000);
    char* cur=NULL;
    int i=0;
    int j=0;
    cur=pub;
    for(i=0;i<10000;i++)
    {
        for(j=0;j<strsSize;j++)
        {
            //pub=realloc(pub,sizeof(char)*i);
            *cur=*(strs[0]+i);
        if(*cur!=*(strs[j]+i))
            break;
        }
        
        if(j==strsSize)
            cur++;
        else
        {
            *cur=NULL;
            break;
        }
    }
    
    if(cur==pub&&cur==NULL)
        pub[0]="";
        
    return pub;
}
```

```
char* longestCommonPrefix(char** strs, int strsSize) {
     
    int i=0;
    int j=0;
    int len=10000;
   char* pub;
    char* cur=NULL;
    for(i=0;i<strsSize;i++)
    {    cur=strs[i];
        while(*cur!='\0')
        { j++;
         cur++;
        }
        if(j<len)
        len=j;
    }
   
    pub=(char*)malloc(sizeof(char)*len);
    cur=pub;

    for(i=0;i<=len;i++)
    {
        for(j=0;j<strsSize;j++)
        {
            *cur=*(strs[0]+i);
        if(*cur!=*(strs[j]+i))
            break;
        }
        
        if(j==strsSize)
            cur++;
        else
        {
            *cur=NULL;
            break;
        }
    }
    
    if(cur==pub&&cur==NULL)
        pub[0]="";
        
    return pub;
}
```

