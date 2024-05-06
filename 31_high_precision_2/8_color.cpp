/**
 * Description:
 *  有排成一列的N个球. 现在想要把这些球都涂成K种颜色中的某一种.
 * 若要求任意相邻两个球颜色不同, 共有多少种不同的涂色方法?
 *
 * Input:
 *  一行，两个整数N，K.
 *
 * Output:
 *  一行, 一个整数代表涂色方法数.
 *
 * Hints:
 *  1≤N≤1000, 2≤K≤1000, 保证输出不超过1000位
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
10 8
 *
 *  output:
322828856
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

// 高精*单精
void mulBIG(int a[], int b, int c[])
{
    int lenc = a[0], u = 0;
    for (int i = 1; i <= lenc; i++) {
        int t = a[i] * b + u;
        c[i] = t % 10;
        u = t / 10;
    }
    while (u > 0 && lenc <= 500) {
        c[++lenc] = u % 10;
        u /= 10;
    }
    c[0] = lenc;
}

int n, k, x[3010];

int main()
{
    cin >> n >> k;
    s2BIG(to_string(k), x);
    for (int i = 1; i <= n - 1; i++) {
        mulBIG(x, k - 1, x);
    }
    printBIG(x);
    return 0;
}