/**
 * Description:
 *  高桥设计了一个H行W列的迷宫，第i行第j列的格子如果是 # 就代表墙壁，如果是 .
 * 就代表通路。迷宫中只能从通路移动到上下左右的通路，不能斜向移动，也不能移动到墙壁格子。
 *  高桥指定好起点和终点后，将迷宫交给青山。青山从起点出发，沿最短路线走到终点。
 *  高桥打算设定一组合适的起点终点位置，使得青山移动次数达到最大，那么青山最多可能移动多少次？
 *
 * Input:
 *  第1行，2个正整数H,W
 *  接下来H行，每行W个字符，表示迷宫的地图
 *
 * Output:
 *  1个正整数，青山最多可能移动的次数
 *
 * Hints:
 *  1≤H,W≤20
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 3
.#.
...
##.
 *
 *  output:
4
 *
 *  2):
 *  input:
3 5
...#.
.#.#.
.#...
 *
 *  output:
10
 *
 */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m, dis[30][30], ans;
char g[30][30];
struct node {
    int x, y;
};

int bfs(int a, int b)
{
    int ans = 0;
    queue<node> q;
    memset(dis, -1, sizeof dis);
    node tt = {a, b};
    q.push(tt);
    dis[a][b] = 0;
    while (q.size()) {
        node t = q.front();
        q.pop();
        for (int i = 0; i <= 3; i++) {
            int x = t.x + dx[i], y = t.y + dy[i];
            if (x < 1 || x > n || y < 1 || y > m || g[x][y] == '#' ||
                dis[x][y] != -1) {
                continue;
            }
            node tm = {x, y};
            q.push(tm);
            dis[x][y] = dis[t.x][t.y] + 1;
            ans = max(ans, dis[x][y]);
        }
    }
    return ans;
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
            if (g[i][j] == '.') {
                ans = max(ans, bfs(i, j));
            }
        }
    }
    cout << ans << endl;
    return 0;
}