class Solution {
public:
    string solveEquation(string equation) {
        equation.push_back('+');
        int sum = 0, x = 0;
        string cur;
        bool tol = true;
        for (char& ch : equation) {
            if (ch == '+' || ch == '-' || ch == '=') {
                if (!cur.empty()) {
                    if (tol) sum += stoi(cur);
                    else sum -= stoi(cur);
                }
                cur = "";
                if (ch == '=') tol = false;
                else cur.push_back(ch);
            }
            else if (ch == 'x') {
                if (cur.empty() || cur.back() > '9' || cur.back() < '0') cur.push_back('1');
                if (tol) x += stoi(cur);
                else x -= stoi(cur);
                cur = "";
            }
            else cur.push_back(ch);
        }
        if (x == 0) {
            if (sum == 0) return "Infinite solutions";
            else return "No solution";
        }
        return "x=" + to_string(-sum / x);
    }
};