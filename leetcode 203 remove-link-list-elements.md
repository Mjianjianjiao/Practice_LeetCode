leetcode 203 remove-link-list-elements

移除链表元素

删除链表中等于给定值 **val **的所有节点。

**示例:**

```
输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
```

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    
    struct ListNode* cur;
    struct ListNode* tmp;
    
    cur=head;
    tmp=cur;
    
    while(cur)
    {
        if(cur->val==val)
        {
            if(cur==head)
            {
                head=head->next;
            }
            
            tmp->next=cur->next;
             free(cur);
        }
        else
        {
            tmp=cur;
        }
             cur=cur->next;
       
    }
    
    return head;
    
}
```

