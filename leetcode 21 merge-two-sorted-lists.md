leetcode 21 merge-two-sorted-lists

 合并两个有序链表

将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

**示例：**

```
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

```

```
struct ListNode* BuyNode(int val)
{
    struct ListNode* node=malloc(sizeof(struct ListNode));
    node->val=val;
    node->next=NULL;
    return node;
}
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    
    
    struct ListNode*  cur1=l1;
    struct ListNode*  cur2=l2;
    struct ListNode*  cur3;
    struct ListNode* list=NULL;
    cur3=list;
    while(cur1!=NULL&&cur2!=NULL)
    {
        if(cur1->val<cur2->val)
        {
            if(list==NULL)
            {            list=BuyNode(cur1->val);
                cur3=list;
            }
                else
            {
                cur3->next=BuyNode(cur1->val);
                cur3=cur3->next;
            }
            cur1=cur1->next;
        }
        else
        {
             if(list==NULL)
             {list=BuyNode(cur2->val);
            cur3=list;
             }else
            {
                cur3->next=BuyNode(cur2->val);
                cur3=cur3->next;
            }
            cur2=cur2->next;
        }
    }
    
    if(cur1)
    while(cur1)
    {
        if(list==NULL)
        {list=BuyNode(cur1->val);
        cur3=list;
        }else
        {
            cur3->next=BuyNode(cur1->val);
            cur3=cur3->next;
        }
                    cur1=cur1->next;

    }
     if(cur2)
    while(cur2)
    {
        if(list==NULL)
        {list=BuyNode(cur2->val);
        cur3=list;
        }else
        {
            cur3->next=BuyNode(cur2->val);
            cur3=cur3->next;
        }
                    cur2=cur2->next;

    }
    return list;
}
```

