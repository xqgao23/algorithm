/**
 * Description:
 *  小猴在一个n×m的棋盘上玩一个游戏。每个格子上写着一个字符，小猴可以选任意一个格子作为起点，将代表小兵的棋子放到起点上，然后按照格子上的字符指示移动棋子。
 *  如果格子上的字符是"UDLR"之一，就把棋子向对应方向移动1格，"UDLR"分别对应上下左右。
 *  如果格子上的字符是'#'，就不能再继续移动了。
 *  小猴反复移动棋子，直到棋子不能移动或者走出棋盘。小猴想要移动的步数尽可能多，那么通过选择合适的起点，小猴最多能移动多少步？（如果小猴可以无限地移动棋子，输出−1）
 *
 * Input:
 *  第1行，2个正整数n,m。
 *  接下来n行，每行m个字符。只包含UDLR#。
 *
 * Output:
 *  输出小猴可以移动棋子的最多步数。如果可以无限地移动棋子，输出−1。
 *
 * Hints:
 *  1≤n,m≤2000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 4
#D#D
#DLL
UL##
 *
 *  output:
6
 *
 *  2):
 *  input:
3 4
####
#RL#
####
 *
 *  output:
-1
 *
 *  3):
 *  input:
1 1
#
 *
 *  output:
0
 *
 */

#include <iostream>
using namespace std;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
string dir = "UDLR";
int n, m, vis[2010][2010], ans = -1, cnt;
char g[2010][2010];

int dfs(int x, int y)
{
    if (vis[x][y] == 0) {
        cnt++;
    }
    vis[x][y] = 1;
    int c = 0;
    for (int i = 0; i <= 3; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (dir[i] != g[xx][yy] || g[xx][yy] == '#') {
            continue;
        }
        c = max(c, dfs(xx, yy) + 1);
    }
    return c;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            g[i][j] = '#';
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            if (g[i][j] == '#') {
                ans = max(ans, dfs(i, j));
            }
        }
    }
    if (cnt < (n + 2) * (m + 2)) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}