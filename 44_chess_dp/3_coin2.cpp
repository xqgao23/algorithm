/**
 * Description:
 *  小猴进入了一个由n×n个格子组成的地区，每个格子都可以走。 第i行第j列的格子里有vi,j个金币。 小猴从地图的左上角（第1行第1列）出发，每次只能向下走或向右走，并且收集路上经过的格子的金币。（起点和终点也算经过的格子）
 *  每次经过一个格子时，小猴可以选择收集这个格子中的金币，并将金币全部装入钱袋（小猴不能只将部分金币装入钱袋）；也可以放弃这个格子中的金币。到达右下角（第n行第n列）时，钱袋中的金币数量必须是p的倍数，小猴才能带着金币离开这个地区。
 *  问小猴到达右下角（第n行第n列）时，最多能带走多少金币？
 *
 * Input:
 *  第1行，2个正整数n,p，用空格隔开。
 *  接下来n行，每行n个整数，表示每个格子内的金币数量。
 *
 * Output:
 *  输出一个整数，小猴最多能收集到的金币数量。
 *
 * Hints:
 *  1≤n≤100, 0≤p,vi,j≤1000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 3
1 2 1
3 4 3
5 1 3
 *
 *  output:
12
 *
 *  2):
 *  input:
3 4
1 0 1
0 1 0
1 0 1
 *
 *  output:
0
 *
 */

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n, p, v[110][110], f[110][110][1010]; // f[i][j][k] 表示走到 (i,j)时金币数量%p为k时的最大金币数量

int main()
{
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }
    memset(f, -0x3f, sizeof f);
    f[1][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < p; k++) {
                f[i][j][k] = max(max(f[i - 1][j][k], f[i - 1][j][((k - v[i][j]) % p + p) % p] + v[i][j]), max(f[i][j - 1][k], f[i][j - 1][((k - v[i][j]) % p + p) % p] + v[i][j]));
            }
        }
    }
    cout << f[n][n][0] << endl;
    return 0;
}