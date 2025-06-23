/*

Reference - https://www.youtube.com/watch?v=mQeF6bN8hMk

[[hash table]]
[[depth first search]]
[[breadth first search]]
[[graph]]

#referbackpro
*/

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
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> map;

        if (node == NULL) return NULL;
        if (node->neighbors.size() == 0){
            Node* clone = new Node(node->val);
            return clone;
        }

        return dfs(node, map);
    }

    Node* dfs(Node* current, unordered_map<Node*, Node*> &map){
        vector<Node*> neighbor;
        Node* clone = new Node(current->val);

        map[current] = clone;

        for (auto i:current->neighbors){
            if (map.find(i) != map.end()) neighbor.push_back(map[i]);
            else neighbor.push_back(dfs(i, map));
        }

        clone->neighbors = neighbor;
        return clone;
    }
};
