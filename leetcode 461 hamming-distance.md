leetcode 461 hamming-distance

汉明距离

两个整数之间的[汉明距离](https://baike.baidu.com/item/%E6%B1%89%E6%98%8E%E8%B7%9D%E7%A6%BB)指的是这两个数字对应二进制位不同的位置的数目。

给出两个整数 `x` 和 `y`，计算它们之间的汉明距离。

**注意：**
0 ≤ `x`, `y` < 231.

**示例:**

```
输入: x = 1, y = 4

输出: 2

解释:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

上面的箭头指出了对应二进制位不同的位置。
```

```
int hammingDistance(int x, int y) {
    int length=0,tmp=0,i=0;
  
    tmp=x^y;
    for(i=0;i<32;i++)
        if(tmp>>i&1==1)
            length++;
    
    return length;
}
```

