leetcode 700 serach-in-abinary-search-tree

二叉搜索树中的搜索

给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。

例如，

```
给定二叉搜索树:

        4
       / \
      2   7
     / \
    1   3

和值: 2

```

你应该返回如下子树:

```
      2     
     / \   
    1   3
```

```
//递归查找
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    
    if(root==NULL)
        return NULL;
    if(root->val==val)
        return root;
    if(root->val>val)
      return   searchBST(root->left,val);
    
       return   searchBST(root->right,val);
    
}
```

```
//迭代
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    
    while(root!=NULL&&root->val!=val)
    {
        root=root->val>val?root->left:root->right;
    }
    return root;
}

```

