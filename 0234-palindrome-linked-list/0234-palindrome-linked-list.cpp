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
    bool isPalindrome(ListNode* head) {
        stack<int> sk;
        ListNode * temp = head;
        while( temp!= NULL )
        {
            sk.push( temp->val );
            temp = temp->next;
        }

        temp = head;
        while( temp!=NULL )
        {
            if( temp->val != sk.top() )
                return false;
            temp = temp->next;
            sk.pop();
        }

        return true;

    }
};