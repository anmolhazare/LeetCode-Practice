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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        //Some variables that we need
        ListNode* prev = list1;
        ListNode* temp = list1;
        ListNode* end = NULL;
        ListNode* list2_end = list2;
        while(list2_end->next!=NULL){
            list2_end=list2_end->next;
        }
        
        int count=0;
        //Remove the Elements
        while(temp->next!=NULL){
            if(a!=0 && count==a-1){
                prev=temp;
            }
            if(count==b){
                end=temp->next;
            }
            count++;
            temp=temp->next;
        }
        prev->next=list2;
        list2_end->next=end;
        return list1;
        
    }
};
