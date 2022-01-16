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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr){        //判断特殊条件
            return nullptr;
        }
        ListNode* temp = new ListNode(0, head);
        ListNode* newHead = temp;               //设置新的头结点，为防止返回时的错误
        while(temp->next != nullptr){
            if(temp->next->val == val){
                temp->next = temp->next->next;
            }else{
                temp = temp->next;
            }
        }
        return newHead->next;           //此处若直接返回head，会导致错误
    }
};
