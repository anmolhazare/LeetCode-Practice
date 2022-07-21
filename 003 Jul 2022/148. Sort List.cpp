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
            if(amit==temp){
                amit=amit->next;
            }else{
                prev=prev->next;
                amit=amit->next;
            }
        }
        prev->next=head;
        head->next=amit;
        return temp;
    }
};
