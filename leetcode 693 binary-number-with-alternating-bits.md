leetcode 693 binary-number-with-alternating-bits

交替位二进制数

给定一个正整数，检查他是否为交替位二进制数：换句话说，就是他的二进制数相邻的两个位数永不相等。

**示例 1:**

```
输入: 5
输出: True
解释:
5的二进制数是: 101

```

**示例 2:**

```
输入: 7
输出: False
解释:
7的二进制数是: 111

```

**示例 3:**

```
输入: 11
输出: False
解释:
11的二进制数是: 1011

```

** 示例 4:**

```
输入: 10
输出: True
解释:
10的二进制数是: 1010

```

```
bool hasAlternatingBits(int n) {
    int count=0;    
    int i=0;
    int tmp=n;
    int flag=0;
    int n1=0;
    int n2=0;
    for(i=0;i<32;i++)
    {
      if(tmp>>i&1==1)
          count++;
    }
    flag=tmp&1;
    i=0;
    while(count--)
    {
       n1=tmp>>i&1;
       n2=tmp>>(i+1)&1;
        if(n1==n2|flag!=n1)
           return false;
         flag=n1;
        i+=2;
    }
    return true;
}
```

