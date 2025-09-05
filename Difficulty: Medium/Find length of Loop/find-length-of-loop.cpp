/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return Findlength(slow);
            }
        }
        return 0;
    }

  private:
    int Findlength(Node* node) {
        int cnt = 1;
        Node* temp = node->next;

        while (temp != node) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
};
