/**
 * Description:
 *  小猴进入了一个由n×m个格子组成的地区，每个格子都可以走。 第i行第j列的格子写着一个数vi,j 。 小猴从地图的左上角（第1行第1列）出发，每次只能向：正下、正右、右上、右下这四个方向走一步。
 *  问小猴到达右下角（第n行第m列）时，他经过的格子中的数总和最大是多少？
 *
 * Input:
 *  第一行两个整数n,m(1≤n,m≤1000)
 *  接下来n行，每行m个整数，表示每个格子里的数。
 *
 * Output:
 *  一个整数，小猴他经过的格子中的数的最大总和
 *
 * Hints:
 *  1≤n,m≤1000, -1000≤vi,j≤1000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4 4
1 1 9 10
2 5 -99 11
5 -10 99 2
-50 4 6 8
 *
 *  output:
133
 *
 */

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n, m, v[1010][1010], f[1010][1010];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }
    memset(f, -0x3f, sizeof f);
    f[0][0] = 0;
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            f[i][j] = max(max(f[i - 1][j], f[i][j - 1]), max(f[i - 1][j - 1], f[i + 1][j - 1])) + v[i][j];
        }
    }
    cout << f[n][m] << endl;
    return 0;
}