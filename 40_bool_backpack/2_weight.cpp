/**
 * Description:
 *  设有 1g 、 2g 、 3g 、 5g 、 10g 、 20g 的砝码各若干枚（其总重 <= 1000 ）
 *
 * Input:
 *  输入方式：a1,a2,a3,a4,a5,a6
 *  表示 1g 砝码有ai个， 2g 砝码有a2个， ··· ， 20g 砝码有a6个
 *
 * Output:
 *  输出一个正整数N, 表示用这些砝码能称出的不同重量的个数，但不包括一个砝码也不用的情况
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
1 1 0 0 0 0
 *
 *  output:
3
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n, w[1010], f[1010][1010], c[] = {0, 1, 2, 3, 5, 10, 20}; // f[i][j] 表示前i个砝码能否恰好装满j

int main()
{
    for (int i = 1; i <= 6; i++) {
        int a;
        cin >> a;
        for (int j = 1; j <= a; j++) {
            w[++n] = c[i];
        }
    }
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 1000; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= w[i]) {
                f[i][j] |= f[i - 1][j - w[i]];
            }
        }
    }
    int ans = 0;
    for (int j = 1; j <= 1000; j++) {
        if (f[n][j]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}