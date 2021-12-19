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
    bool isPalindrome(ListNode* head) {
        stack<int> tmp;                     //生成一个临时存储的栈
        ListNode* current = head;
        while(current){                     //将链表元素全都压栈
            tmp.push(current->val);
            current = current->next;
        }
        current = head;
        while(current){                     //分别比较栈顶元素和链表从头开始的元素
            if(tmp.top() != current->val){
                return false;
            }
            tmp.pop();                  //弹出一个元素
            current = current->next;       //链表指针后移
        }
        return true;
    }
};
