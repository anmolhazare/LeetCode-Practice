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
    ListNode* h;
    int size(ListNode* head){
        if(head==NULL) return 0;
        return 1+size(head->next);
    }
    Solution(ListNode* head) {
        h=head;
    }
    
    int getRandom() {
        int num = rand() % size(h);
        ListNode* temp = h;
        while(num--){
            temp=temp->next;
        }
        
        return temp->val;
        
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */