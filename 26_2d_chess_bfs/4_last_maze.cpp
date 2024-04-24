/**
 * Description:
 *  哈利•波特作为三强争霸赛的第四名选手，历尽艰险闯到了最后一关------迷宫。现在，迷宫里只剩下哈利和塞德里克了，哈利只有在塞德里克前面拿到奖杯，才能赢得比赛。哈利只要能看到奖杯，就可以用飞来咒拿到它，所以，现在的问题是哈利如何能尽早地看到奖杯。哈利的视力非常好，他能从迷宫的一端沿直线看到迷宫的另一端（但他只能看八个方向------东北，东，东南，南，西南......），而且跑得非常快，跑一步（向上、下、左、右移动一格）只需要1s。但迷宫是不透光的，而且，要烧掉迷宫的墙也不容易，所以哈利决定绕到一个能够看到奖杯的地方。现在，哈利希望你能帮他确定最短需要多长时间才能拿到奖杯。
 *
 * Input:
 *  第一行为2个数N,M表示迷宫的规模（N为高，M为宽）。
 *  接下来是N∗M的迷宫，'O'表示空地，'X'表示墙。
 *  最后是多组数据，分别是奖杯坐标及哈利的坐标（显然不可能在墙上），每对占一行，0为结束标志。
 *
 * Output:
 *  根据每对数据，计算哈利拿到奖杯的最短时间，每对一行。如果魔法部有意难为选手，用墙将奖杯包围了起来，输出"Poor
 * Harry"。
 *
 * Hints:
 *  N*M≤16384，1<=N,M≤1000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 4
OXXO
XXOO
XOOO
3 2 2 4
3 3 1 1
0 0 0 0
 *
 *  output:
1
Poor Harry
 *
 */

#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int n, m, x1, y1, x2, y2, vis[1010][1010], dis[1010][1010];

char g[1010][1010];
struct node {
    int x, y;
};

int bfs(int a, int b)
{
    memset(vis, 0, sizeof vis);
    memset(dis, -1, sizeof dis);
    for (int i = 0; i <= 7; i++) {
        int x = x1, y = y1;
        while (x >= 1 && x <= n && y >= 1 && y <= m && g[x][y] == 'O') {
            vis[x][y] = 1;
            x += dx[i];
            y += dy[i];
        }
    }
    queue<node> q;
    node tt = {a, b};
    q.push(tt);
    dis[a][b] = 0;
    while (q.size()) {
        node t = q.front();
        q.pop();
        if (vis[t.x][t.y]) {
            return dis[t.x][t.y];
        }
        for (int i = 0; i <= 3; i++) {
            int nx = t.x + dx[i], ny = t.y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m || g[nx][ny] != 'O' ||
                dis[nx][ny] != -1) {
                continue;
            }
            node tm = {nx, ny};
            q.push(tm);
            dis[nx][ny] = dis[t.x][t.y] + 1;
        }
    }
    return -1;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    while (cin >> x1 >> y1 >> x2 >> y2, x1) {
        int ans = bfs(x2, y2);
        if (ans == -1) {
            cout << "Poor Harry" << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}