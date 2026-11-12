class Trie {
public:

    struct Node {
        Node* links[26];
        bool flag;

        Node() {
            for (int i = 0; i < 26; i++) {
                links[i] = NULL;
            }

            flag = false;
        }
    };

    Node* root;

    Trie() {
        root = new Node();
    }

    // Insert word
    void insert(string word) {

        Node* node = root;

        for (int i = 0; i < word.size(); i++) {

            int index = word[i] - 'a';

            if (node->links[index] == NULL) {
                node->links[index] = new Node();
            }

            node = node->links[index];
        }

        node->flag = true;
    }

    // Search complete word
    bool search(string word) {

        Node* node = root;

        for (int i = 0; i < word.size(); i++) {

            int index = word[i] - 'a';

            if (node->links[index] == NULL) {
                return false;
            }

            node = node->links[index];
        }

        return node->flag;
    }

    // Check prefix
    bool startsWith(string prefix) {

        Node* node = root;

        for (int i = 0; i < prefix.size(); i++) {

            int index = prefix[i] - 'a';

            if (node->links[index] == NULL) {
                return false;
            }

            node = node->links[index];
        }

        return true;
    }
};