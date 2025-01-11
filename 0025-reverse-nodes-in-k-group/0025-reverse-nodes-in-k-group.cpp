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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* front;
        while (temp != NULL) {
            front = temp->next;  // Store the next node
            temp->next = prev;   // Reverse the link
            prev = temp;         // Move `prev` to the current node
            temp = front;        // Move `temp` to the next node
        }
        return prev;  // `prev` will be the new head of the reversed list
    }

    ListNode* getkthnode(ListNode* head, int k) {
        k--;
        ListNode* temp = head;
        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;
        ListNode* nextNode;

        while (temp != NULL) {
            ListNode* kthnode = getkthnode(temp, k);
            if (kthnode == NULL) {
                if (prevLast) {
                    prevLast->next = temp;
                }
                break;
            }
            nextNode = kthnode->next;
            kthnode->next = NULL;

            // Reverse the current group
            ListNode* reversedHead = reverseList(temp);

            if (temp == head) {
                head = reversedHead;  // Update head if it's the first group
            } else {
                prevLast->next = reversedHead;  // Connect previous group to the current one
            }

            prevLast = temp;  // Update prevLast to the current group's tail
            temp = nextNode;  // Move to the next group
        }

        return head;
    }
};
