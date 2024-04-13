/**
 * Description:
 *  输入一个整数矩阵，计算位于矩阵边缘的元素之和。所谓矩阵边缘的元素，就是第一行和最后一行的元素以及第一列和最后一列的元素。
 *
 * Input:
 *  第一行分别为矩阵的行数n和列数m（1 < n,m < 100），两者之间以一个空格分开。
 *  接下来输入的n行数据中，每行包含m个整数，整数之间以一个空格分开。(0 <= 整数 <= 100)
 *
 * Output:
 *  输出对应矩阵的边缘元素和
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 3
3 4 1
3 7 1
2 0 1
 *
 *  output:
15
 *
 */

#include <iostream>
using namespace std;
int n, m, a[110][110];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 || j == 1 || i == n || j == m) {
                sum += a[i][j];
            }
        }
    }
    cout << sum << endl;
    return 0;
}