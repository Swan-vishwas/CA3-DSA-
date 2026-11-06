#include <stack>
#include <string>

class Solution {
public:
    bool isValid(const std::string& s) {
        std::stack<char> openings;

        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                openings.push(ch);
                continue;
            }

            char expectedOpening;
            switch (ch) {
                case ')': expectedOpening = '('; break;
                case '}': expectedOpening = '{'; break;
                case ']': expectedOpening = '['; break;
                default: return false; // Reject characters outside the bracket set.
            }

            if (openings.empty() || openings.top() != expectedOpening) {
                return false;
            }
            openings.pop();
        }

        return openings.empty();
    }
};
