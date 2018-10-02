给定一个 32 位有符号整数，将整数中的数字进行反转。

**示例 1:**

```
输入: 123
输出: 321

```

** 示例 2:**

```
输入: -123
输出: -321

```

**示例 3:**

```
输入: 120
输出: 21

```

**注意:**

假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。根据这个假设，如果反转后的整数溢出，则返回 0。

```
int reverse(int x) {

    int sum=0;
    int tmp=x;
    int n=0;
    while(tmp)
    {
        n=tmp%10;
        tmp/=10;
        if(sum>INT_MAX/10||(sum==INT_MAX&&n>7))
            return 0;
        if(sum<INT_MIN/10||(sum==INT_MIN&&n<-8))
            return 0;
        sum=sum*10+n;
    }
    return sum; 
}
```

