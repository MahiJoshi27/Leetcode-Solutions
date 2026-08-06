class Solution {
public:
    bool vowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    string reverseVowels(string s) {

        int left = 0;
        int right = s.size() - 1;

        while (left < right) {

            while (left < right && !vowel(s[left]))
                left++;

            while (left < right && !vowel(s[right]))
                right--;

            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};