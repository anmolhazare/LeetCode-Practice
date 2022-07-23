class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL){
            return head;
        }
        if(head->next==NULL){
            return NULL;
        }
        ListNode* slow = head;
        ListNode* crush = head;
        ListNode* fast = head->next;
        while(fast!=NULL && fast->next!=NULL){
            if(slow!=head){
                crush=crush->next;
            }
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast!=NULL && fast->next==NULL){
            ListNode* temp = slow->next->next;
            slow->next=temp;
        }else{
            crush->next=slow->next;
        }
        return head;
    }
};
