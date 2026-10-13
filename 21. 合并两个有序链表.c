//21. 合并两个有序链表
//思路：创建新表头，比较两链表值的大小并连接。
//复杂度O(m+n)/O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* list3=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* c=list3;
    while(list1!=NULL&&list2!=NULL){
        if(list1->val<=list2->val)
        {c->next=list1,list1=list1->next;}
        else
        {c->next=list2,list2=list2->next;}
        c=c->next;
    }
    if(list1!=NULL)
    c->next=list1;
    else
    c->next=list2;
    return list3->next;
}