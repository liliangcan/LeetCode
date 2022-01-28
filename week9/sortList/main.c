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
    ListNode* sortList(ListNode* head) {
        vector<int> temp;
        ListNode* ptr = head;
        //先将链表的所有元素都放进一个向量中
        while(ptr != nullptr){
            temp.push_back(ptr->val);
            ptr = ptr->next;
        }
        ptr = head;
        //然后对其进行排序
        sort(temp.begin(),temp.end());
        //接着按照顺序放回去
        for(int i = 0; i < temp.size(); i++){
            ptr->val = temp[i];
            ptr = ptr->next;
        }
        //最后返回头结点
        return head;
    }
};
