class Solution {
public:
    vector<vector<string>> suggestedProducts(
        vector<string>& products, string searchWord) {

        sort(products.begin(), products.end());

        vector<vector<string>> ans;
        string prefix = "";

        for(char ch : searchWord) {
            prefix += ch;

            vector<string> temp;

            for(string s : products) {
                if(s.find(prefix) == 0) {
                    temp.push_back(s);
                }

                if(temp.size() == 3)
                    break;
            }

            ans.push_back(temp);
        }

        return ans;
    }
};