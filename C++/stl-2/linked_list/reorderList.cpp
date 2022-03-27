/*143. 重排链表
给定一个单链表 L 的头节点 head ，单链表 L 表示为：

L0 → L1 → … → Ln - 1 → Ln
请将其重新排列后变为：

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 

示例 1：



输入：head = [1,2,3,4]
输出：[1,4,2,3]
示例 2：



输入：head = [1,2,3,4,5]
输出：[1,5,2,4,3]
 

提示：

链表的长度范围为 [1, 5 * 104]
1 <= node.val <= 1000
*/

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
    void reorderList(ListNode* head) {
        // // method 1, use an auxiliary matrix
        // if (!head) {
        //     return;
        // }
        // vector<ListNode*> vec;
        // ListNode* node = head;
        // while(node) {
        //     vec.push_back(node);
        //     node = node->next;
        // }
        // int i = 0, j = vec.size() - 1;
        // while (i < j) {
        //     vec[i]->next = vec[j];
        //     i++;
        //     if (i == j) {
        //         break;
        //     }
        //     vec[j]->next = vec[i];
        //     j--;
        // }
        // vec[i]->next = nullptr;

        // method 2, not using auxiliary vector
        /*
        注意到目标链表即为将原链表的左半端和反转后的右半端合并后的结果。
        这样我们的任务即可划分为三步：
        1. 找到原链表的中点
        2. 将原链表的右半端反转
        3. 将原链表的两端合并
        */
        if (!head) {
            return;
        }
        // 第一步，找到原链表的中点
        ListNode* mid = findmid(head);
        // 第二部， 将原链表的右半端反转
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = nullptr;//将left从mid处截断
        right = reversList(right);
        mregeList(left, right);
    }

    ListNode* findmid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        // fast每次走两步，slow每次走一步，因此最终fast走到头的时候，slow为中点
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reversList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;

        while (cur) {
            ListNode* next_temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next_temp;
        }
        return pre;
    }

    void mregeList(ListNode* left, ListNode* right) {
        ListNode* temp_left;
        ListNode* temp_right;

        while(left && right) {
            temp_left = left->next;
            temp_right = right->next;

            left->next = right;
            left = temp_left;
            right->next = left;
            right = temp_right;
        }
    }
};

