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
    vector<int> postorder(Node* root) {
        vector<int> res;
        stack<Node*> stk;
        if(!root){
            return res;     //如果为空树，直接返回
        }
        stk.push(root);         //根节点入栈
        while(!stk.empty()){
            root = stk.top();       //栈顶元素
            stk.pop();
            //先放左边进去，那么右边的就会在栈顶
            for(int i = 0; i < root->children.size(); i++){
                stk.push(root->children[i]);
            }           
            res.push_back(root->val);       //访问根
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
