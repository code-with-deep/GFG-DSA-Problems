/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  private:
    // Recursive helper function to add 1
    int addHelper(Node* temp) {
        if (temp == NULL) return 1; // carry = 1 (since we are adding 1 initially)
        
        int carry = addHelper(temp->next); // go to the last node
        temp->data += carry;
        
        if (temp->data < 10) return 0;  // no carry
        temp->data = 0;                 // reset and return carry
        return 1;
    }

  public:
    Node* addOne(Node* head) {
        int carry = addHelper(head);

        if (carry == 1) {
            Node* newNode = new Node(1); // create a new head
            newNode->next = head;
            head = newNode;
        }

        return head;
    }
};
