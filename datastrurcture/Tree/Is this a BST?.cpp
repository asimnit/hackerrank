/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
//bool isgreater(Node *root, int pdata);
bool issmaler(Node *root, int pdata)
{
    if(root == NULL)
        return true;
    if(root->data >= pdata)
        return false;
    return issmaler(root->left, pdata) && issmaler(root->left, root->data) && issmaler(root->right, pdata) && isgreater(root->right, root->data);
}
bool isgreater(Node *root, int pdata)
{
    if(root == NULL)
        return true;
    if(root->data <= pdata)
        return false;
    return isgreater(root->right, pdata) && isgreater(root->right, root->data) && isgreater(root->left, pdata) && issmaler(root->left, root->data);
}
bool checkBST(Node *root)
{
    return issmaler(root->left, root->data) && isgreater(root->right, root->data);
}
