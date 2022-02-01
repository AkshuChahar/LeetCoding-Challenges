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
    ListNode* root; // There is always going to be atleast one node.

    Solution(ListNode* head) {
        root = head;
    }

/*
One way to solve this question is to just copy all values in an array and then randomly display any value. But the Space Complexity will be O(n).

To provide a solution to the follow-up question. i.e., solve using constant space, we use the Reservoir Sampling Method.

RESERVOIR SAMPLING METHOD:
- When we read the first node head, if the stream ListNode stops here, we can just return the head->val. The probability of picking here is 1/1.
- When we goto second node we can decide if we replace the result r or not. The possibility is 1/2. So now we need to genereate a random 
number between 0 & 1 and if it is equals to 1 replace r with the current node else we don't traumantize r, so it's value is till the value of head.
- Now let's goto third node and we can decide if we can replace the result r or not. The probability of picking the third node will be 1/3
and not picking up will be 2/3. So now we generate a random number between 0-to-2 if the result is 2 then we replace r with the value of indexed node 2.
- We need to continue this till the end of list node.
- To conclude, if we have n different balls than the equal probability of picking any one of them will be 1/n.
*/

    int getRandom() {
        int ans, n = 1;         // Initialise 'ans' (to store the recent random node) and 'n' (to calculate the length).
        ListNode* ln = root;
        while (ln) {            // Iterate the whole linked list
            if (rand() % n == 0) // Check if we should choose the current node or not. Update the value of 'ans' if the probability comes out to be 1.
                ans = ln->val;
            n++;                // Update length.
            ln = ln->next;      // Update node.
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */