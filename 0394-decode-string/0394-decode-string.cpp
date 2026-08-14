class Solution {
public:
    string decodeString(string s) {

        stack<string> my_stack;

        for(char ch : s) {

            if(ch != ']') {
                my_stack.push(string(1, ch));
            }

            else {

                string temp = "";

                while(my_stack.top() != "[") {
                    temp = my_stack.top() + temp;
                    my_stack.pop();
                }

                my_stack.pop();   // remove '['

                string num = "";

                while(!my_stack.empty() && isdigit(my_stack.top()[0])) {
                    num = my_stack.top() + num;
                    my_stack.pop();
                }

                int rep_num = stoi(num);

                string rep_str = "";

                while(rep_num) {
                    rep_str = rep_str + temp;
                    rep_num--;
                }

                my_stack.push(rep_str);
            }
        }

        string final_ans = "";

        while(!my_stack.empty()) {
            final_ans = my_stack.top() + final_ans;
            my_stack.pop();
        }

        return final_ans;
    }
};