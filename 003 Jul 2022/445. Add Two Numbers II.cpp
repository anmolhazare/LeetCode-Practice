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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         pair<ListNode* , ListNode* > temp1 = reverse(l1);
         pair<ListNode* , ListNode* > temp2 = reverse(l2);
         int carry = 0;
         ListNode* head = NULL;
         ListNode* tail = NULL;
         while(temp1.first!=NULL && temp2.first!=NULL){
               int sum = carry+temp1.first->val+temp2.first->val;
               if(sum>9){
                   carry=1;
                   sum-=10;
               }else{
                   carry=0;
               }
               ListNode* temp = new ListNode(sum);
             if(head==NULL){
                 head=temp;
                 tail=temp;
             }else{
                 tail->next=temp;
                 tail=tail->next;
             }
             temp1.first=temp1.first->next;
             temp2.first=temp2.first->next;
         }
         if(temp1.first==NULL && temp2.first==NULL && carry==0){
            pair<ListNode* , ListNode* > amit = reverse(head);
             return amit.first;
         }else if(temp1.first==NULL && temp2.first==NULL && carry==1){
             ListNode* temp = new ListNode(1);
             if(head==NULL){
                 head=temp;
                 tail=temp;
             }else{
                 tail->next=temp;
                 tail=tail->next;
             }
             pair<ListNode* , ListNode* > amit = reverse(head);
             return amit.first;
         }else if(temp1.first!=NULL){
             while(temp1.first!=NULL){
                 int sum = carry+temp1.first->val;
               if(sum>9){
                   carry=1;
                   sum-=10;
               }else{
                   carry=0;
               }
               ListNode* temp = new ListNode(sum);
              if(head==NULL){
                 head=temp;
                  tail=temp;
             }else{
                 tail->next=temp;
                 tail=tail->next;
              }
             temp1.first=temp1.first->next;
             }
             
             if(carry==0){
                 pair<ListNode* , ListNode* > amit = reverse(head);
                 return amit.first;
             }else{
                  ListNode* temp = new ListNode(1);
             if(head==NULL){
                 head=temp;
                 tail=temp;
             }else{
                 tail->next=temp;
                 tail=tail->next;
             }
             pair<ListNode* , ListNode* > amit = reverse(head);
             return amit.first;
             }
         }else{
             while(temp2.first!=NULL){
                 int sum = carry+temp2.first->val;
               if(sum>9){
                   carry=1;
                   sum-=10;
               }else{
                   carry=0;
               }
               ListNode* temp = new ListNode(sum);
              if(head==NULL){
                 head=temp;
                  tail=temp;
             }else{
                 tail->next=temp;
                 tail=tail->next;
              }
             temp2.first=temp2.first->next;
             }
             
             if(carry==0){
                 pair<ListNode* , ListNode* > amit = reverse(head);
                 return amit.first;
             }else{
                  ListNode* temp = new ListNode(1);
             if(head==NULL){
                 head=temp;
                 tail=temp;
             }else{
                 tail->next=temp;
                 tail=tail->next;
             }
             pair<ListNode* , ListNode* > amit = reverse(head);
             return amit.first;
             }
         }
             
         }
};
