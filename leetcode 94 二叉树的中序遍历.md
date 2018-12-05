leetcode 94 二叉树的中序遍历

给定一个二叉树，返回它的*中序 *遍历。

**示例:**

```
输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
```

**进阶:** 递归算法很简单，你可以通过迭代算法完成吗？

- 递归中序遍历二叉树

  ```
  class Solution {
  public:
      
      void InorderBT(TreeNode* root, vector<int>& Inorder)
      {
          if(root == NULL)
              return ;
          
          InorderBT(root->left,Inorder);
          Inorder.push_back(root->val);
          InorderBT(root->right,Inorder);
          
      }
      vector<int> inorderTraversal(TreeNode* root) {
          
          vector<int> Inorder;
          InorderBT(root,Inorder);
          
          return Inorder;
          
      }
  };
  ```

  ​

- 非递归中序遍历二叉树

```
class Solution {
public:
    
   
    vector<int> inorderTraversal(TreeNode* root) {
        
        if(root == NULL)
            return vector<int> ();
        
        stack<TreeNode*>  st;
        vector<int> inorder;
        
        while(root || !st.empty())
        {
            while(root)
            {
                st.push(root);
                root = root -> left;
            }
            
            root =st.top() -> right;
            inorder.push_back(st.top()->val);
            st.pop();
            
            if(root == NULL && !st.empty())
            {
                root = st.top() -> right;
                inorder.push_back(st.top()->val);
                st.pop();
            }
        }
        
        return inorder;
 
        
    }
};
```

