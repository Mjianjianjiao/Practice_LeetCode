leetcode 946 验证栈序列

给定 `pushed` 和 `popped` 两个序列，只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时，返回 `true`；否则，返回 `false` 。

 

**示例 1：**

```
输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
输出：true
解释：我们可以按以下顺序执行：
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

```

**示例 2：**

```
输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
输出：false
解释：1 不能在 2 之前弹出。
```

```
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
  
        //使用一个栈进行模拟出入栈的操作，先将数据入栈，如果栈顶的数据与出栈的数据相同，则将栈顶元素出栈，如果不相同就连续入栈，直到相同时再出栈
        
        if(pushed.size() != popped.size())
            return  false;
        
        stack<int> st;
        
        int index_push = 0;
        int index_pop = 0;
        
        while(index_push < pushed.size())
        {
            st.push(pushed[index_push]);
             while(index_pop < popped.size() && !st.empty() &&st.top() == popped[index_pop])  //栈不为空时才能取栈定元素
            {
                st.pop();
                index_pop++;
            }
            
            index_push++;
        }
        
        return !st.size();
    }
};
```

