/**
 * Description:
 *  输入整数n, 计算n的阶乘
 *  n!=1×2×3×⋯×n
 *  规定0的阶乘等于1
 *
 * Input:
 *  一个整数n
 *
 * Output:
 *  输出n的阶乘
 *
 * Hints:
 *  0≤n≤200,保证输出不超过1000位
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
50
 *
 *  output:
30414093201713378043612608166064768844377641568960512000000000000
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
    while (u > 0) {
        c[++lenc] = u % 10;
        u /= 10;
    }
    c[0] = lenc;
}

string sa;
int n, f[210][1010];

int main()
{
    cin >> n;
    s2BIG("1", f[0]);
    for (int i = 1; i <= n; i++) {
        mulBIG(f[i - 1], i, f[i]);
    }
    printBIG(f[n]);
    return 0;
}