leetcode 268 缺失的数字

给定一个包含 `0, 1, 2, ..., n` 中 *n* 个数的序列，找出 0 .. *n* 中没有出现在序列中的那个数。

**示例 1:**

```
输入: [3,0,1]
输出: 2

```

**示例 2:**

```
输入: [9,6,4,2,3,5,7,0,1]
输出: 8

```

**说明:**
你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?

```
int missingNumber(int* nums, int numsSize) {
//     int* a=malloc(sizeof(int)*numsSize);
//     int i=0;
//     memset(a,0,sizeof(int)*numsSize);
//     for(i=0;i<numsSize;i++)
//     {
//         a[nums[i]]++;
//     }

//      for(i=0;i<numsSize;i++)
//     {
//         if(a[i]==0)
//             break;
//     }
    
//     return i;
    
 
    
    
    int i=0;
    int sum=0;
    for(i=0;i<=numsSize;i++)
    {
        sum+=i;
    }
    for(i=0;i<numsSize;i++)
    {
        sum-=nums[i];
    }
    return sum;
}
```

