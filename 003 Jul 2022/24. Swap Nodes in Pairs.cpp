class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp = head->next;
        ListNode* t = swapPairs(temp->next);
        temp->next=head;
        head->next=t;
        head=temp;
        return head;
    }
};
