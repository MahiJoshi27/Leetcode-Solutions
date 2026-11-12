class WordDictionary {
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

    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
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

    bool dfs(string word, int index, Node* node) {

        if (node == NULL) {
            return false;
        }

        if (index == word.size()) {
            return node->flag;
        }

        char ch = word[index];

        if (ch == '.') {

            for (int i = 0; i < 26; i++) {

                if (node->links[i] != NULL) {
                    if (dfs(word, index + 1, node->links[i])) {
                        return true;
                    }
                }
            }

            return false;
        }

        int pos = ch - 'a';

        if (node->links[pos] == NULL) {
            return false;
        }

        return dfs(word, index + 1, node->links[pos]);
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};