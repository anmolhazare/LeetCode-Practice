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
    pair<ListNode*,ListNode*> reverse(ListNode* head){
        if(head==NULL || head->next==NULL) return {head,head};
        pair<ListNode*,ListNode*> p = reverse(head->next);
        p.second->next=head;
        p.second=p.second->next;
        head->next=NULL;
        return p;
    }
    ListNode* mid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    int pairSum(ListNode* head) {
        ListNode* temp = head;
        ListNode* middle = mid(temp);
        pair<ListNode*,ListNode*> p = reverse(middle);
        ListNode* p_reverse = p.first;
        int max=INT_MIN;
        while(p_reverse!=NULL){
            int tu = p_reverse->val+head->val;
            p_reverse=p_reverse->next;
            head=head->next;
            if(tu>max) max=tu;
        }
        return max;
    }
};
