/**
 * Description:
 *  小猴不小心游荡进了一片苹果林地。这个苹果林被分割成一个 R 行 C 列的网格(1≤R≤40,1≤C≤40)。
 *  小猴可以从一个格向上下左右走到邻接的另一个格。小猴发现一开始她自己在苹果林的(1,1)，也就是第一行第一列。
 *  小猴用他敏锐的视觉去数每一个邻接的格里挂着的苹果的数目。然后他就游荡到那个有最多没有被吃掉的苹果的邻接的格子（保证这样的格子只有一个）。
 *  按照这种移动方法，最终小猴总是会在(R,C)停止，并且吃掉路过格子中的所有苹果（包含起点和终点）。
 *  给定这个苹果林的大小及每个格的苹果数ai,j(1≤ai,j≤100),
 * 要求小猴一共吃了多少个苹果。
 *
 * Input:
 *  第1行，两个正整数R,C
 *  接下来R行，每行C个正整数，表示每格的苹果数。
 *
 * Output:
 *  输出小猴一共吃了多少个苹果。
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 4
3 3 4 5
4 5 3 2
1 7 4 2
 *
 *  output:
39
 *
 */

#include <iostream>
using namespace std;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m, a[45][45], vis[45][45], ans;

void dfs(int x, int y)
{
    ans += a[x][y];
    if (x == n && y == m) {
        return;
    }
    a[x][y] = -1;
    int nx = x + dx[0], ny = y + dy[0];
    for (int i = 1; i < 4; i++) {
        if (a[x + dx[i]][y + dy[i]] > a[nx][ny]) {
            nx = x + dx[i], ny = y + dy[i];
        }
    }
    dfs(nx, ny);
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    dfs(1, 1);
    cout << ans << endl;
    return 0;
}