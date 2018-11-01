leetcode 101对称二叉树

给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 `[1,2,2,3,4,4,3]` 是对称的。

```
    1
   / \
  2   2
 / \ / \
3  4 4  3

```

但是下面这个 `[1,2,2,null,3,null,3]` 则不是镜像对称的:

```
    1
   / \
  2   2
   \   \
   3    3

```

**说明:**

如果你可以运用递归和迭代两种方法解决这个问题，会很加分。

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool sameTree(struct TreeNode* root1,struct TreeNode* root2)
{
   if(root1==NULL&&root2==NULL)
       return true;                    //两个树根节点为空
    if(root1==NULL||root2==NULL)    //一个为空另一个不为空
        return false;

    return (root1->val==root2->val)&&sameTree(root1->left,root2->right)&&sameTree(root1->right,root2->left);
        
}
bool isSymmetric(struct TreeNode* root) {
    
    if(root==NULL)
        return true;
    
    return  sameTree(root->left,root->right);
}
```

