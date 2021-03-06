leetcode 64 最小路径和

给定一个包含非负整数的 *m* x *n* 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

**说明：**每次只能向下或者向右移动一步。

**示例:**

```
输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。
```

```
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        /*
        动态规划求解：
        状态： 从F(0,0)到F(i,j)的最小路径和
        递推关系：
        F(i,j)=min{F(i-1,j),F(i,j-1)}+F(i,j);
        左边界：
        F(i,j)=F(i-1,j)+F(i,j);
        上边界：
        F(i,j)=F(i,j-1)+F(i,j);
        
        初始化：
          F(0,0)=F(0,0);
          
          返回值：
          F(m-1,n-1)
        */
        
        if(grid.empty())  //参数检查
            return -1;
        
        vector<vector<int>> min_sum(grid);  //拷贝开辟保存路径和的数组
        
        //初始化
        min_sum[0][0]=grid[0][0];
        int m=min_sum.size();
        int n=min_sum[0].size();
        //递推关系
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(i==0&&j==0)
                continue;
                else if(i==0)
                {//上边界
                   min_sum[i][j]+=min_sum[i][j-1];
                }else if(j==0)
                {//左边界
                    min_sum[i][j]+=min_sum[i-1][j];
                }else{
                    min_sum[i][j]=min(min_sum[i][j-1],min_sum[i-1][j])+min_sum[i][j];
                }
            }
        //返回值
        
        return min_sum[m-1][n-1];
        
        
    }
};
```

