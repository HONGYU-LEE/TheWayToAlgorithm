bool isMirror(struct TreeNode* q, struct TreeNode* p)
{
    if(!p && !q)
        return true;
    else if(!p || !q)
        return false;
    
    if(p->val != q->val)
        return false;

    return ismirror(q->right, p->left) && ismirror(q->left, p->right);
}

bool isSymmetric(struct TreeNode* root){
    if(!root)
        return true;

    return ismirror(root->left, root->right);
}
