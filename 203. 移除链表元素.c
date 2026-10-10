//203. 移除链表元素
//思路：虚拟头节点+单指针遍历
//复杂度：O(n)/O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* a=(struct ListNode*)malloc(sizeof(struct ListNode));
    a->next=head;
    struct ListNode* i=a;
    while(i->next!=NULL){
        if(i->next->val==val){
            struct ListNode* b=i->next;
            i->next=i->next->next;
            free(b);
        }
        else
        i=i->next;
    }
    struct ListNode* newhead=a->next;
    free(a);
    return newhead;
}
