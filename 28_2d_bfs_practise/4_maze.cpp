/**
 * Description:
 *  给定一个N×M方格的迷宫，迷宫里有T处障碍，障碍处不可通过。给定起点坐标和终点坐标，问:
 * 每个方格最多经过1次，有多少种从起点坐标到终点坐标的方案。
 *  在迷宫中移动有上下左右四种方式，每次只能移动一个方格。数据保证起点上没有障碍。
 *
 * Input:
 *  第一行N,M,T，N为行，M为列，T为障碍总数。
 *  第二行起点坐标SX,SY，终点坐标FX,FY。
 *  接下来T行，每行为障碍点的坐标。
 *
 * Output:
 *  给定起点坐标和终点坐标，问每个方格最多经过1次，从起点坐标到终点坐标的方案总数。
 *
 * Hints:
 *  1≤n,m≤5
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
2 2 1
1 1 2 2
1 2
 *
 *  output:
1
 *
 */

#include <iostream>
using namespace std;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int n, m, t, sx, sy, fx, fy, vis[10][10], ans;

void dfs(int x, int y)
{
    if (x == fx && y == fy) {
        ans++;
        return;
    }
    vis[x][y] = 1;
    for (int i = 0; i <= 3; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 1 || xx > n || yy < 1 || yy > m || vis[xx][yy]) {
            continue;
        }
        dfs(xx, yy);
    }
    vis[x][y] = 0;
}

int main()
{
    cin >> n >> m >> t >> sx >> sy >> fx >> fy;
    for (int i = 1; i <= t; i++) {
        int x, y;
        cin >> x >> y;
        vis[x][y] = 1;
    }
    dfs(sx, sy);
    cout << ans << endl;
    return 0;
}