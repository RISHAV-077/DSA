/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //mwthod 2 using maps
        unordered_map<Node*  , Node*>mpp;
        Node*curr = head;
        Node* prev = NULL;
        Node* newhead =NULL;

        while(curr){
            Node* temp = new Node(curr->val);
            mpp[curr] = temp;
            if(newhead ==NULL){
                newhead = temp;
                prev = newhead;
            }
            else{
                prev->next = temp;
                prev = temp;

            }
             curr= curr->next;
        }
        //filling the random variable
        curr= head;
        Node* newcurr = newhead;
        while(curr){
            if(curr->random == NULL) newcurr->random = NULL;
            else{
                newcurr->random = mpp[curr->random];
            }


            curr= curr->next;
            newcurr = newcurr->next;

        }
        return newhead;
    }
};