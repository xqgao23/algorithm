/**
 * Description:
 *  斐波那契数列,
 * 可以证明，对任何正整数 m，都存在一个斐波那契数的开头数字恰好和 m 相同。
 *  输入 m，输出第一个开头和 m 相同的斐波那契数。
 *
 * Input:
 *  一行,1个整数 m
 *
 * Output:
 *  一行, 第一个开头和m 相同的斐波那契数
 *
 * Hints:
 *  1≤m≤10<9>, 保证答案不超过1000位。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
10
 *
 *  output:
10946
 *
 */

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

void s2BIG(string s, int a[])
{ // 高精度输入
    int lena = s.size();
    for (int i = 1; i <= lena; i++) {
        a[i] = s[lena - i] - '0';
    }
    a[0] = lena;
}

void printBIG(int a[])
{ // 高精度输出
    int lena = a[0];
    for (int i = lena; i >= 1; i--) {
        cout << a[i];
    }
    cout << endl;
}

void addBIG(int a[], int b[], int c[])
{ // 高精+高精
    int lenc = max(a[0], b[0]), u = 0;
    for (int i = 1; i <= lenc; i++) {
        int t = u;
        if (i <= a[0]) {
            t += a[i];
        }
        if (i <= b[0]) {
            t += b[i];
        }
        c[i] = t % 10;
        u = t / 10;
    }
    if (u > 0) {
        c[++lenc] = u;
    }
    c[0] = lenc;
}

bool check(int a[], int b[])
{
    if (a[0] > b[0]) {
        return false;
    }
    for (int i = a[0], j = b[0]; i >= 1; i--, j--) {
        if (a[i] != b[j]) {
            return false;
        }
    }
    return true;
}

string sm;
int m[1010], f[5010][1010];

int main()
{
    cin >> sm;
    s2BIG(sm, m);
    s2BIG("1", f[1]);
    s2BIG("1", f[2]);
    int n = 2;
    while (!check(m, f[n])) {
        n++;
        addBIG(f[n - 1], f[n - 2], f[n]);
    }
    printBIG(f[n]);
    return 0;
}