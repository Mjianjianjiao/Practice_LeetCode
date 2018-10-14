leetcode 80 remove-duplicates-form-sorted-array-ii

删除排序数组中的重复项

给定一个排序数组，你需要在**原地**删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在**原地修改输入数组**并在使用 O(1) 额外空间的条件下完成。

**示例 1:**

```
给定 nums = [1,1,1,2,2,3],

函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。

你不需要考虑数组中超出新长度后面的元素。
```

**示例 2:**

```
给定 nums = [0,0,1,1,1,1,2,3,3],

函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。

你不需要考虑数组中超出新长度后面的元素。
```

```
int removeDuplicates(int* nums, int numsSize) {
    
    int start=0,end=0,k=0;
    
    while(end<numsSize)
    {
        end=start;
        while(end<numsSize&&nums[start]==nums[end])//确定相同数字的长度
            end++;
        end--;
        if(end==start)
        {
            nums[k++]=nums[start];
        }else
        {
         nums[k++]=nums[start];       //每次取两个
            nums[k++]=nums[start+1];
        }
        start=end+1;
        end=start;
    }
    return k;
}
```

