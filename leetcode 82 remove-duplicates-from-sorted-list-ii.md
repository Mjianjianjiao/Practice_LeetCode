leetcode 82 remove-duplicates-from-sorted-list-ii

删除排序链表中的重复元素

给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 *没有重复出现 *的数字。

示例 1:**

```
输入: 1->2->3->3->4->4->5
输出: 1->2->5

```

**示例 2:**

```
输入: 1->1->1->2->3
输出: 2->3
```

```
struct ListNode* deleteDuplicates(struct ListNode* head) {
 
    struct ListNode* cur;
    struct ListNode* tmp;
    struct ListNode* del;
    struct ListNode* del2;
    if(head==NULL||head->next==NULL)
        return head;
    cur=head;
    tmp=cur->next;
    del=cur;
   while(tmp!=NULL)
   {
       
       while(tmp!=NULL&&del->val==tmp->val)
           tmp=tmp->next;
      
       
       if(del->next==tmp)
       {
           cur=del;
           del=tmp;
           if(tmp==NULL)
              break;
           tmp=tmp->next;
           
       }else{
           
        while(del!=tmp)
       {
           del2=del;
           
           if(del==head)
           {
               head=tmp;
              
           }
           
           del=del->next;
           free(del2);
       }
           if(head==tmp)
               cur=head;
           else
             cur->next=tmp;
            if(tmp==NULL)
                   return head;
             else tmp=tmp->next;
       
   }
       }
      
    return head;
}
```

