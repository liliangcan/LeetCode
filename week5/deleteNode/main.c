/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        //既然不能先删除自己，那就把自己整容成儿子，再假装儿子养活孙子
        //超有意思的一种说法，好容易就记住了
        node->val = node->next->val;
        node->next = node->next->next;       
    }
};
