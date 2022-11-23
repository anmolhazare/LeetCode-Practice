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
    ListNode* create(vector<int> &arr){
        ListNode* head=NULL;
        ListNode* tail=NULL;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            ListNode* temp = new ListNode(arr[i]);
            if(head==NULL){
                head=temp;
                tail=temp;
            }else{
                tail->next=temp;
                tail=tail->next;
            }
        }
        return head;
        
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        vector<int> arr;
        while(head!=NULL){
            arr.push_back(head->val);
            head=head->next;
        }
        return create(arr);
    }
};