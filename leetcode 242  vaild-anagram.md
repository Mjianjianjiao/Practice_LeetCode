leetcode 242 vaild-anagram

有效的字母异位词

给定两个字符串 *s* 和 *t* ，编写一个函数来判断 *t* 是否是 *s* 的一个字母异位词。

**示例 1:**

```
输入: s = "anagram", t = "nagaram"
输出: true

```

**示例 2:**

```
输入: s = "rat", t = "car"
输出: false
```

**说明:**
你可以假设字符串只包含小写字母。

**进阶:**
如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

```
bool isAnagram(char* s, char* t) {
    
    int *a=malloc(sizeof(int)*26);
    memset(a,0,sizeof(int)*26);
    if(strlen(s)!=strlen(t))
        return false;
    int i=0;
    char* cur=s;
    while(*cur!='\0')
    {
        a[*cur-97]++;
        cur++;
    }
    cur=t;
    while(*cur!='\0')
    {
        a[*cur-97]--;
        cur++;
    }
    
    for(i=0;i<26;i++)
        if(a[i]!=0)
            return false;
    
    return true;
}
```

