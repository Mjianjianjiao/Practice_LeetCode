leetcode 86 partition-list

分隔链表

给定一个链表和一个特定值* x*，对链表进行分隔，使得所有小于 *x* 的节点都在大于或等于 *x* 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

**示例:**

```
输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5
```

```
struct ListNode* partition(struct ListNode* head, int x) {
 
    struct ListNode* cur=head;
    struct ListNode* pos=NULL;
    struct ListNode* head2=NULL;
    struct ListNode* tail=head2;
    struct ListNode* cur2;
    
    
    head2=malloc(sizeof(struct ListNode));

    if(head==NULL||head->next==NULL)
        return head;
    cur=head;
    while(cur!=NULL)
    { 
        if(cur->val>=x)
        {
            pos=cur;
            break;
        }    
        cur=cur->next;
    }            //找到第一个大于等于目标值的位置
    if(pos==NULL)  //如果没有返回链表头节点
        return head;
    cur=head;
    cur2=cur;
    tail=head2;
    while(cur)   //将小于目标值的节点都摘下来放在一起
    {
        if(cur->val<x)
        {
            
            
            
                tail->next=cur;
                tail=tail->next;
                 if(cur==head)
                 {
                     head=head->next;
                     cur2=cur2->next;
                 }
                else cur2->next=cur->next;
            
                cur=cur->next;
            
        }
        else
        {
            cur2=cur;
            cur=cur->next;
        }
    }
    
    tail->next=pos;

    head2=head2->next;
    
    return head2;
}
```

