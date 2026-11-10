class WordDictionary {
public:
    struct Node {
        Node* links[26];
        bool flag = false;

        Node() {
            for(int i = 0; i < 26; i++)
                links[i] = NULL;
        }
    };

    Node* root;

    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* node = root;

        for(char ch : word) {
            int idx = ch - 'a';

            if(node->links[idx] == NULL)
                node->links[idx] = new Node();

            node = node->links[idx];
        }

        node->flag = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(string& word, int i, Node* node) {

        if(i == word.size())
            return node->flag;

        char ch = word[i];

        if(ch != '.') {
            int idx = ch - 'a';

            if(node->links[idx] == NULL)
                return false;

            return dfs(word, i + 1, node->links[idx]);
        }

        for(int j = 0; j < 26; j++) {
            if(node->links[j] != NULL) {
                if(dfs(word, i + 1, node->links[j]))
                    return true;
            }
        }

        return false;
    }
};