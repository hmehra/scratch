#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        char c;
        for (int i = 0; i < s.size(); i++) {
            switch(s[i]) {
            case '(':
                brackets.push(s[i]);
                break;
            case '{':
                brackets.push(s[i]);
                break;
            case '[':
                brackets.push(s[i]);
                break;
            case ')':
                if (brackets.empty()) {
                    return false;
                } else {
                    c = brackets.top();
                    if (c != '(') {
                        return false;
                    }
                    brackets.pop();
                }
                break;
            case ']':
                if (brackets.empty()) {
                    return false;
                } else {
                    c = brackets.top();
                    if (c != '[') {
                        return false;
                    }
                    brackets.pop();
                }
                break;
            case '}':
                if (brackets.empty()) {
                    return false;
                } else {
                    c = brackets.top();
                    if (c != '{') {
                        return false;
                    }
                    brackets.pop();
                }
                break;
            default:
                return false;
                break;
            }
        }

        if (brackets.size() == 0) {
            return true;
        }

        return false;
    }
};


int main()
{
    Solution S;
    cout << "}" << "\t" << S.isValid("}") << endl;
    cout << "(" << "\t" << S.isValid("(") << endl;
    cout << "()}" << "\t" << S.isValid("()}") << endl;
    cout << "()" << "\t" << S.isValid("()") << endl;
    cout << "{}" << "\t" << S.isValid("{}") << endl;
    cout << "[]" << "\t" << S.isValid("[]") << endl;
    cout << "(}" << "\t" << S.isValid("(}") << endl;
    cout << "()()()" << "\t" << S.isValid("()()()") << endl;
    cout << "{}()[]" << "\t" << S.isValid("{}()[]") << endl;
    cout << "([)]" << "\t" << S.isValid("([)]") << endl;
}
