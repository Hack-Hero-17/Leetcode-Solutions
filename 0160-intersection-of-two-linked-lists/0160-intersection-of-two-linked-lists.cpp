/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> st;
        ListNode * l1 = headA;
        while( l1!=NULL )
        {
            st.insert(l1);
            l1 = l1->next;
        }
        ListNode * l2 = headB;
        while( l2!= NULL )
        {
            if( st.find(l2) != st.end()) return l2;
            l2 = l2->next;
        }
        return NULL;
    }
};