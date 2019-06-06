/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */
int height(node *root)
{
   if(root == NULL)
       return -1;
    return root->ht;
}

node* LL(node *x)
{
    node *w = x->left;
    x->left = w->right;
    w->right = x;
    x->ht = max(height(x->left), height(x->right)) + 1;
    w->ht = max(height(w->left), height(x)) + 1;
    return w;
}

node* RR(node *x)
{
    node *w = x->right;
    x->right = w->left;
    w->left = x;
    x->ht = max(height(x->left), height(x->right)) + 1;
    w->ht = max(height(x), height(w->right)) + 1;
    return w;
}

node* LR(node *x)
{
    x->left = RR(x->left);
    return LL(x);
}

node* RL(node *x)
{
    x->right = LL(x->right);
    return RR(x);
}

node * insert(node * root,int val)
{
    if(root == NULL)
    {
        root = new node;
        root->val = val;
        root->right = NULL;
        root->left = NULL;
    }
    if(val < root->val)
    {
        root->left = insert(root->left, val);
        if(height(root->left) - height(root->right) == 2)
        {
            if(val < root->left->val)
                root = LL(root);
             else 
               root = LR(root);
        }
    }
    if(val > root->val)
    {
        root->right = insert(root->right, val);
        if(height(root->right) - height(root->left) == 2)
        {
            if(val > root->right->val)
                root = RR(root);
            else
                root = RL(root);
        }
    }
    root->ht = max(height(root->left), height(root->right)) + 1;
    return root;
}
