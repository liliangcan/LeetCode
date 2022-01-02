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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;                              //初始化进位值为0
        while (l1 || l2) {
            int n1 = l1 ? l1->val: 0;
            int n2 = l2 ? l2->val: 0;
            int sum = n1 + n2 + carry;              //记得要加上进位
            if (!head) {
                head = tail = new ListNode(sum % 10);       //当链表为空时加入第一个节点
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;                               //保存进位值
            if (l1) {
                l1 = l1->next;                  //如果某一个链表还有就继续生成新链表的后续节点
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {                            //到最后如果有进位就再加一个节点存贮
            tail->next = new ListNode(carry);
        }
        return head;
    }
};
