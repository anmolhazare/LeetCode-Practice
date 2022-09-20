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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==0 || k==1) return head;
        ListNode* temp = head;
        int t = k;
        while(temp!=NULL && t>1){
            temp=temp->next;
            t--;
        }
        if(temp==NULL) return head;
        ListNode* store = temp->next;
        temp->next=NULL;
        pair<ListNode* ,ListNode* > p = reverse(head);
        p.second->next=reverseKGroup(store,k);
        return p.first;
    }
};
