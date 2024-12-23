Ques 4. Given the head of a linked list, reverse the nodes of the list k at a 
time, and return the modified list. 
k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes, in the end, 
should remain as it is. 
You may not alter the values in the list's nodes, only nodes themselves may 
be changed. 

Program Code: 
#include <iostream> 
#include <vector> 
struct ListNode { 
int val; 
ListNode *next; 
ListNode(int x) : val(x), next(nullptr) {} 
}; 
ListNode* reverseKGroup(ListNode* head, int k) { 
if (!head || k == 1) return head; 
ListNode dummy(0); 
dummy.next = head; 
ListNode* curr = &dummy; 
    ListNode* nex = &dummy; 
    ListNode* pre = &dummy; 
    int count = 0; 
    while (curr->next) { 
        curr = curr->next; 
        count++; 
    } 
    while (count >= k) { 
        curr = pre->next; 
        nex = curr->next; 
        for (int i = 1; i < k; ++i) { 
            curr->next = nex->next; 
            nex->next = pre->next; 
            pre->next = nex; 
            nex = curr->next; 
        } 
        pre = curr; 
        count -= k; 
    } 
    return dummy.next; 
} 
 
ListNode* createLinkedList(const std::vector<int>& nums) { 
    ListNode* dummyHead = new ListNode(0); 
    ListNode* curr = dummyHead; 
    for (int num : nums) { 
        curr->next = new ListNode(num); 
        curr = curr->next; 
    } 
    return dummyHead->next; 
} 
 
void printLinkedList(ListNode* head) { 
    ListNode* curr = head; 
    while (curr != nullptr) { 
        std::cout << curr->val; 
        if (curr->next != nullptr) { 
            std::cout << " -> "; 
        } 
        curr = curr->next; 
    } 
    std::cout << std::endl; 
} 
 
int main() { 
    std::vector<int> vals = {1, 2, 3, 4, 5}; 
    ListNode* head = createLinkedList(vals); 
     
    int k = 2; 
    std::cout << "Original list: "; 
    printLinkedList(head); 
 
    ListNode* result = reverseKGroup(head, k); 
 
std::cout << "Reversed list in groups of " << k << ": "; 
printLinkedList(result); 
return 0; 
} 
