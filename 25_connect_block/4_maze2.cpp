/**
 * Description:
 *  有一个仅由数字0与1组成的n×n格迷宫。若你位于一格0上，那么你可以移动到相邻4格中的某一格1上，同样若你位于一格1上，那么你可以移动到相邻4格中的某一格0上。
 *  你的任务是：对于给定的迷宫，询问从某一格开始能移动到多少个格子（包含自身）。
 *
 * Input:
 *  输入的第1行为两个正整数n,m。
 *  下面n行，每行n个字符，字符只可能是0或者1，字符之间没有空格。
 *  接下来m行，每行2个用空格分隔的正整数i,j，对应了迷宫中第i行第j列的一个格子，询问从这一格开始能移动到多少格。
 *
 * Output:
 *  输出包括m行，对于每个询问输出相应答案。
 *
 * Hints:
 *  n≤1000，m≤100000。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
2 2
01
10
1 1
2 2
 *
 *  output:
4
4
 *
 */

#include <iostream>
using namespace std;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m, vis[1010][1010], cnt, ans[1000010];
char g[1010][1010];

void dfs(int x, int y)
{
    vis[x][y] = cnt;
    ans[cnt]++;
    for (int i = 0; i <= 3; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > n || g[nx][ny] == g[x][y] ||
            vis[nx][ny]) {
            continue;
        }
        dfs(nx, ny);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!vis[i][j]) {
                cnt++;
                dfs(i, j);
            }
        }
    }
    while (m--) {
        int i, j;
        cin >> i >> j;
        cout << ans[vis[i][j]] << endl;
    }
    return 0;
}