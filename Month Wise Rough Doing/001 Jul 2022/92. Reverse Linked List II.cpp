class Solution {
public:
    pair<ListNode* ,ListNode* > reverse(ListNode* head){
        if(head==NULL || head->next==NULL){
            pair<ListNode* , ListNode*> p;
            p.first=head;
            p.second=head;
            return p;
        }
        pair<ListNode* , ListNode* > temp = reverse(head->next);
        temp.second->next=head;
        head->next=NULL;
        temp.second=head;
        return temp;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* start = NULL;
        ListNode* end = NULL;
        ListNode* prev = NULL;
        ListNode* temp = head;
        int count=1;
        if(left==1){
            start=head;
        }
        while(temp->next!=NULL){
            if((count+1)==left){
                prev=temp;
                start=temp->next;
            }
            if(count==right){
                end=temp->next;
                temp->next=NULL;
                break;
            }
            temp=temp->next;
            count++;
        }
        pair<ListNode* , ListNode* > tempu = reverse(start);
        if(tempu.first!=NULL){
            if(prev==NULL){
                 tempu.second->next=end; 
                 return tempu.first;
            }
         prev->next=tempu.first;
         tempu.second->next=end;   
        }
        return head;
    }
};
