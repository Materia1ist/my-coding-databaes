#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct BigInteger {
    string num;

    BigInteger() : num("0") {}
    BigInteger(string s) : num(s) {}

    bool operator<(const BigInteger& other) const {
        if (num.size() != other.num.size()) {
            return num.size() < other.num.size();
        }
        return num < other.num;
    }

    bool operator>(const BigInteger& other) const {
        return other < *this;
    }

    bool operator<=(const BigInteger& other) const {
        return !(other < *this);
    }

    bool operator>=(const BigInteger& other) const {
        return !(*this < other);
    }

    BigInteger operator+(const BigInteger& other) const {
        string a = num, b = other.num;
        if (a.size() < b.size()) swap(a, b);

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int carry = 0;
        string result;
        for (size_t i = 0; i < a.size(); ++i) {
            int sum = (i < b.size() ? (a[i] - '0') + (b[i] - '0') : (a[i] - '0')) + carry;
            result.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        if (carry) result.push_back(carry + '0');
        reverse(result.begin(), result.end());
        return BigInteger(result);
    }

    BigInteger operator*(const BigInteger& other) const {
        string a = num, b = other.num;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string result(a.size() + b.size(), '0');

        for (size_t i = 0; i < a.size(); ++i) {
            int carry = 0;
            for (size_t j = 0; j < b.size() || carry; ++j) {
                int sum = result[i + j] - '0' + (a[i] - '0') * (j < b.size() ? (b[j] - '0') : 0) + carry;
                carry = sum / 10;
                result[i + j] = sum % 10 + '0';
            }
        }

        while (result.size() > 1 && result.back() == '0') result.pop_back();
        reverse(result.begin(), result.end());
        return BigInteger(result);
    }

    BigInteger operator%(const BigInteger& other) const {
        BigInteger dividend = *this;
        BigInteger divisor = other;

        while (dividend >= divisor) {
            BigInteger multiple = divisor;
            BigInteger count("1");

            while (multiple * BigInteger("2") <= dividend) {
                multiple = multiple * BigInteger("2");
                count = count * BigInteger("2");
            }

            dividend = dividend - multiple;
        }

        return dividend;
    }

    friend ostream& operator<<(ostream& os, const BigInteger& bi) {
        os << bi.num;
        return os;
    }
};

BigInteger readBigInt() {
    string s;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
        s.push_back(c), c = getchar();
    return BigInteger(s);
}

void printBigInt(BigInteger n) {
    string s = n.num;
    for (char c : s) putchar(c);
}

const BigInteger MOD("1000000007");

int main() {
    freopen("test_data.txt", "r", stdin);
    BigInteger n, m, k, x, y, ans("0");
    n = readBigInt();
    m = readBigInt();
    k = readBigInt();
    x = readBigInt();
    y = readBigInt();

    BigInteger tx, ty;
    for (BigInteger i("1"); i <= k; i = i + BigInteger("1")) {
        tx = readBigInt();
        ty = readBigInt();
        if (tx != x && ty != y) {
            if (tx < x) {
                ans = ans + tx;
            } else {
                ans = ans + (n - tx + BigInteger("1"));
            }
            if (ty < y) {
                ans = ans + ty;
            } else {
                ans = ans + (m - ty + BigInteger("1"));
            }
        }
        if (tx != x && ty == y) {
            if (tx > x) {
                ans = ans + (n - tx + BigInteger("1")) * (n + m + tx - BigInteger("4"));
            } else {
                ans = ans + tx * (n + m + n - tx - BigInteger("3"));
            }
        }
        if (ty != y && tx == x) {
            if (ty > y) {
                ans = ans + (m - ty + BigInteger("1")) * (m + n + ty - BigInteger("4"));
            } else {
                ans = ans + ty * (m + n + m - ty - BigInteger("3"));
            }
        }
    }
    ans = ans % MOD;
    printBigInt(ans);
}
