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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA,*pB;
        if(!headA || !headB){return nullptr;}       //任意一个为空都不会有交点
        pA=headA;
        pB=headB;
        while(pA != pB){
            pA = pA!=nullptr?pA->next:headB;        //当到尾部时就跳到另一个链表头部
            pB = pB!=nullptr?pB->next:headA;
        }
        return pA;              //若有相交，最多遍历到第二次的某处就会得出答案
        
    }
};
