/**
 * Description:
 *  你现在身处一个n×m格的迷宫之中，每步可以向上下左右走1格，迷宫中有一些格子不能进入。
 * 给出起点和终点，求最短多少步可以走到终点。
 *
 * Input:
 *  第1行，2个正整数n,m
 *  接下来n行，每行m个数（0或1），1表示可以进入的格子，0表示不能进入的格子。数之间没有空格
 *  第n+2行，4个整数x1,y1,x2,y2，表示起点在x1行y1列，终点在x2行y2列。一定都是可以进入的格子。
 *
 * Output:
 *  如果可以走到终点，输出所需最短步数。
 *  如果不能走到终点，输出-1
 *
 * Hints:
 *  1≤n,m≤50, 1<=x1,x2<=n, 1<=y1,y2<=m
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4 4
1101
1001
1100
0111
1 2 4 4
 *
 *  output:
7
 *
 *  2):
 *  input:
4 4
1101
1001
1100
0111
1 4 4 4
 *
 *  output:
-1
 *
 */

#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m, x1, y1, x2, y2, dis[55][55];
char g[55][55];
struct node {
    int x, y;
};

int bfs(int a, int b)
{
    queue<node> q;
    memset(dis, -1, sizeof dis);
    node tt = {.x = a, .y = b};
    q.push(tt);
    dis[a][b] = 0;
    while (q.size()) {
        node t = q.front();
        q.pop();
        if (t.x == x2 && t.y == y2) {
            return dis[x2][y2];
        }
        for (int i = 0; i <= 3; i++) {
            int nx = t.x + dx[i], ny = t.y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m || g[nx][ny] == '0' ||
                dis[nx][ny] != -1) {
                continue;
            }
            node tm = {.x = nx, .y = ny};
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
    cin >> x1 >> y1 >> x2 >> y2;
    cout << bfs(x1, y1) << endl;
    return 0;
}