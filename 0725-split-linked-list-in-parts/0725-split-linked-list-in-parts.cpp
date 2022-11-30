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
    int size(ListNode* head){
        if(head==NULL) return 0;
        return 1+size(head->next);
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int div = size(head)/k;
        int rem = size(head)%k;
        vector<ListNode*> ans;
        
        while(head!=NULL){
            int temp = 0;
            if(rem!=0){
                temp++;
                rem--;
            }
            ans.push_back(head);
            for(int i=1;i<(div+temp);i++){
                head=head->next;
            }
            
            ListNode* tt = head->next;
            head->next=NULL;
            head=tt;
            
        }
        
        while(ans.size()!=k) ans.push_back(NULL);
        
        return ans;
        
        
    }
};