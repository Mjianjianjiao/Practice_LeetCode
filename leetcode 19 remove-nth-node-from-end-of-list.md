leetcode 19 remove-nth-node-from-end-of-list

删除链表的倒数第N个节点

给定一个链表，删除链表的倒数第 *n *个节点，并且返回链表的头结点。

**示例：**

```
给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.

```

**说明：**

给定的 *n* 保证是有效的。

**进阶：**

你能尝试使用一趟扫描实现吗？

```
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int k=0;
    struct ListNode* cur=head;
    struct ListNode* del=head;
    int len=0;
    if(!n)
        return head;
    if(head==NULL)
        return head;
    while(cur)
    {
        cur=cur->next;
        len++;
    }
    if(n>len)
        perror("error");
    if(n==len)
    {head=head->next;
     free(del);
     return head;
    }
        cur=head;
    k=n;
    while(k--)
    {
        cur=cur->next;
    }
    
    while(cur)
    {
        del=del->next;
        cur=cur->next;
    }
    
    cur=head;
    while(cur->next!=del)
    {
        cur=cur->next;
    }
    
    cur->next=del->next;
    free(del);
    return head;
}

```

```
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
 
    struct ListNode* cur=head;
    struct ListNode* del=head;
    struct ListNode* cur2=head;
     
    if(n==0)
        return head;
    if(head==NULL)
        return head;
    while(cur)
    {
        while(n)
        {
            cur=cur->next;
            n--;
        }
        if(cur==NULL)
        {
            head=head->next;
            free(del);
            return head;
        }
        cur2=del;
        del=del->next;
        cur=cur->next;
    }
    cur2->next=del->next;
    free(del);
    
    return head;
}
```

