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
    static int pairSum(ListNode* head) {
        ListNode *fast=head, *slow=fast;
        ListNode *rev=NULL, *nextNode;
        while(fast){
            fast=fast->next->next;
            nextNode=slow->next;
            slow->next=rev;
            rev=slow;
            slow=nextNode;           
        }
        int ans=0;
        while(slow){
            int x=rev->val;
            rev=rev->next;
            ans=max(ans, x+(slow->val));
            slow=slow->next;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna