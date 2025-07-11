/*

This was the implementation of the trie data structure basically. Interesting, and surprisingly easy once you get the hang of it.

Reference - https://www.youtube.com/watch?v=oobqoCJlHA0

[[hash table]]
[[string]]
[[design]]
[[[trie]]]

#referback
*/

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool end_of_word;

    TrieNode() {
        end_of_word = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* current = root;

        for (int i = 0; i < word.length(); i++) {
            if (!current->children.count(word[i])) {
                current->children[word[i]] = new TrieNode();
            }
            current = current->children[word[i]];
        }
        current->end_of_word = true;
    }

    bool search(string word) {
        TrieNode* current = root;

        for (int i = 0; i < word.length(); i++) {
            if (!current->children.count(word[i])) {
                return false;
            }
            current = current->children[word[i]];
        }
        return current->end_of_word;
    }

    bool startsWith(string prefix) {
        TrieNode* current = root;

        for (int i = 0; i < prefix.length(); i++) {
            if (!current->children.count(prefix[i])) {
                return false;
            }
            current = current->children[prefix[i]];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
