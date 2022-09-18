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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL) return NULL;
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        ListNode* head=NULL;
        ListNode* tail=NULL;
        
        while(list1!=NULL && list2!=NULL){
            if(list1->val>list2->val){
                ListNode* temp = new ListNode(list2->val);
                if(head==NULL){
                    head=temp;
                    tail=temp;
                }else{
                    tail->next=temp;
                    tail=tail->next;
                }
                list2=list2->next;
            }else{
                ListNode* temp = new ListNode(list1->val);
                if(head==NULL){
                    head=temp;
                    tail=temp;
                }else{
                    tail->next=temp;
                    tail=tail->next;
                }
                list1=list1->next;
            }
        }
        if(list1!=NULL){
            tail->next=list1;
        }
        if(list2!=NULL){
            tail->next=list2;
        }
        return head;
        
    }
};
