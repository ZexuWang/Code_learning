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
    vector<int> reversePrint(ListNode* head) {
        if (head == NULL) return {};
        auto pre = reversePrint(head->next);
        pre.push_back(head->val);
        return pre;

    }
};