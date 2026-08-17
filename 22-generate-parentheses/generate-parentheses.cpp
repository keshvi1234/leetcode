class Solution {
public:
    vector<string> res;

    vector<string> generateParenthesis(int n) {
        helper("", 0, 0, n);
        return res;
    }

    void helper(string s, int open, int close, int n) {

        if (s.length() == n * 2) {
            res.push_back(s);
            return;
        }

        if (open < n)
            helper(s + "(", open + 1, close, n);

        if (close < open)
            helper(s + ")", open, close + 1, n);
    }
};