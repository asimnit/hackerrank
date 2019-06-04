#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/
void topView(Node * root) {
        if(root == NULL)
        return;
        map<int, int> m;
        queue< pair<Node*, int> > q;
        q.push(make_pair(root, 0));
         
        while(!q.empty())
        {
            pair<Node*, int> p = q.front();
            Node *n = p.first;
            int val = p.second;
            q.pop();
            if (m.find(val) == m.end()) {
              m[val] = n->data;
              cout << n->data << " ";
            }
            if (n->left!= NULL)
              q.push(make_pair(n->left, val - 1));
            if (n->right != NULL)
              q.push(make_pair(n->right, val + 1));
        }
    }
}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.topView(root);
    return 0;
}
