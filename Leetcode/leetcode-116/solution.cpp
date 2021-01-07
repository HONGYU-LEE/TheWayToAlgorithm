/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void solution(Node* node1, Node* node2)
    {
        if(!node1 || !node2)
        {
            return;
        }
        //前序遍历
        node1->next = node2;

        //连接同一个父节点的左右节点
        solution(node1->left, node1->right);
        solution(node2->left, node2->right);
        //连接不同父节点，左节点的右子树连接右节点的左子树
        solution(node1->right, node2->left);
    }

    Node* connect(Node* root) {
        if(root == nullptr)
        {
            return nullptr;
        }

        solution(root->left, root->right);
        return root;
    }
};