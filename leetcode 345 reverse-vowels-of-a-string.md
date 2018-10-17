leetcode 345 reverse-vowels-of-a-string

反转字符串中的元音字母

编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

**示例 1:**

```
输入: "hello"
输出: "holle"

```

**示例 2:**

```
输入: "leetcode"
输出: "leotcede"
```

**说明:**
元音字母不包含字母"y"。

```
int isvowel(char* c)
{
    if(*c=='a'||*c=='e'||*c=='i'||*c=='o'||*c=='u'|| *c=='A'||*c=='E'||*c=='I'||*c=='O'||*c=='U')
        return 1;
     
    return 0;
}

char* reverseVowels(char* s) {
    
    if(s==NULL)
        return NULL;
    char* left=s;
    char* right=s+strlen(s)-1;;
    char tmp;
    while(left<right)
    {
        if(isvowel(left)==0)
            left++;
        if(isvowel(right)==0)
            right--;
        if(isvowel(left)==1&&isvowel(right)==1)
        {
            tmp=*left;
            *left=*right;
            *right=tmp;
            left++;
            right--;
        }
    }
    
    return s;
}
```

