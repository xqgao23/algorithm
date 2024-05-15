/**
 * Description:
 *  输入两个正整数 a 和 b, 和一个字符表示运算种类, 计算a 和 b的运算结果并输出
 *
 * Input:
 *  第一行 , 一个字符, 表示运算符
 *  接下来两行 , 每行一个正整数 , 分别代表 a 和 b
 *
 * Output:
 *  一行 , 输出 a 和 b 的运算结果
 *  如果运算符为 '+', 输出 a+b;
 *  如果运算符为 '-', 输出 ∣a−b∣;
 *  如果运算符为 '*', 输出 a×b;
 *  如果运算符为 '/', 输出 a÷b。
 *
 * Hints:
 *  1≤a≤10<1000>,
 *  加减运算: 1≤b≤10<1000>
 *  乘除运算: 1≤b≤10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
+
999999999999999999999999
1
 *
 *  output:
1000000000000000000000000
 *
 *  2):
 *  input:
-
123456789123456789123456789
123456789123456790000000000
 *
 *  output:
876543211
 *
 *  3):
 *  input:
*
36792990267276763916015625
33554432
 *
 *  output:
1234567890000000000000000000000000
 *
 *  4):
 *  input:
/
1634254846899862270311363684648
112233
 *
 *  output:
14561268494113694459841256
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
struct BIG {
    int len, num[1010];
    void s2BIG(string s)
    {
        len = s.size();
        for (int i = 1; i <= len; i++) {
            num[i] = s[len - i] - '0';
        }
    }
    void print()
    {
        for (int i = len; i >= 1; i--) {
            cout << num[i];
        }
        cout << endl;
    }
};

BIG operator+(BIG a, BIG b)
{
    BIG c;
    int len = max(a.len, b.len), u = 0;
    for (int i = 1; i <= len; i++) {
        int t = u;
        if (i <= a.len) {
            t += a.num[i];
        }
        if (i <= b.len) {
            t += b.num[i];
        }
        c.num[i] = t % 10;
        u = t / 10;
    }
    if (u > 0) {
        c.num[++len] = u;
    }
    c.len = len;
    return c;
}

BIG operator-(BIG a, BIG b)
{
    BIG c;
    int len = max(a.len, b.len), u = 0;
    for (int i = 1; i <= len; i++) {
        int t = a.num[i] - u;
        if (i <= b.len) {
            t -= b.num[i];
        }
        if (t < 0) {
            u = 1;
            c.num[i] = t + 10;
        } else {
            u = 0;
            c.num[i] = t;
        }
    }
    while (c.num[len] == 0 && len > 1) {
        len--;
    }
    c.len = len;
    return c;
}

bool operator<(BIG a, BIG b)
{
    if (a.len != b.len) {
        return a.len < b.len;
    }
    for (int i = a.len; i >= 1; i--) {
        if (a.num[i] != b.num[i]) {
            return a.num[i] < b.num[i];
        }
    }
    return false;
}

BIG operator*(BIG a, int b)
{
    BIG c;
    int len = a.len, u = 0;
    for (int i = 1; i <= len; i++) {
        int t = a.num[i] * b + u;
        c.num[i] = t % 10;
        u = t / 10;
    }
    while (u > 0) {
        c.num[++len] = u % 10;
        u /= 10;
    }
    c.len = len;
    return c;
}

BIG operator/(BIG a, int b)
{
    BIG c;
    int len = a.len;
    int r = 0;
    for (int i = len; i >= 1; i--) {
        int t = r * 10 + a.num[i];
        c.num[i] = t / b;
        r = t % b;
    }
    while (c.num[len] == 0 && len > 1) {
        len--;
    }
    c.len = len;
    return c;
}

string sa, sb, op;
BIG a, b, c;
int d;

int main()
{
    cin >> op >> sa;
    a.s2BIG(sa);
    if (op == "+") {
        cin >> sb;
        b.s2BIG(sb);
        c = a + b;
    }
    if (op == "-") {
        cin >> sb;
        b.s2BIG(sb);
        if (a < b) {
            c = b - a;
        } else {
            c = a - b;
        }
    }
    if (op == "*") {
        cin >> d;
        c = a * d;
    }
    if (op == "/") {
        cin >> d;
        c = a / d;
    }
    c.print();
    return 0;
}