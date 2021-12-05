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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* h = (ListNode*)malloc(sizeof(ListNode)),*q,*p,*temp,*pre;
        h->next = list1;
        pre = h;
        q = list1;
        p = list2;
        if (q == nullptr) {     //当表1为空返回表2
            return p;
        } else if (p == nullptr) {      //当表2为空返回表1
            return q;
        }
        while(p!=NULL){            //将表2的元素插入到表1中
            while(q!=NULL&&p->val>q->val){
                //若p当前值大于q值，则表1的两个指针pre，q不断后移
                q=q->next;
                pre=pre->next;
            }
            //当p不大于q时，就将p插入q的前驱节点pre后面
            temp=p->next;
            p->next=q;
            pre->next=p;
            p=temp;
            q=pre->next;        //pre的后继成为新的q节点
        }
        h=h->next;
        return h;
    }
};
