 leetcode 287 寻找重复的数

给定一个包含 *n* + 1 个整数的数组 *nums*，其数字都在 1 到 *n *之间（包括 1 和 *n*），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。

**示例 1:**

```
输入: [1,3,4,2,2]
输出: 2

```

**示例 2:**

```
输入: [3,1,3,4,2]
输出: 3

```

**说明：**

1. **不能**更改原数组（假设数组是只读的）。
2. 只能使用额外的 *O*(1) 的空间。
3. 时间复杂度小于 *O*(*n*2) 。
4. 数组中只有一个重复的数字，但它可能不止重复出现一次。



如果没有时间和空间的要求限制，这个题很容易我们可以通过

1. **暴力法**

使用双重循环，用两个指针进行比较（时间复杂度高）

2.  **计数**

开辟一个n个数的数组，将原数组中的n个数映射到相应位上计数，如果有一位超过1，返回其下标（开辟o（n）个空间）

3. **排序**

   先排序，再遍历一次，大部分排序的时间复杂度都高，

   满足要求的可以使用快排

所以因为时间和空间的限制，采用二分法 

二分法

```
int findDuplicate(int* nums, int numsSize) {
    if(nums==NULL)
        return ;
    //二分法
    int count=0;
    int i=0;
    int left=0;
    int right=numsSize-1;
    int mid=(left+right)/2;
    while(left<right)
{
        count=0;
        mid=left+(right-left)/2;
    for(i=0;i<numsSize;i++)//统计是否有数超出范围
    {
        if(nums[i]<=mid)
            count++;
    }
     if(count>mid)
     {
         right=mid;
     }else  
        {
            left=mid+1;
        }     
  }
    return left;
}
```

```
//取环法
int findDuplicate(int* nums, int numsSize) {
    int slow=nums[0],fast=nums[nums[0]];
    while(slow!=fast){
        slow=nums[slow];
        fast=nums[nums[fast]];
    }
    fast=0;
    while(slow!=fast){
        slow=nums[slow];
        fast=nums[fast];
    }
    return slow;
}
```

