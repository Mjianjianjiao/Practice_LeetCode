leetcode 451 sort-characters-by-frequency

根据字符出现频率排序

给定一个字符串，请将字符串里的字符按照出现的频率降序排列。

**示例 1:**

```
输入:
"tree"

输出:
"eert"

解释:
'e'出现两次，'r'和't'都只出现一次。
因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。

```

**示例 2:**

```
输入:
"cccaaa"

输出:
"cccaaa"

解释:
'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
注意"cacaca"是不正确的，因为相同的字母必须放在一起。

```

**示例 3:**

```
输入:
"Aabb"

输出:
"bbAa"

解释:
此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
注意'A'和'a'被认为是两种不同的字符。
```

```
char* frequencySort(char* s) {
    
    int *a=malloc(sizeof(int)*256);  //给256个字符都开辟一位
    int i=0;
    int index=0;
    int len=strlen(s);
    int max=0;
    memset(a,0,sizeof(int)*256);
    char* s2=malloc(sizeof(char)*len+1);  //开辟空间存放排序后字符
  
    if(s==NULL)
        return NULL;
    
    //将字符映射进数组
    for(i=0;i<len;i++)
        a[s[i]]++;
    
    while(index<len)
{  
    for(i=0;i<256;i++)   //找出次数最多
        if(a[i]>a[max])
            max=i;
    
    while(a[max])       //放入新数组
     {
         s2[index++]=max;
         a[max]--;
     }
         
}    
    s2[index]='\0';
    
    return s2;
}
```

