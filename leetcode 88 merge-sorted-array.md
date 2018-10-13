leetcode 88 merge-sorted-array

合并两个有序数组

给定两个有序整数数组 *nums1 *和 *nums2*，将 *nums2 *合并到 *nums1 *中*，*使得 *num1 *成为一个有序数组。

**说明:**

- 初始化 *nums1* 和 *nums2* 的元素数量分别为 *m* 和 *n*。
- 你可以假设 *nums1 *有足够的空间（空间大小大于或等于 *m + n*）来保存 *nums2* 中的元素。

**示例:**

```
输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]
```

```
void merge(int* nums1, int m, int* nums2, int n) {
 
    if(nums1==NULL||nums2==NULL)
        return ;
    int i=0,j=0,flag=0;
    int tmp=0;
    if(nums1[0]>nums1[m-1])
        flag=1;
    if(m==0)
        for(i=0;i<n;i++)
        {
            nums1[i]=nums2[i];
        }
    

    for(i=0;i<n;i++)
    {
        tmp=nums2[i];
        for(j=m+i;j>0;j--)
        {
            
            if(flag==1)
            {
                if(tmp>nums1[j-1])
                   {
                       nums1[j]=nums1[j-1];
                   }else {
            
                    break;
                }
            }else
            {
                 if(tmp<nums1[j-1])
                   {
                       nums1[j]=nums1[j-1];
                   }else 
                 {

                     break;
                 }
            }
        }
        nums1[j]=tmp;
    }
    
}
```

