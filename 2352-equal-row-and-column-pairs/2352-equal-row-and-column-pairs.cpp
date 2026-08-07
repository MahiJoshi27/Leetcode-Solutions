class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int>my_map;
        int n=grid.size();
        for(int i=0; i<n;i++){
            my_map[grid[i]]++;
        }
        int pair_cnt=0;
        for(int i=0;i<n;i++){
            vector<int >cur_col;
            for(int j=0;j<n;j++){
                cur_col.push_back(grid[j][i]);
            }
            if(my_map.find(cur_col)!=my_map.end())pair_cnt+=my_map[cur_col];
        }
        return pair_cnt;
    }
};