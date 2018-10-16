leetcode 328 even-linked-list

奇偶链表

给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。

**示例 1:**

```
输入: 1->2->3->4->5->NULL
输出: 1->3->5->2->4->NULL

```

**示例 2:**

```
输入: 2->1->3->5->6->4->7->NULL 
输出: 2->3->6->7->1->5->4->NULL
```

**说明:**

- 应当保持奇数节点和偶数节点的相对顺序。
- 链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode* cur=head;
    struct ListNode* per=head;
    struct ListNode* pos=head;
    struct ListNode* tmp;
    
    if(head==NULL||head->next==NULL)
        return head;
    per=cur->next;
    cur=per->next;
    while(cur)
    {
        
       
        tmp=cur;
        per->next=cur->next;
        
        tmp->next=pos->next;
        pos->next=tmp;  //取每次最后一个奇数节点的位置
        pos=pos->next;  //移到最后一个奇数节点
        
        per=per->next;
        if(per==NULL)
           break; 
        cur=per->next;
    }
    
    return head;
}
```

