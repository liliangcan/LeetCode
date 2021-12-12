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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> interim;
        while (head != nullptr) {
            if (interim.count(head)) { return true; }       //当已经在集合里了说明已出现环，当即返回
            interim.insert(head);
            head = head->next;
        }
        return false;
    }
};
