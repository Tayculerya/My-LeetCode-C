//148. 排序链表
//思路：找中点，断链，递归组数，合并。
//复杂度O(nlogn)/O(logn)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* merge(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy; 
    struct ListNode* tail = &dummy;
    
    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if (l1 != NULL) tail->next = l1;
    if (l2 != NULL) tail->next = l2;
    
    return dummy.next;
}
struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode *slow = head;
    struct ListNode *fast = head->next; 
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* rightHead = slow->next; 
    slow->next = NULL;                       
    struct ListNode* left = sortList(head);
    struct ListNode* right = sortList(rightHead);
    return merge(left, right);
}