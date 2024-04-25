/**
 * Description:
 *  迷宫城可以看做n×m网格，每个格子要么是空地，要么是障碍物。
 *  '.' 代表空地，'*'
 * 代表障碍物。现在要你对于每个障碍物都做如下判断：如果把当前障碍格改成空地，那么当前格所在连通块的大小（即包含的格子个数）就要标记在地图的这个格子上。我们认为上下左右相邻的格子是相互连通的。
 *  输出时，将每个障碍物格子改成连通块大小除10的余数
 *
 * Input:
 *  第1行，2个正整数n,m
 *  接下来n行，每行m个字符，表示迷宫地图，'.' 代表空地，'*' 代表障碍物
 *
 * Output:
 *  输出n行，每行m个字符。
 *  将障碍物格改成连通块大小除10的余数。空格原样输出。
 *
 * Hints:
 *  1≤n,m≤1000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 3
*.*
.*.
*.*
 *
 *  output:
3.3
.5.
3.3
 *
 *  2):
 *  input:
4 5
**..*
..***
.*.*.
*...*
 *
 *  output:
46..3
..032
.8.6.
8...6
 *
 */

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m, cnt, vis[1010][1010], ans[1000010];
char g[1010][1010];

void dfs(int x, int y)
{
    vis[x][y] = cnt;
    ans[cnt]++;
    for (int i = 0; i <= 3; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 1 || xx > n || yy < 1 || yy > m || vis[xx][yy] ||
            g[xx][yy] != '.') {
            continue;
        }
        dfs(xx, yy);
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
                cnt++;
                dfs(i, j);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == '*') {
                int c = 1, t[5] = {0};
                for (int k = 0; k <= 3; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    t[k] = vis[x][y];
                }
                sort(t, t + 4);
                for (int k = 0; k <= 3; k++) {
                    if (t[k] != t[k + 1]) {
                        c += ans[t[k]];
                    }
                }
                cout << c % 10;
            } else {
                cout << g[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}