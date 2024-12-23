Ques 2. You are given two non-empty linked lists representing two non
negative integers. The digits are stored in reverse order, and each of their 
nodes contains a single digit. Add the two numbers and return the sum as a 
linked list. 
You may assume the two numbers do not contain any leading zero, except 
the number 0 itself. 

Program code: 
#include <iostream> 
#include <vector> 
struct ListNode { 
    int val; 
    ListNode *next; 
    ListNode(int x) : val(x), next(nullptr) {} 
}; 
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { 
    ListNode* dummyHead = new ListNode(0);  
    ListNode* p = l1, * q = l2, * curr = dummyHead; 
    int carry = 0; 
    while (p != nullptr || q != nullptr) { 
        int x = (p != nullptr) ? p->val : 0; 
        int y = (q != nullptr) ? q->val : 0; 
        int sum = carry + x + y; 
        carry = sum / 10; 
        curr->next = new ListNode(sum % 10); 
        curr = curr->next; 
        if (p != nullptr) p = p->next; 
        if (q != nullptr) q = q->next; 
    } 
    if (carry > 0) { 
        curr->next = new ListNode(carry); 
    } 
    return dummyHead->next; // Return the actual head of the resulting linked 
list 
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
    std::vector<int> l1_vals = {2, 4, 3}; 
    std::vector<int> l2_vals = {5, 6, 4}; 
    ListNode* l1 = createLinkedList(l1_vals); 
ListNode* l2 = createLinkedList(l2_vals); 
ListNode* result = addTwoNumbers(l1, l2); 
printLinkedList(result); 
return 0; 
} 
