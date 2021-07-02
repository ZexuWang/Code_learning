/*
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

示例1：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // recuesive solution
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            //多重调用引发多重返回，返回的顺序应该和调用的顺序相匹配
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }

    }
};

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode* head = new ListNode(0);
            ListNode* cur = head;
            while (l1 && l2) {
                if (l1->val < l2->val) {
                    cur->next = l1;
                    l1 = l1->next;
                } else {
                    cur->next = l2;
                    l2 = l2->next;
                }
                cur = cur->next;
            }
            cur->next = l1 ? l1 : l2;
            return head->next;
            
        }

};