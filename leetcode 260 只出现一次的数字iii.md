leetcode 260 只出现一次的数字iii

给定一个整数数组 `nums`，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。

**示例 :**

```
输入: [1,2,1,3,2,5]
输出: [3,5]
```

**注意：**

1. 结果输出的顺序并不重要，对于上面的例子， `[5, 3]` 也是正确答案。
2. 你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？

```
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        if(nums.empty())
            return vector<int> ();
/*
*对于该题，将两个不同数分开，再进行异或
   1. 将所有的数全部异或
*  2. 找出其中为1的位的位置，（表示两数在此位并不相同）
*  3. 将所有数字按01分为两拨，并相异或 
*/  
        
     //全部异或
        int value=0;
        for(int i=0;i<nums.size();i++)
        {
            value^=nums[i];
        }
        
      //找出不同位
        int index=0;
        for(int j=0;j<32;j++)
        {
            if(value>>j&1==1)
            {
                index=j;
                break;
            }
        }
        
        //将所有的数分为两边并异或
        vector<int> key(2,0);
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>>index&1==1)
                key[0]^=nums[i];
            else
                key[1]^=nums[i];
        }


        
        return key;
                       
        
    }
};
```

