class TrieNode {
public:
    TrieNode* links[26];
    bool isEnd;

    TrieNode() {
        for(int i = 0; i < 26; i++)
            links[i] = NULL;

        isEnd = false;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();

    void insert(string word) {
        TrieNode* node = root;

        for(char ch : word) {
            int idx = ch - 'a';

            if(node->links[idx] == NULL)
                node->links[idx] = new TrieNode();

            node = node->links[idx];
        }

        node->isEnd = true;
    }

    string searchRoot(string word) {
        TrieNode* node = root;
        string ans = "";

        for(char ch : word) {
            int idx = ch - 'a';

            if(node->links[idx] == NULL)
                return word;

            ans += ch;
            node = node->links[idx];

            if(node->isEnd)
                return ans;
        }

        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        for(string word : dictionary)
            insert(word);

        stringstream ss(sentence);
        string word, ans = "";

        while(ss >> word) {
            if(ans != "")
                ans += " ";

            ans += searchRoot(word);
        }

        return ans;
    }
};