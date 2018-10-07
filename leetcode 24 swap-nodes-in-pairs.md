leetcode 24 swap-nodes-in-pairs

两两交换链表中的节点

给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

**示例:**

```
给定 1->2->3->4, 你应该返回 2->1->4->3.
```

**说明:**

- 你的算法只能使用常数的额外空间。
- **你不能只是单纯的改变节点内部的值**，而是需要实际的进行节点交换。

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* cur1;
    struct ListNode* cur2;
    struct ListNode* tmp;
    if(head==NULL||head->next==NULL)
        return head;
    
    cur1=head;
    cur2=cur1->next;
    tmp=cur1; 
    while(cur2)
     {   
        if(tmp==head)
            head=cur2;
        else
            tmp->next=cur2;
        cur1->next=cur2->next;
        cur2->next=cur1;
        if(cur1==NULL||cur1->next==NULL)
            return head;
        tmp=cur1;
        cur1=cur1->next;
        cur2=cur1->next;
    }
    
    return head;
}
```

