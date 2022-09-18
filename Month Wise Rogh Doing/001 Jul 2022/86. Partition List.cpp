class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL){
            return head;
        }
        ListNode* temp = partition(head->next,x);
        if(head->val>=x && temp!=NULL && temp->val<x){
            ListNode* amit = temp;
            while(amit->next!=NULL && amit->next->val<x){
                amit=amit->next;
            }
            ListNode* yash = amit->next;
            if(amit->val==x && yash==NULL){
                head->next=temp;
                return head;
            }
            amit->next=head;
            head->next=yash;
            return temp;
        }
        head->next=temp;
        return head;
    }
};
