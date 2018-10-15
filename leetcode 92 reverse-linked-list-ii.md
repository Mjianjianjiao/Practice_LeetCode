leetcode 92 reverse-linked-list-ii

反转链表ii

反转从位置 *m* 到 *n* 的链表。请使用一趟扫描完成反转。

**说明:**
1 ≤ *m* ≤ *n* ≤ 链表长度。

**示例:**

```
输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL
```

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
   struct ListNode* cur=head;
    struct ListNode* tmp;
    struct ListNode* Inhead;
    struct  ListNode* per=cur;
    struct ListNode* newhead=malloc(sizeof(struct ListNode));
    newhead->next=head;
    int t=0;
    int flag=1;
    if(m==n)
        return head;
    if(m>n)
    {
        t=m;
        m=n;    
        n=m;
    }
    m--;
    n--;
    while(n)
    {
        if(m!=0)   //找到m 的位置
        {
        per=cur;
         cur=cur->next;     
            m--;
        }else
        {
            
            if(flag)
            {
                if(cur==head)   //给定一个前插位置
            {
                Inhead=newhead;
            }else{
                Inhead=per;
            }
            flag=0;
            }
            tmp=cur->next;
            cur->next=tmp->next;
            tmp->next=Inhead->next;
            Inhead->next=tmp;
        }
      
        n--;
    }
    if(Inhead==newhead)
    head=newhead->next;

    return head;
    
}
```

