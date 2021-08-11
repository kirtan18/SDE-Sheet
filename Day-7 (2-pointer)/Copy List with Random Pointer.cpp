
https://leetcode.com/problems/copy-list-with-random-pointer/


///////////////////////////////////////////////////////////////////
BruteForce 
T.C = O(N)
S.C = O(N)  


class Solution {
public:
    unordered_map<Node*,Node*>m;
    Node* copyRandomList(Node* head) {
        if(!head)return NULL;
        
        if(m[head]) return m[head];
        m[head] = new Node(head->val);
        m[head]->next = copyRandomList(head->next);
        m[head]->random = copyRandomList(head->random);
        return m[head];
    }
};


//////////////////////////////////////////////////////////////////////

Optimal 
T.C = O(N) + O(N) + O(N) = O(N)
S.C = O(1)
  
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node*iter = head;
        Node*front = head;
        
        while(iter != NULL){
            Node* newNode = new Node(iter->val);
            newNode->next = iter->next;
            iter->next = newNode;
            iter = newNode->next;
        }
        
        iter = head;
        while(iter != NULL){
            if(iter->random != NULL){
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }
        
        iter = head;
        Node * pseudohead = new Node(0);
        Node * copy = pseudohead;
        
        while(iter != NULL){
            front = iter->next->next;
            copy->next = iter->next;
            iter->next = front;
            copy = copy->next;
            iter = front;
        }
        return pseudohead->next;
        
    }
};  

