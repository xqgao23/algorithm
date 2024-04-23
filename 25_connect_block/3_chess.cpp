/**
 * Description:
 *  DZY喜欢在棋盘上玩。
 *  他有一个n行m列的棋盘，棋盘上的格子分为好格和坏格，DZY在每个好格上放一个黑或白的棋子，并保证同色棋子不相邻（两个格子相邻为它们存在共同的边）。
 *  你要给出一个可行的摆法。
 *
 * Input:
 *  输入共n+1行:
 *  第1行，两个用空格隔开的整数n,m，意义如题目描述.
 *  第2∼n+1行，每行一个m长度的字符串，由'.'和'-'组成，这给出了整个棋盘的1∼n行.
 * '.'表示这里是一个好格,'-'则表示坏格.
 *
 * Output:
 *  输出共n行:
 *  第1∼n行，每行一个m长度的字符串，由'W','B'和'-'组成，这是按要求放置完棋子的整个棋盘的1∼n行.
 * 'W'表示这里放了一个白色棋子,'B'表示这里放了一个黑色棋子,'-'则表示坏格.
 *  请保证每个区域的最上一行的最左一个棋子是黑子.
 *
 * Hints:
 *  1<=n,m<=100
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
2 2
..
..
 *
 *  output:
BW
WB
 *
 *  2):
 *  input:
3 3
.-.
---
--.
 *
 *  output:
B-B
---
--B
 *
 */

#include <iostream>
using namespace std;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m, vis[110][110];
char g[110][110];

void dfs(int x, int y, char c)
{
    g[x][y] = c;
    vis[x][y] = 1;
    for (int i = 0; i <= 3; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > m || g[nx][ny] != '.' ||
            vis[nx][ny]) {
            continue;
        }
        if (c == 'B') {
            dfs(nx, ny, 'W');
        } else {
            dfs(nx, ny, 'B');
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == '.' && !vis[i][j]) {
                dfs(i, j, 'B');
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << g[i][j];
        }
        cout << endl;
    }
    return 0;
}