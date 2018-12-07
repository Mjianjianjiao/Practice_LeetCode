leetcode 145 二叉树的后续遍历

给定一个二叉树，返回它的 *后序 *遍历。

**示例:**

```
输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [3,2,1]
```

**进阶:** 递归算法很简单，你可以通过迭代算法完成吗？

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        if(root == NULL)
            return vector<int> ();
        
        stack<TreeNode*> st;
        stack<int> flag;
        vector<int> ret_value;
        
        while(root || !st.empty()){
     
            while(root){
                st.push(root);
                flag.push(1);
                root = root -> left;
            }
            root = st.top() -> right;
            flag.top() += 1;

            
            if(root == NULL && !st.empty())
            {
             
                
                //判断该节点是否已经进入过
                while(!flag.empty()&&flag.top() != 1)
                {
                    ret_value.push_back(st.top() -> val);   //如果进入过右字数，将其直接出
                    st.pop();
                    flag.pop();
                }
                
                if(!st.empty())
                {
                 root = st.top() -> right;
                    flag.top() += 1;
                }
            }
        
        }
        
        return ret_value;
    }
};
```

