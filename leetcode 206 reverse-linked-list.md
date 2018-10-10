leetcode 206 reverse-linked-list

反转一个单链表。

示例:**

```
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
```

**进阶:**
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

```
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* n1;
    struct ListNode* n2;
    struct ListNode* n3;
 
    if(head==NULL||head->next==NULL)
        return head;
    
    n1=head;
    n2=n1->next;
    n3=n2->next;
    
    while(n2)
    {
        n2->next=n1;
        n1=n2;
        n2=n3;
        if(n3)
        n3=n3->next;        
    }
        head->next=NULL;
    return n1;

}
```

