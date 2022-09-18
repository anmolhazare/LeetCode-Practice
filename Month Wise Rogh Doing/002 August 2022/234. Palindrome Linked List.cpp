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
    pair<ListNode* ,ListNode* > reverse(ListNode* head){
        if(head==NULL || head->next==NULL){
            return {head,head};
        }
        pair<ListNode* ,ListNode*> p = reverse(head->next);
        p.second->next=head;
        head->next=NULL;
        p.second=p.second->next;
        return p;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL) return false;
        if(head->next==NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        pair<ListNode* ,ListNode*> p = reverse(slow);
        ListNode* temp = p.first;
        while(temp!=NULL){
            if(temp->val!=head->val) return false;
            temp=temp->next;
            head=head->next;
        }
        return true;
    }
};
