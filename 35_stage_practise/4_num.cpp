/**
 * Description:
 *  求 n! 中某个数码出现的次数。
 *
 * Input:
 *  第 1 行，一个正整数 n(n≤1000) 和数码 a。
 *
 * Output:
 *  n! 中某个数码出现的次数。
 *
 * Hints:
 *  1≤n≤2*10<5>, 0≤k≤10<9>,1≤ai≤10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
8 4
 *
 *  output:
1
 *
 *  2):
 *  input:
50 0
 *
 *  output:
19
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

int n, f[1010][10010], x, ans;

int main()
{
    cin >> n >> x;
    s2BIG("1", f[0]);
    for (int i = 1; i <= n; i++) {
        mulBIG(f[i - 1], i, f[i]);
    }
    for (int i = 1; i <= f[n][0]; i++) {
        if (f[n][i] == x) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}