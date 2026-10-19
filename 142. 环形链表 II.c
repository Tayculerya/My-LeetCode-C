//142. 环形链表 II
//思路：快慢指针找相同点，再找循环头部。
//复杂度：O(n)/O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode*slow=head;
    struct ListNode*fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            struct ListNode*a=head;
            struct ListNode*b=slow;
            while(a!=b){
                a=a->next;
                b=b->next;
            }
            return a;
        }
    }
    return NULL;
}