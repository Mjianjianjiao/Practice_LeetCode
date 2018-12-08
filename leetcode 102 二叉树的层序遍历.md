leetcode 102 二叉树的层序遍历

给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: `[3,9,20,null,null,15,7]`,

```
    3
   / \
  9  20
    /  \
   15   7

```

返回其层次遍历结果：

```
[
  [3],
  [9,20],
  [15,7]
]
```

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)
            return vector<vector<int>> ();
        
        queue<TreeNode*> root_q;
        queue<int> level;
        vector<vector<int>> ret_v;

        root_q.push(root);
        level.push(0);
        
        while(!root_q.empty()){
           
            int leve = level.front() ;
            vector<int> leve_v;        
            
            while(leve == level.front())
            {
                root = root_q.front();   
                
                if(root)
                {
                   leve_v.push_back(root->val);
                   root_q.push(root->left);
                   level.push(leve+1);
                   root_q.push(root->right);
                   level.push(leve+1);
                }
                
                root_q.pop();
                level.pop();
            }
            
            if(!leve_v.empty())
            ret_v.push_back(leve_v);
        }
          return ret_v;  
    }
};
```

