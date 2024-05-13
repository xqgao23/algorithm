/**
 * Description:
 *  在一个n×m的只包含0和1的矩阵里找出一个不包含0的最大正方形，输出边长。
 *
 * Input:
 *  输入文件第一行为两个整数n,m(1≤n,m≤100)，接下来n行，每行m个数字，用空格隔开，0或1.
 *
 * Output:
 *  一个整数，最大正方形的边长
 *
 * Hints:
 *  1≤n,m≤1000, 0≤vi,j≤1000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4 4
0 1 1 1
1 1 1 0
0 1 1 0
1 1 0 1
 *
 *  output:
2
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n, m, a, ans, f[110][110]; // f[i][j] 表示以 (i,j) 为右下角的最 大正方形的边长

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a;
            if (a) {
                f[i][j] = min(min(f[i - 1][j - 1], f[i - 1][j]), f[i][j - 1]) + 1;
            }
            ans = max(ans, f[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}