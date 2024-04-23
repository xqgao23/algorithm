/**
 * Description:
 *  由于近期的降雨, 雨水汇集在农民约翰的田地不同的地方.
 * 我们用一个N×M(1≤N≤100,1≤M≤100)网格图表示. 每个网格中有水('W') 或是旱地('.').
 * 一个网格与其周围的八个网格相连, 而一组相连的网格视为一个湖.
 * 约翰想弄清楚他的田地已经形成了多少湖. 给出约翰田地的示意图, 确定当中有多少湖.
 *
 * Input:
 *  输入共2行:
 *  第1行,2个空格隔开的整数:N 和M.
 *  第2行到第N+1行，每行M个字符, 每个字符是'W'或'.', 它们表示网格图中的一排.
 * 字符之间没有空格.
 *
 * Output:
 *  1个整数，湖的个数.
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.
 *
 *  output:
3
 *
 */

#include <iostream>
using namespace std;
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int n, m, vis[110][110], ans;
char g[110][110];

void dfs(int x, int y)
{
    vis[x][y] = 1;
    for (int i = 0; i <= 7; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > m || g[nx][ny] != 'W' ||
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
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == 'W' && !vis[i][j]) {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}