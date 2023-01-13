/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> vis;
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
            
        Node* copy = new Node(node ->val);
        return makeClone(node, copy);
    }

    Node* makeClone(Node* node, Node* copy){
        Node *newNode;
        vis[node] = copy;
        vector<Node*> child;
        for(auto x: node -> neighbors){
            if(!vis[x]){
                newNode = new Node(x->val);
                child.push_back(newNode);
                makeClone(x, newNode);
            }
            else{
                child.push_back(vis[x]);
            }
        }
        copy -> neighbors = child;
        return copy;
    }
};