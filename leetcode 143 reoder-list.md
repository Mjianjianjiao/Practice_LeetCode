leetcode 143 reoder-list

重排链表

给定一个单链表 *L*：*L*0→*L*1→…→*L**n*-1→*L*n ，
将其重新排列后变为： *L*0→*L**n*→*L*1→*L**n*-1→*L*2→*L**n*-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

**示例 1:**

```
给定链表 1->2->3->4, 重新排列为 1->4->2->3.
```

**示例 2:**

```
给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
```

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    
    struct ListNode* start=head;
    struct ListNode* end=NULL;
    struct ListNode* tmp=head;
    struct ListNode* tail=head;
    
    if(head==NULL||head->next==NULL)
        return;
    
    while(start)
    {
       while(tail->next)
       {
           tmp=tail;
           tail=tail->next;
       }
        
        end=tmp->next;
        if(start==end)
            break;
        tmp->next=end->next;
        
        end->next=start->next;
        start->next=end;
        
        start=end->next;
    }
    
    return head;
}  //可分为两段 反转后拼接
```

