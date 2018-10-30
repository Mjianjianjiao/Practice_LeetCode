leetcode 746 使用最小花费爬楼梯

数组的每个索引做为一个阶梯，第 `i`个阶梯对应着一个非负数的体力花费值 `cost[i]`(索引从0开始)。

每当你爬上一个阶梯你都要花费对应的体力花费值，然后你可以选择继续爬一个阶梯或者爬两个阶梯。

您需要找到达到楼层顶部的最低花费。在开始时，你可以选择从索引为 0 或 1 的元素作为初始阶梯。

**示例 1:**

```
输入: cost = [10, 15, 20]
输出: 15
解释: 最低花费是从cost[1]开始，然后走两步即可到阶梯顶，一共花费15。

```

** 示例 2:**

```
输入: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
输出: 6
解释: 最低花费方式是从cost[0]开始，逐个经过那些1，跳过cost[3]，一共花费6。

```

**注意：**

1. `cost` 的长度将会在 `[2, 1000]`。
2. 每一个 `cost[i]` 将会是一个Integer类型，范围为 `[0, 999]`。

```
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        /*
        状态:到达第i阶楼梯F(i)的最小值
        递推关系：F(i)=min{F(i-1)，F(i-2)}+F(i)
        初始化： F(0)=cost[0]
                 F(1)=cost[1]
        返回值：
            min{F(n-1),F(n-2)}
        */
        if(cost.empty())
            return 0;
        vector<int> min_sum(cost);  //存储容器
          min_sum[0]=cost[0];  //初始化
          min_sum[1]=cost[1];
        int n=cost.size();
        //递推关系
        for(int i=2;i<n;i++)
        {
            min_sum[i]=min(min_sum[i-2],min_sum[i-1])+min_sum[i];
        }
        //返回值
        return min(min_sum[n-1],min_sum[n-2]);
    }
};
```

