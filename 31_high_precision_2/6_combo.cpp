/**
 * Description:
 *  计算C<m, n>组合
 *
 * Input:
 *  一行,2个正整数n,m以空格分隔
 *
 * Output:
 *  输出C<m, n>组合数的值
 *
 * Hints:
 *  0≤m≤n≤200,保证输出不超过1000位
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5 3
 *
 *  output:
10
 *
 *  2):
 *  input:
99 37
 *
 *  output:
2154618614921181030658724688
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

// 高精*单精
void mulBIG(int a[], int b, int c[])
{
    int lenc = a[0], u = 0;
    for (int i = 1; i <= lenc; i++) {
        int t = a[i] * b + u;
        c[i] = t % 10;
        u = t / 10;
    }
    while (u > 0) {
        c[++lenc] = u % 10;
        u /= 10;
    }
    c[0] = lenc;
}

// 高精/单精
void divBIG(int a[], int b, int c[])
{
    int lenc = a[0], r = 0;
    for (int i = lenc; i >= 1; i--) {
        int t = r * 10 + a[i];
        c[i] = t / b;
        r = t % b;
    }
    while (c[lenc] == 0 && lenc > 1) {
        lenc--;
    }
    c[0] = lenc;
}

int n, m, x[1010];

int main()
{
    cin >> n >> m;
    s2BIG("1", x);
    for (int i = m + 1; i <= n; i++) {
        mulBIG(x, i, x);
    }
    for (int i = 1; i <= n - m; i++) {
        divBIG(x, i, x);
    }
    printBIG(x);
    return 0;
}