/**
 * Description:
 *  斐波那契数列, 给出正整数n, 计算f(n)的值
 *
 * Input:
 *  一行 ,1 个正整数n
 *
 * Output:
 *  一行 , 输出f(n)
 *
 * Hints:
 *  1≤n≤4000, f(n)值不超过1000位
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
10
 *
 *  output:
55
 *
 *  2):
 *  input:
99
 *
 *  output:
218922995834555169026
 *
 */

#include <algorithm>
#include <cstdio>
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

int n, F[4005][1005];

int main()
{
    cin >> n;
    s2BIG("1", F[1]);
    s2BIG("1", F[2]);
    for (int i = 3; i <= n; i++) {
        addBIG(F[i - 1], F[i - 2], F[i]);
    }
    printBIG(F[n]);
    return 0;
}