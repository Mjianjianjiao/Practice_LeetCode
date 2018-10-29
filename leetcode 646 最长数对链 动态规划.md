leetcode 646 最长数对链  动态规划

给出 `n` 个数对。 在每一个数对中，第一个数字总是比第二个数字小。

现在，我们定义一种跟随关系，当且仅当 `b < c` 时，数对`(c, d)` 才可以跟在 `(a, b)` 后面。我们用这种形式来构造一个数对链。

给定一个对数集合，找出能够形成的最长数对链的长度。你不需要用到所有的数对，你可以以任何顺序选择其中的一些数对来构造。

**示例 :**

```
输入: [[1,2], [2,3], [3,4]]
输出: 2
解释: 最长的数对链是 [1,2] -> [3,4]

```

**注意：**

1. 给出数对的个数在 [1, 1000] 范围内。

```
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        /*
        
        状态：第i位之前最长链对数
        递推关系：
        
         
         (F(i-1).num[1]<F(i).num[0])==true  -->F(i)=max{F(j)}+F(i);
                                                    
          F=max{F(j)}
          初始化：
           F(i)=1;
        */
        int n=pairs.size();
        vector<vector<int>>  sort_pairs(pairs);
        for(int i=0;i < n-1;i++ )
            for(int j=0;j<n-1-i;j++)
            {
                if(sort_pairs[j][0]>sort_pairs[j+1][0])
                {
                    int tmp1=sort_pairs[j][0];
                    int tmp2=sort_pairs[j][1];
                    sort_pairs[j][0]=sort_pairs[j+1][0];
                    sort_pairs[j][1]=sort_pairs[j+1][1];
                    sort_pairs[j+1][0]=tmp1;
                    sort_pairs[j+1][1]=tmp2;
                }
            }
        vector<int> max_sum(n);
        max_sum[0]=1;
        for(int i=0;i<n;i++)
            max_sum[i]=1;
        
        int tmp=0;
        for(int i=1;i<pairs.size();i++)
        {    for(int j=0;j<i;j++)
            {
                if(sort_pairs[i][0]>sort_pairs[j][1])
                 tmp=max(max_sum[j],tmp);
               
            }
          max_sum[i]=tmp+max_sum[i];
        }
        for(int i=0;i<n;i++)
           max_sum[0]=max(max_sum[0],max_sum[i]);
        
        return max_sum[0];
    }
};
```

