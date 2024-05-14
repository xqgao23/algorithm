/**
 * Description:
 *  有一个H行W列的棋盘第i行第j列的棋盘格记为(i,j)。每个格子中都写了两个数，(i,j)中写有整数Aij和Bij。
 *  高桥君首先对每个格子里的两个数染色：一个涂成红色，另一个涂成蓝色。
 *  染色完成后，高桥君从左上角(1,1)出发，每次可以向右或向下走一格，直到到达右下角(H,W)。途中经过的所有格子（包括起点和终点）中红色数字之和记为R，蓝色数字之和记为B。
 *  通过适当的染色以及选取合适的路径，高桥君想要R和B之差的绝对值尽可能的小。问∣R−B∣的最小值是多少？
 *
 * Input:
 *  输入共2H+1行
 *  第1行，两个正整数H,W
 *  第2到H+1行，每行W个整数，第i+1行第j个数为Aij
 *  第H+2到2H+1行，每行W个整数，第i+H+1行第j个数为Bij
 *
 * Output:
 *  输出∣R−B∣的最小值
 *
 * Hints:
 *  2≤H,W≤80, 0≤Aij, Bij≤80,
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
2 2
1 2
3 4
3 4
2 1
 *
 *  output:
0
 *
 *  2):
 *  input:
2 3
1 10 80
80 10 1
1 2 3
4 5 6
 *
 *  output:
2
 *
 */

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int D = 80 * 80 * 2;
int n, m, a[85][85], b[85][85], M;
bool f[85][85][2 * D + 10];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> b[i][j];
            M = max(M, abs(a[i][j] - b[i][j]));
        }
    }
    f[0][1][D] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int d = a[i][j] - b[i][j];
            for (int k = D - (i + j - 1) * M; k <= (i + j - 1) * M + D; k++) {
                if (k + d <= 2 * D) {
                    f[i][j][k] |= f[i - 1][j][k + d];
                }
                if (k - d >= 0) {
                    f[i][j][k] |= f[i - 1][j][k - d];
                }
                if (k + d <= 2 * D) {
                    f[i][j][k] |= f[i][j - 1][k + d];
                }
                if (k - d >= 0) {
                    f[i][j][k] |= f[i][j - 1][k - d];
                }
            }
        }
    }
    for (int k = 0; k <= D; k++) {
        if (f[n][m][k + D] || f[n][m][-k + D]) {
            cout << k << endl;
            break;
        }
    }
    return 0;
}