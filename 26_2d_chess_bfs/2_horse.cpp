/**
 * Description:
 *  有一个n∗m的棋盘(1<n,m≤400)，在某个点上有一个马，要求你计算出马到达棋盘上任意一个点最少要走几步
 *
 * Input:
 *  一行四个数据，棋盘的大小和马的坐标。
 *
 * Output:
 *  一个n∗m的矩阵，代表马到达某个点最少要走几步（左对齐，宽5格，不能到达则输出−1）
 *
 * Hints:
 *  1≤n,m≤400
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 3 1 1
 *
 *  output:
0    3    2
3    -1   1
2    1    4
 *
 */

#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};
int n, m, a, b, dis[500][500];
struct node {
    int x, y;
};

void bfs(int a, int b)
{
    queue<node> q;
    memset(dis, -1, sizeof dis);
    node tt = {a, b};
    q.push( tt);
    dis[a][b] = 0;
    while (q.size()) {
        node t = q.front();
        q.pop();
        for (int i = 0; i <= 7; i++) {
            int nx = t.x + dx[i], ny = t.y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m || dis[nx][ny] != -1) {
                continue;
            }
            node tm = {nx, ny};
            q.push(tm);
            dis[nx][ny] = dis[t.x][t.y] + 1;
        }
    }
}

int main()
{
    cin >> n >> m >> a >> b;
    bfs(a, b);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%-5d", dis[i][j]);
        }
        cout << endl;
    }
    return 0;
}