/**
 * Description:
 *  小猴遇到了一个问题，他管理着一座n×m格的迷宫，迷宫用一个二维字符数组表示，ai,j表示第i行第j列的状态：
 *  . 表示空格子
 *  # 表示障碍物格子
 *  G 表示格子里有一名好人
 *  B 表示格子里有一名坏人
 *  迷宫的唯一出口是第n行第m列，保证第n行第m列是空格子。
 *  迷宫中的人（好人和坏人）的移动方式都是上下左右移动，只有障碍物格子不能通行（移动过程中可以穿过其他人，不论好人还是坏人），如果能通过若干次移动到达第n行第m列，就能逃离迷宫。
 *  现在小猴想要将一些空格子改成障碍物格子，使得所有坏人都无法逃离迷宫，所有好人都能够逃离迷宫。如果有需要，他也可以将出口改成障碍物。
 *  问小猴能否达成他的目的？（输入包含多组数据）
 *
 * Input:
 *  第1行，1个正整数T，表示有T组数据。
 *  每组数据如下：
 *  第1行，两个正整数n,m，表示迷宫大小。
 *  接下来n行，每行m个字符，表示迷宫状态。
 *
 * Output:
 *  输出T行。
 *  对每组数据，如果小猴能让所有好人都能够逃离，所有坏人无法逃离迷宫，输出Yes；否则输出No。
 *
 * Hints:
 *  1≤T≤10, 1≤n,m≤50
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
6
1 1
.
1 2
G.
2 2
#B
G.
2 3
G.#
B#.
3 3
#B.
#..
GG.
2 2
#B
B.
 *
 *  output:
Yes
Yes
No
No
Yes
Yes
 *
 */

#include <cstring>
#include <iostream>
using namespace std;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int t, n, m, vis[55][55];
char g[55][55];

void dfs(int x, int y)
{
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > m || g[nx][ny] == '#' ||
            vis[nx][ny]) {
            continue;
        }
        dfs(nx, ny);
    }
}

bool check()
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == 'B') {
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x < 1 || x > n || y < 1 || y > m || g[x][y] == 'B') {
                        continue;
                    }
                    if (g[x][y] == 'G') {
                        return false;
                    }
                    g[x][y] = '#';
                }
            }
        }
    }
    memset(vis, 0, sizeof vis);
    if (g[n][m] != '#') {
        dfs(n, m); // 可能没有好人
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == 'G' && !vis[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> g[i][j];
            }
        }
        if (check()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}