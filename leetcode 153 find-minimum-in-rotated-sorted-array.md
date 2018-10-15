leetcode 153 find-minimum-in-rotated-sorted-array

寻找旋转排序数组的最小值

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 `[0,1,2,4,5,6,7]` ****可能变为 `[4,5,6,7,0,1,2]` )。

请找出其中最小的元素。

你可以假设数组中不存在重复元素。

**示例 1:**

```
输入: [3,4,5,1,2]
输出: 1
```

**示例 2:**

```
输入: [4,5,6,7,0,1,2]
输出: 0
```

```
int findMin(int* nums, int numsSize) {
   
    if(numsSize==0||nums==NULL)
        return NULL;
    
    if(nums[0]<=nums[numsSize-1])
        return nums[0];
    
    int i=0;
    for(i=0;i<numsSize-1;i++)
    {
        if(nums[i]>nums[i+1])
            return nums[i+1];
    }
    
    return nums[0];
}
```

```
int findMin(int* nums, int numsSize) {
    int left=0, right=numsSize-1, mid;
    while(left < right){
        //printf("%d %d\n", left, right);
        mid = left + (right - left) / 2;
        if(nums[mid]<nums[right])
            right = mid;
        else
            left = mid + 1;
    }
    return nums[left];
}
```

