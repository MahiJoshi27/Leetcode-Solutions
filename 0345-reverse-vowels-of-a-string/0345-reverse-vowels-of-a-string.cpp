class Solution {
public:
    string reverseVowels(string s) {

        int i = 0;
        int j = s.length() - 1;

        while(i < j) {

            if(!isVowel(s[i])) {
                i++;
            }
            else if(!isVowel(s[j])) {
                j--;
            }
            else {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }

        return s;
    }

    bool isVowel(char ch) {
        ch = tolower(ch);

        return ch == 'a' || ch == 'e' ||
               ch == 'i' || ch == 'o' ||
               ch == 'u';
    }
};