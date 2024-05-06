/**
 * Description:
 *  一个数列 x1,x2,…,xk,⋯ 如下定义 :xk = axk-1 + bx-2,(k≥3)
 *  其中a,b是已知常数
 *  输入正整数a,b,x1,x2,n, 计算xn的值
 *
 * Input:
 *  一行,5个正整数a,b,x1,x2,n以空格分隔
 *
 * Output:
 *  xn的值
 *
 * Hints:
 *  1≤a,b≤999, 1≤x1,x2≤10<9>, 1≤n≤1000,保证输出不超过1000位
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4 1 1 1 6
 *
 *  output:
377
 *
 *  2):
 *  input:
1 1 1 1 99
 *
 *  output:
218922995834555169026
 *
 *  3):
 *  input:
5 2 101 3 50
 *
 *  output:
4236937698195997833754524403189216443
 *
 */

#include <algorithm>
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

string sx1, sx2;
int a, b, n, x[1010][1010], A[1010], B[1010];

int main()
{   
    cin >> a >> b >> sx1 >> sx2 >> n;
    s2BIG(sx1, x[1]);
    s2BIG(sx2, x[2]);
    for (int i = 3; i <= n; i++) {
        mulBIG(x[i - 1], a, A);
        mulBIG(x[i - 2], b, B);
        addBIG(A, B, x[i]);
    }
    printBIG(x[n]);
    return 0;
}