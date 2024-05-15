/**
 * Description:
 *  帅帅经常跟同学玩一个矩阵取数游戏：对于一个给定的 n×m 的矩阵，矩阵中的每个元素 ai,j 均为非负整数。游戏规则如下：
 *  	1.	每次取数时须从每行各取走一个元素，共n 个。经过 m 次后取完矩阵内所有元素；
 *  	2.	每次取走的各个元素只能是该元素所在行的行首或行尾；
 *  	3.	每次取数都有一个得分值，为每行取数的得分之和，每行取数的得分 = 被取走的元素值 ×2<i>，其中 i 表示第 i 次取数（从 1 开始编号）；
 *  	4.	游戏结束总得分为 m 次取数得分之和。
 *  帅帅想请你帮忙写一个程序，对于任意矩阵，可以求出取数后的最大得分。
 *
 * Input:
 *  输入包括 n+1 行：
 *  第一行为两个用空格隔开的整数 n 和 m。
 *  第 2∽n+1 行为 n×m 矩阵，其中每行有 m 个用单个空格隔开的非负整数。
 *
 * Output:
 *  输出仅包含1行，为一个整数，即输入矩阵取数后的最大得分。
 *
 * Hints:
 *  1≤n,m≤80, 0≤ai,j≤1000,
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
2 3
1 2 3
3 4 2
 *
 *  output:
82
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

int operator%(BIG a, int b)
{
    // return a.num[1] % 2;
    int r = 0;
    for (int i = a.len; i >= 1; i--) {
        r = r * 10 + a.num[i];
        r %= b;
    }
    return r;
}

int n, m, a[85][85];
BIG f[85][85], ans, p[85];

void cal()
{
    p[0].s2BIG("1");
    for (int i = 1; i <= m; i++) {
        p[i] = p[i - 1] * 2;
    }
}

BIG getv(int a[])
{
    memset(f, 0, sizeof f);
    for (int i = 1; i <= m; i++) {
        f[i][i] = f[i][i] + p[m] * a[i];
    }
    for (int l = 2; l <= m; l++) {
        for (int i = 1; i + l - 1 <= m; i++) {
            int j = i + l - 1;
            f[i][j] = max(f[i][j], f[i + 1][j] + p[m - l + 1] * a[i]);
            f[i][j] = max(f[i][j], f[i][j - 1] + p[m - l + 1] * a[j]);
        }
    }
    return f[1][m];
}

int main()
{
    cin >> n >> m;
    for (int i = 1;
         i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    cal();
    ans.s2BIG("0");
    for (int i = 1; i <= n; i++) {
        ans = ans + getv(a[i]);
    }
    ans.print();
    return 0;
}