leetcode 896 monotonic-array

单调数列

如果数组是单调递增或单调递减的，那么它是*单调的*。

如果对于所有 `i <= j`，`A[i] <= A[j]`，那么数组 `A` 是单调递增的。 如果对于所有 `i <= j`，`A[i]> = A[j]`，那么数组 `A` 是单调递减的。

当给定的数组 `A` 是单调数组时返回 `true`，否则返回 `false`。

```
bool isMonotonic(int* A, int ASize) {
    
   int i=0; 
    
  if(A==NULL||ASize==0)
      return false;
 //
    if(A[0]>=A[ASize-1])
        while(i<ASize-1)
        {
            if(A[i]<A[i+1])
                return false;
             i++;
        }
    
    i=0;
    
    if(A[0]<=A[ASize-1])
        while(i<ASize-1)
        {
            if(A[i]>A[i+1])
                return false;
             i++;
        }
    
    return true;
}
```

