leetcode 2 add-two-numbers

两数相加

给定两个**非空**链表来表示两个非负整数。位数按照**逆序**方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

**示例：**

```
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
```

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  
    struct ListNode* cur1=l1;
    struct ListNode* cur2=l2;
    struct ListNode* head,*tail;
    
    if(l1==NULL)
        return l2;
    if(l2==NULL)
        return l1;
    if(l1==NULL&&l2==NULL)
        return NULL;
    
    
    head=malloc(sizeof(struct ListNode));
    tail=head;
    int flag = 0;
    while(cur1 && cur2)
    {
        tail->next=malloc(sizeof(struct ListNode));
            tail=tail->next;
            tail->next=NULL;
        if(flag==1)
            cur1->val+=1;
        if(cur1->val+cur2->val>=10)
        {
            
            tail->val=cur1->val+cur2->val-10;
            flag=1;
            
        }else
        {
            tail->val=cur1->val+cur2->val;
            flag=0;
        }
        
        cur1=cur1->next;
        cur2=cur2->next;
    }
    
    if(cur1)//l1不空，l2空
    {
        
        while(cur1)
        {
            tail->next=malloc(sizeof(struct ListNode));
            tail=tail->next;
            tail->next=NULL;
            if(flag==1)
            cur1->val+=1;
            if(cur1->val>=10)
            {
                flag=1;
                cur1->val-=10;
            }
            else flag=0;
            tail->val=cur1->val;
            cur1=cur1->next;
        } 
    }
    
   
    
      if(cur2)//l1不空，l2空
    {
        
        while(cur2)
        {
            tail->next=malloc(sizeof(struct ListNode));
            tail=tail->next;
            tail->next=NULL;
            if(flag==1)
            cur2->val+=1;
            if(cur2->val>=10)
            {
                flag=1;
                cur2->val-=10;
            }
            else flag=0;
            tail->val=cur2->val;
            cur2=cur2->next;
        } 
    }
    
     if(flag==1)
    {
        tail->next=malloc(sizeof(struct ListNode));
            tail=tail->next;
        tail->val=1;
        tail->next=NULL;
    }
    
    
    return head->next;
    
}
```

