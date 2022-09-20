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
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp = sortList(head->next);
        if(temp!=NULL && head->val<=temp->val){
            head->next=temp;
            return head;
        }
        ListNode* amit = temp;
        ListNode* prev = temp;
        while(amit!=NULL && amit->val<head->val){
            prev=amit;
            amit=amit->next;
        }
        prev->next=head;
        head->next=amit;
        return temp;
    }
};
