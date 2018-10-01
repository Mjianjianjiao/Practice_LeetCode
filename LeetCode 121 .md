LeetCode 121 买股票的最佳时机

```
int maxProfit(int* prices, int pricesSize) {
    
    assert(prices);
    int max=0;
    int min=0;
    int i=0;
    int j=0;
    int tmp=0;
    for(i=0;i<pricesSize-1;i++)
        for(j=i+1;j<pricesSize;j++)
        {
            
            if((prices[j]-prices[i])>tmp)
            {
                tmp=prices[j]-prices[i];
                max=j;
                min=i;
            }
        }
    if(tmp>0)
    return prices[max]-prices[min];
    
    return 0;
}
```

