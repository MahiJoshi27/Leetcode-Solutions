class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> map;
        for(int i:arr){
            map[i]++;
        }
        unordered_set<int> my_set;
        for(auto & pair:map){
            if(my_set.find(pair.second)!=my_set.end()) return false;
            my_set.insert(pair.second);
        }
        return true;
    }
};