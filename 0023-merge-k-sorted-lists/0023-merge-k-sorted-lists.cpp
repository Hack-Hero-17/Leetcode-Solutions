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
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        if (arr.size() == 0) return nullptr;
        if (arr.size() == 1) return arr[0];
        ListNode* head;
        priority_queue<int> pq;
        
        for (int i=0; i<arr.size(); ++i) {
            head = arr[i];
            while (head) {
                pq.push(head->val);
                head = head->next;
            }
        }
        
        head = nullptr;
        
        while (!pq.empty()) {
            ListNode* temp = new ListNode(pq.top());
            pq.pop();
            temp->next = head;
            head = temp;
        }
        return head;
    }
};