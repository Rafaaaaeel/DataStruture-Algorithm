#include <iostream>


/*

Given -> 
    [2,5,8] 
       + 
    [5,1,2]

Then

    [7,6,0]
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 int main ()
 {
    ListNode* firstNode = new ListNode(2);
    ListNode* secondNode = new ListNode(5);
    ListNode* thirdNode = new ListNode(8);

    ListNode* firstNodeSecondList = new ListNode(5);
    ListNode* secondNodeSecondList = new ListNode(1);
    ListNode* thirdNodeSecondList = new ListNode(2);


    secondNode->next = thirdNode;
    firstNode->next = secondNode;

    secondNodeSecondList->next = thirdNodeSecondList;
    firstNodeSecondList->next = secondNodeSecondList;


    ListNode* l1 = firstNode;
    ListNode* l2 = firstNodeSecondList;

    
    ListNode* finalList = new ListNode();

    while(l1)
    {
        int total = l1->val + l2->val;

        ListNode* node = new ListNode(total);

        if (finalList->next == nullptr && finalList->val == 0) 
        {
            finalList->val = total;
        } else 
        {
            ListNode* temp = finalList;

            while(temp->next != nullptr) 
            {
                temp = temp->next;
            }

            temp->next = node;
        }

        l1 = l1->next;
        l2 = l2->next;
    }

    ListNode* temp = finalList;

    while(temp)
    {
        std::cout << temp->val << "\n";
        temp = temp->next;
    }
 }