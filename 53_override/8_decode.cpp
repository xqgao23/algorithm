/**
 * Description:
 *  皮皮有一个藏着宝物的箱子，为了让人无法打开这个箱子，他给箱子的密码锁进行了复杂的加密。加密会使用 +,−,×,÷ 四种运算，经过复杂的加密之后他终于得到了加密之后的数字，但是他却忘记了原本的密码是什么？唯一值得庆幸的是他记录下来了加密的操作的整个操作序列，请你帮他还原最初的密码。
 *
 * Input:
 *  输入共 n+1 行：
 *  第 1 行，2 个正整数 n，num，分别表示操作次数和最终的密码数字；
 *  接下来 n 行，每行 2 个数据，操作符 op 和 操作数 x。
 *  例如：当 op= '+' 时，表示将当前数加上 x。
 *
 * Output:
 *  还原之后的密码。
 *
 * Hints:
 *  1≤n≤100, 1≤x,num≤10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 292
* 2
/ 3
/ 3
 *
 *  output:
1314
 *
 *  2):
 *  input:
4 13
/ 6
+ 1
* 4
- 3
 *
 *  output:
18
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

int n, num, x[110];
char op[110];
BIG ans, t;

int main()
{
    cin >> n >> num;
    for (int i = 1; i <= n; i++) {
        cin >> op[i] >> x[i];
    }
    ans.s2BIG(to_string(num));
    for (int i = n; i >= 1; i--) {
        if (op[i] == '+') {
            t.s2BIG(to_string(x[i]));
            ans = ans - t;
        } else if (op[i] == '-') {
            t.s2BIG(to_string(x[i]));
            ans = ans + t;
        } else if (op[i] == '*') {
            ans = ans / x[i];
        } else {
            ans = ans * x[i];
        }
    }
    ans.print();
    return 0;
}