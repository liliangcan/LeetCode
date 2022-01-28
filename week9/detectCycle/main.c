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
    // a+(n+1)b+nc = 2(a+b) ⟹ a = c+(n−1)(b+c)      // a 就是从head到入环点的距离，b 是入环点到停止点的慢指针走的距离
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* quick = head;
        while (quick != nullptr) {
            //慢指针每次走一步
            slow = slow->next;
            if (quick->next == nullptr) {   //若快指针下一个就是尾部了，则直接返回nullptr
                return nullptr;
            }
            //快指针每次走两步
            quick = quick->next->next;
            if (quick == slow) {
                //再引入一个ptr，与slow同时向后移动，最终会在入环点相遇
                ListNode *ptr = head;
                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};
