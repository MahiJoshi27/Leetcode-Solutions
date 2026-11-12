class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for(int x : asteroids) {

            bool alive = true;

            while(!st.empty() && st.top() > 0 && x < 0) {

                if(st.top() < -x) {
                    st.pop();
                }
                else if(st.top() == -x) {
                    st.pop();
                    alive = false;
                    break;
                }
                else {
                    alive = false;
                    break;
                }
            }

            if(alive) {
                st.push(x);
            }
        }

        vector<int> ans;

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};