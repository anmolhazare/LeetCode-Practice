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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL){
            return head;
        }
        queue<int> odd;
        queue<int> even;
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            if(count%2==0){
                odd.push(temp->val);
            }else{
                even.push(temp->val);
            }
            count++;
            temp=temp->next;
        }
        ListNode* head2=NULL;
        ListNode* tail = NULL;
        while(odd.size()!=0){
            ListNode* amit = new ListNode(odd.front());
            odd.pop();
          if(head2==NULL)   {
             head2 = amit;
              tail=amit;
          }else{
              tail->next=amit;
              tail=tail->next;
          }
        }
        while(even.size()!=0){
            ListNode* amit = new ListNode(even.front());
            even.pop();
          if(head2==NULL)   {
              head2= amit;
              tail=amit;
          }else{
              tail->next=amit;
              tail=tail->next;
          }
        }
        return head2;
    }
};
