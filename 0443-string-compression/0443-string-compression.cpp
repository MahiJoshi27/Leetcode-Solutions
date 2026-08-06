class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int r=0, w=0 ;
        while(r<n){
            char ch = chars[r];
            int cnt=0;
            while(r<n && chars[r]==ch){
                cnt++ , r++;
            }
            chars[w]=ch;
            w++;
            if(cnt>1){
                string temp= to_string(cnt);
                for(char c:temp){
                    chars[w]=c;
                    w++;
                }
            }
        }
        return w;
    }
};