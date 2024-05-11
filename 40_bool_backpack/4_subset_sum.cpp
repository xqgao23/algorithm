/**
 * Description:
 *  对于 1∼n 的连续整数集合 , 能划分成两个数字和相等的子集 . 例如 n=3 时 ,{1,2,3} 能划分成 2 个子集 ,{3} 和 {1,2}, 并且这是唯一一种方法 .
 *  又例如 n=7, 有 4 种方法能划分集合 {1,2,3,4,5,6,7}:{1,6,7} 和 {2,3,4,5}{2,5,7} 和 {1,3,4,6}{3,4,7} 和 {1,2,5,6}{1,2,4,7} 和 {3,5,6}
 *  根据输入的 n, 输出划分子集的方案总数
 *
 * Input:
 *  一行 , 一个整数 n
 *
 * Output:
 *  划分方案数。
 *
 * Hints:
 *  1≤n≤39。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
7
 *
 *  output:
4
 *
 */

#include <iostream>
using namespace std;
long long n, f[45][800];
// f[i][j] 表示前i个数字恰好装满j的方案数

int main()
{
    cin >> n;
    int m = (1 + n) * n / 2;
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= i) {
                f[i][j] += f[i - 1][j - i];
            }
        }
    }
    if (m & 1) {
        cout << 0 << endl;
    } else {
        cout << f[n][m / 2] / 2 << endl;
    }
    return 0;
}