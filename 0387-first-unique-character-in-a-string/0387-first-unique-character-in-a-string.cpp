class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char , int > map;
        queue<int > Q;
        for(int i=0 ; i<s.size(); i++){
            if(map.find(s[i]) ==map.end()){
                Q.push(i);
            }
            map[s[i]]++;
            while(Q.size() > 0 && map[s[Q.front()]]>1){
                Q.pop();

                
            }
        }
        return Q.empty() ? -1 : Q.front();
    }
};