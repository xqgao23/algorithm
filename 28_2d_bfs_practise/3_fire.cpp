/**
 * Description:
 *  一个街道被分成 n×m 的网格。
 *  目前有 k 个格子已经起火
 * ，每个起火的格子每个单位时间都会向上下左右延伸，延伸出来的新的格子也会起火。
 *  问哪些格子起火的的时间最晚。
 *
 * Input:
 *  第1行包含2个整数n,m。
 *  第2行包含1个整数k，初始起火格子个数。
 *  接下来k行，每行2个整数xi,yi，表示初始起火格子位置 。
 *
 * Output:
 *  每行一个，输出所有最晚起火的格子。
 *  输出顺序按行坐标从小到大，相同行的按列坐标从小到大。
 *
 * Hints:
 *  1≤n,m≤2000, 1≤k≤10, 1≤xi≤n, 1≤yi≤m
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 3
1
3 1
 *
 *  output:
1 3
 *
 *  2):
 *  input:
3 3
1
2 2
 *
 *  output:
1 1
1 3
3 1
3 3
 *
 *  3):
 *  input:
3 3
2
1 1
3 3
 *
 *  output:
1 3
2 2
3 1
 *
 */

#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, k, dis[2010][2010], ans = 0;

struct node {
    int x, y;
};

void bfs()
{
    queue<node> q;
    memset(dis, -1, sizeof dis);
    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        node tt = {x, y};
        q.push(tt);
        dis[x][y] = 0;
    }
    while (q.size()) {
        node t = q.front();
        q.pop();
        for (int i = 0; i <= 3; i++) {
            int x = t.x + dx[i], y = t.y + dy[i];
            if (x < 1 || x > n || y < 1 || y > m || dis[x][y] != -1) {
                continue;
            }
            node tm = {x, y};
            q.push(tm);
            dis[x][y] = dis[t.x][t.y] + 1;
            ans = max(ans, dis[x][y]);
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    bfs();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dis[i][j] == ans) {
                cout << i << " " << j << endl;
            }
        }
    }
    return 0;
}