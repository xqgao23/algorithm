/**
 * Description:
 *  对一个如下的8×8的国际象棋棋盘，有八个皇后被放置在棋盘上，使得每行、每列和每条斜线上都至多只有一个皇后,
 *  这就是著名的八皇后问题，下图是其中一个解.
 *  类似地我们可以定义n皇后问题:n×n的国际象棋棋盘，有n个皇后被放置在棋盘上，使得每行、每列和每条斜线上都至多只有一个皇后.
 *  但是目前棋盘上有一些格子有缺口，我们不能在这些格子上放置皇后。你要求出有多少种放置皇后的方法。
 *
 * Input:
 *  第1行，2个正整数n,k,n×n皇后问题，棋盘上有k个格子不能放置皇后.
 *  接下来k行，每行两个正整数x,y，表示第x行第y列不能放皇后。
 *
 * Output:
 *  输出放置皇后的方法数。
 *
 * Hints:
 *  1≤n≤12；1≤x,y≤n, 0≤k≤n<2>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4 1
1 3
 *
 *  output:
1
 *
 */

#include <iostream>
using namespace std;
int n, k, g[15][15], c[15], z[30], f[30], ans;

void dfs(int x)
{
    if (x > n) {
        ans++;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!g[x][i] && !c[i] && !f[x + i] && !z[x - i + n]) {
            c[i] = f[x + i] = z[x - i + n] = 1;
            dfs(x + 1);
            c[i] = f[x + i] = z[x - i + n] = 0;
        }
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        g[x][y] = 1;
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}