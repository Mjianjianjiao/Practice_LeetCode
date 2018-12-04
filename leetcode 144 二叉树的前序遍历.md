leetcode 144 二叉树的前序遍历

给定一个二叉树，返回它的 *前序 *遍历。

 **示例:**

```
输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [1,2,3]

```

**进阶:** 递归算法很简单，你可以通过迭代算法完成吗？

```
//非递归
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
    vector<int> preorderTraversal(TreeNode* root) {
        
        /*
        *  前序遍历二叉树
        *
        ****/
    
        stack<TreeNode*> st;
        vector<int> prev;
        
        
        while(root || !st.empty())
        {
            while(root)
            {
                st.push(root);
                prev.push_back(root->val);
                root = root -> left;
            }
            
            root = st.top()->right;
            st.pop();
            
            if(root==NULL&&!st.empty())
            {
                root = st.top() ->right;
                st.pop();
            }
                
            
        }
        
        
       return prev;
    }
};
```

```
//递归
class Solution {
public:
    void PrevBTree(TreeNode* root, vector<int>& prev)
        {
            if(root == NULL)
                return ;
            prev.push_back(root->val);
            PrevBTree(root->left,prev);
            PrevBTree(root->right,prev);
        }
        
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> prev;
        PrevBTree(root,prev);
        return prev;
        
    }
};
```



