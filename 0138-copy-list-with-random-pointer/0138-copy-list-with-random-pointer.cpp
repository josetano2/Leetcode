
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(!head){
            return NULL;
        }

        unordered_map<Node*, Node*> nodesMap;
        Node* newHead = new Node(head->val);
        Node* prev = newHead;
        nodesMap[head] = newHead;

        Node* curr = head->next;

        while(curr){
            Node* newNode = new Node(curr->val);
            nodesMap[curr] = newNode;
            prev->next = newNode;
            prev = prev->next;
            curr = curr->next;
        }

        curr = head;
        Node* newCurr = newHead;

        while(curr){
            if(curr->random){
                newCurr->random = nodesMap[curr->random];  
            }
            curr = curr->next;
            newCurr = newCurr->next;
        }

        
        return newHead;
    }
};


