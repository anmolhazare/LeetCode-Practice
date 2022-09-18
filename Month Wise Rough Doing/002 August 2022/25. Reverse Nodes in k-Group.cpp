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
        ListNode* head1=NULL;
        ListNode* tail1 = NULL;
        if(head==NULL || k==0 || k==1) return head;
        
        int tempK = k;
        while(head!=NULL){
            ListNode* start = head;
            ListNode* end = head;
            while(end!=NULL && tempK!=1){
                end=end->next;
                head=head->next;
                tempK--;
            }
            if(end==NULL){
                tail1->next=start;
                return head1;
            }
            head=head->next;
            end->next=NULL;
            pair<ListNode* ,ListNode*> p = reverse(start);
            if(head1==NULL){
                head1=p.first;
                tail1=p.second;
            }else{
                tail1->next=p.first;
                tail1=p.second;
            }
            tempK=k;
        }
        return head1;
    }
};
