/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) 
{
    struct ListNode * link1 = head;
    struct ListNode * link2 = head;
    while(  link1 != NULL && link2 != NULL && link2->next != NULL )
    {
        link1 = link1->next;
        link2 = link2->next->next;
        if( link1 == link2 )
            return true;
    }
    return false;
}