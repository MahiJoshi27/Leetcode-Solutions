class Solution {
public:
    int maxDepth(string s) {
        int openBracket=0;
        int result=0;
        int n = s.size();

        for(int i=0 ; i<s.size(); i++){
            char ch= s[i];
            if(ch == '('){
                openBracket++;
            }
            else if(ch ==')'){
                openBracket--;
            }
            result = max(result, openBracket);
        }
        return result;
    }
};