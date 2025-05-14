class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        pair<char,char> a= {'(',')'},b= {'[',']'},c= {'{','}'};
        char tmp;
        for(char cc:s){
            switch (cc){
                case ')':
                if(stack.empty() || stack.top() != a.first) return false;
                stack.pop();
                break;
                case ']':
                if(stack.empty() || stack.top() != b.first) return false;
                stack.pop();
                break;
                case '}':
                if(stack.empty() || stack.top() != c.first) return false;
                stack.pop();
                break;
                default: stack.push(cc);
            }
        }
        return stack.empty();
    }
};