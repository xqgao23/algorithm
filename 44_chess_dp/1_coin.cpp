/**
 * Description:
 *  小猴进入了一个由n×m个格子组成的地区，每个格子都可以走。 第i行第j列的格子里有vi,j个金币。 小猴从地图的左上角（第1行第1列）出发，每次只能向下走或向右走，并且收集路上经过的格子的金币。（起点和终点也算经过的格子）
 *  问小猴到达右下角（第n行第m列）时，最多能收集到多少金币？
 *
 * Input:
 *  第1行，两个正整数n,m
 *  接下来n行，每行m个整数，表示每个格子内的金币数量。
 *
 * Output:
 *  输出一个整数，小猴最多能收集到的金币数量。
 *
 * Hints:
 *  1≤n,m≤1000, 0≤vi,j≤1000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
2 3
1 2 10
3 4 6

 *
 *  output:
19
 *
 */

#include <iostream>
using namespace std;
int n, m, v, f[1010][1010];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v;
            f[i][j] = max(f[i - 1][j], f[i][j - 1]) + v;
        }
    }
    cout << f[n][m] << endl;
    return 0;
}