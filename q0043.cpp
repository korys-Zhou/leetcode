class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        int len = num2.length();
        for (int i = len - 1; i >= 0; --i) {
            string temp = multiply_single(num1, num2[i] - '0', len - 1 - i);
            res = add(res, temp);
        }
        return res;
    }

private:
    string add(string num1, string num2) {
        string res;
        int carry = 0;
        for (int i = num1.length() - 1, j = num2.length() - 1; i >= 0 || j >= 0 || carry > 0; --i, --j) {
            if (i >= 0) carry += num1[i] - '0';
            if (j >= 0) carry += num2[j] - '0';
            res.push_back(carry % 10 + '0');
            carry /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    string multiply_single(string num, int f, int zeros) {
        if (num == "0" || f == 0) return "0";
        string res;
        int carry = 0;
        for (int i = num.length() - 1; i >= 0 || carry > 0; --i) {
            if (i >= 0) carry += (num[i] - '0') * f;
            res.push_back(carry % 10 + '0');
            carry /= 10;
        }
        reverse(res.begin(), res.end());
        for (int i = 0; i < zeros; ++i) res.push_back('0');
        return res;
    }
};