/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        //特殊情况判断啊
        if(!temp){
            return nullptr;
        }
        while(temp->next){
            //若不相等指针就往下走
            if(temp->val != temp->next->val){
                temp = temp->next;
                continue;
            }
            temp->next = temp->next->next;
        }
        return head;
    }
};
