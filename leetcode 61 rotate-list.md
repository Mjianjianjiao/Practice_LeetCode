leetcode 61 rotate-list

旋转链表

给定一个链表，旋转链表，将链表每个节点向右移动 *k *个位置，其中 *k *是非负数。

**示例 1:**

```
输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL

```

**示例 2:**

```
输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL
```

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode* tail;
    struct ListNode* cur;
        struct ListNode* tmp;
int len=0;
    cur=head;
    tail=head;
    if(head==NULL||head->next==NULL)
        return head;
    while(cur)
    {
        cur=cur->next;
        len++;
    }
    k%=len;
    cur=head;
    while(k--&&tail!=NULL)
    {
        tail=tail->next;
    }
    
    while(tail->next)
    {
        cur=cur->next;
        tail=tail->next;
    }
    while(cur->next!=NULL)
    {
        tmp=cur;
        while(tmp->next!=tail)
        {
            tmp=tmp->next;
        }
     
        tmp->next=tail->next;
        tail->next=head;
        head=tail;
        tail=tmp;
    }
    return head;
}
```

