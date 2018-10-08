leetcode 83 remove-duplicates-from-sorted-list

删除排序链表中的重复元素

给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

**示例 1:**

```
输入: 1->1->2
输出: 1->2

```

**示例 2:**

```
输入: 1->1->2->3->3
输出: 1->2->3
```

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    
    struct ListNode* cur=head;
    struct ListNode* tmp=head;
    
    if(head==NULL||head->next==NULL)
        return head;
    tmp=cur->next;
    while(tmp!=NULL)
    {
        if(cur->val==tmp->val&&tmp!=NULL)
        {
         cur->next=tmp->next;
            free(tmp);
            tmp=cur->next;
        }
        else
        {
            cur=cur->next;
            if(tmp==NULL)
                break;
            tmp=tmp->next;
        }
    }
    return head;
}
```

