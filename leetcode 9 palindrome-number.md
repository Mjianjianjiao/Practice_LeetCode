leetcode 9 palindrome-number

回文数

判读一个整数是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

**示例 1:**

```
输入: 121
输出: true

```

**示例 2:**

```
输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

```

**示例 3:**

```
输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。

```

```
bool isPalindrome(int x) {
  
    if(x<0)
       return false;
     int count=0;
    int i=0;
    int tmp=x;
    while(tmp)
    {
        tmp/=10;
        count++;
    }
    count--;
    while(i<=(count>>1))
    {
       if((x/(int)pow(10,count-i))%10==((x/(int)pow(10,i))%10)) 
          i++;
          else
              return false;
    }
           return true;
}
```

