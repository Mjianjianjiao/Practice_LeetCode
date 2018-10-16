leetcode 147 insretion-sort-list

对链表进行插入排序。

![img](https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif)
插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。

 

**插入排序算法：**

1. 插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
2. 每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
3. 重复直到所有输入数据插入完为止。

 

**示例 1：**

```
输入: 4->2->1->3
输出: 1->2->3->4

```

**示例 2：**

```
输入: -1->5->3->4->0
输出: -1->0->3->4->5
```

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode* cur=head;
    struct ListNode* end=head;
    struct ListNode* tmp,*per;
    struct ListNode* newhead=NULL;
    newhead=malloc(sizeof(struct ListNode));
    newhead->next=head;
    if(head==NULL||head->next==NULL)
        return head;
    end=newhead->next;
    while(end&&end->next)
    {
        if(end->next->val>end->val)
            end=end->next;
        else{
            
        cur=newhead->next;
        tmp=end->next;
        end->next=tmp->next;
        while(cur!=end)
        {
        if(cur->val<tmp->val)
        {
            per=cur;
            cur=cur->next;
        }
        else break;
        }
            
            if(cur==newhead->next)
            {
                tmp->next=newhead->next;
                newhead->next=tmp;
            }else
            {
                tmp->next=per->next;
                per->next=tmp;
            }
        }
       
    }
        head=newhead->next;
    return head;
    
}
```

