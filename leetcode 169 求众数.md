leetcode 169 求众数

给定一个大小为 *n *的数组，找到其中的众数。众数是指在数组中出现次数**大于** `⌊ n/2 ⌋` 的元素。

你可以假设数组是非空的，并且给定的数组总是存在众数。

**示例 1:**

```
输入: [3,2,3]
输出: 3
```

**示例 2:**

```
输入: [2,2,1,1,1,2,2]
输出: 2
```

```
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.empty())
            return -1;
//         int min = nums[0], max = nums[0];   //无法处理负数
//         for(int i = 0; i < nums.size(); i++)
//         {
//             if(nums[i] > max)
//                 max = nums[i];
//             if(nums[i] < min)
//                 min = nums[i];
//         }
        
//         int len = max - min + 1;
        
//         vector<int> nums_tmp(len);
        
//         for(int i = 0; i < nums.size(); i++)
//         {
//             nums_tmp[nums[i] - min]++;
//         }
        
        
//         for(int i = 0; i < nums_tmp.size(); i++)
//             if(nums_tmp[i] > nums.size() / 2)
//                 return i + min;


/*
* 先进行排序，统计出现相同次数最多数字，记录下标 
* 时间复杂度 O(nlogn) 主要花费在排序上
*/
        
//         int count = 0;
//         sort(nums.begin(),nums.end());

        
//         int i = 0, j = 0, max_count = 0, index = 0; 
//         while(j < nums.size()-1 )
//         {
//             int count = 0;
//             while(nums[j] == nums[j+1])
//             {   
//                 j++;
//                 count++;
//             }
                   
//             if(count+1 > max_count)
//             {
//                 max_count = count+1;
//                 index = j;
//             }
            
//             j++;
//         }
        
//         return nums[index];
        
        
        
        //投票法
        
        int elem = 0;
        int cunt = 0;
        
        for(int i = 0 ; i < nums.size(); i++)
        {
            if( cunt == 0 )
            {
                elem = nums[i];
                cunt = 1;
            }else {
                
                if(elem == nums[i])
                    cunt++;
                else 
                    cunt--;
            }
        }
        
        return elem;
    }
};
```

