/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {  //深度优先搜索
        if (root == nullptr) {
            return 0;
        }
        int maxChildDepth = 0;
        vector<Node *> children = root->children;
        for (auto child : children) {
            int childDepth = maxDepth(child);       //计算孩子们的最大深度
            maxChildDepth = max(maxChildDepth, childDepth);     //在二者取最大值作为maxChildDepth
        }
        return maxChildDepth + 1;
        
    }
};
