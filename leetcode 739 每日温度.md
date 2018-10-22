leetcode 739 每日温度

根据每日 `气温` 列表，请重新生成一个列表，对应位置的输入是你需要再等待多久温度才会升高的天数。如果之后都不会升高，请输入 `0` 来代替。

例如，给定一个列表 `temperatures = [73, 74, 75, 71, 69, 72, 76, 73]`，你的输出应该是 `[1, 1, 4, 2, 1, 1, 0, 0]`。

**提示：**`气温` 列表长度的范围是 `[1, 30000]`。每个气温的值的都是 `[30, 100]` 范围内的整数。

```
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
  
    int *a=(int*)malloc(sizeof(int)*temperaturesSize);
    int i=0;
    int j=0;
    int count=0;
    while(i<temperaturesSize)
    {
        j=i;
        while(temperatures[i]>=temperatures[j])
        {
            
            j++;
            if(j==temperaturesSize)
            {
                count=0;
                break;
            }
            count++;
        }
        a[i]=count;
        i++;
        count=0;
    }
    *returnSize=temperaturesSize;
    return a;
}
```

```
出入栈操作
```

