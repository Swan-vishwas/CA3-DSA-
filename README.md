# CA3-DSA-
LeetCode solutions for CA3.

## Valid Parentheses

`ValidParentheses.cpp` contains a stack-based solution to the [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) problem.

### Approach

Scan the string from left to right. Push each opening bracket onto a stack. For a closing bracket, check that the stack is non-empty and that its top contains the matching opening bracket; otherwise, return `false`. Any character that is not one of the six bracket characters is rejected. At the end, the string is valid only if the stack is empty, which ensures every opening bracket was closed.

### Complexity

- Time: **O(n)**, where `n` is the length of the string.
- Space: **O(n)** in the worst case, when all characters are opening brackets.
