/**
 * Description:
 *  给你一个序列a1,a2,…,an，这个序列会有很多上升子序列。 你要求出所有上升子序列中，和最大的一个，输出最大的和。
 *  （只有一个数的子序列，也认为是上升子序列）
 *
 * Input:
 *  第 1 行, 1 个整数N
 *  第 2 行, N个整数a1,a2,...,an
 *
 * Output:
 *  一个整数，最大的上升子序列和
 *
 * Hints:
 *  1≤n≤1000；1≤ai≤10<9>；
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
6
8 1 2 3 9 4
 *
 *  output:
17
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n, a[1010];
long long f[1010], ans;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        f[i] = a[i];
        for (int j = 1; j < i; j++) {
            if (a[i] > a[j]) {
                f[i] = max(f[i], f[j] + a[i]);
            }
        }
        ans = max(ans, f[i]);
    }
    cout << ans << endl;
    return 0;
}