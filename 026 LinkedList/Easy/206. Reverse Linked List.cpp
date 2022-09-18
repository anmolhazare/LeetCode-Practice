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
    pair<ListNode* , ListNode*> helper(ListNode* head){
        if(head==NULL || head->next==NULL) return {head,head};
        pair<ListNode* ,ListNode*> temp = helper(head->next);
        temp.second->next=head;
        temp.second=temp.second->next;
        head->next=NULL;
        return temp;
    }
    ListNode* reverseList(ListNode* head) {
        pair<ListNode* , ListNode*> temp =  helper(head);
        return temp.first;
        
    }
};
