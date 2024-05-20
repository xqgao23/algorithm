/**
 * Description:
 *  其中，圈中的数字表示结点中居民的人口。圈边上数字表示结点编号，现在要求在某个结点上建立一个医院，使所有居民所走的路程之和为最小，同时约定，相邻接点之间的距离为 1。如上图中，若医院建在1 处，则距离和 =4+12+2×20+2×40=136；若医院建在 3 处，则距离和 =4×2+13+20+40=81。
 *
 * Input:
 *  第一行一个整数 n，表示树的结点数。
 *  接下来的 n 行每行描述了一个结点的状况，包含三个整数 w,u,v，其中 w 为居民人口数，u 为左链接（为 0 表示无链接），v 为右链接（为 0 表示无链接）。
 *
 *
 * Output:
 *  一个整数，表示最小距离和。
 *
 * Hints:
 *  1≤n≤1000,0≤u,v≤n,1≤w≤10<5>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5
13 2 3
4 0 0
12 4 5
20 0 0
40 0 0
 *
 *  output:
81
 *
 */

// O(n*n)
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
int n, w[1010], fa[1010], lc[1010], rc[1010];
bool vis[1010];

LL dfs(int x, int d)
{
    LL sum = d * w[x];
    vis[x] = 1;
    if (lc[x] && !vis[lc[x]]) {
        sum += dfs(lc[x], d + 1);
    }
    if (rc[x] && !vis[rc[x]]) {
        sum += dfs(rc[x], d + 1);
    }
    if (fa[x] && !vis[fa[x]]) {
        sum += dfs(fa[x], d + 1);
    }
    return sum;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> lc[i] >> rc[i];
        if (lc[i]) {
            fa[lc[i]] = i;
        }
        if (rc[i]) {
            fa[rc[i]] = i;
        }
    }
    LL ans = 1e18;
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof vis);
        ans = min(ans, dfs(i, 0));
    }
    cout << ans << endl;
    return 0;
}