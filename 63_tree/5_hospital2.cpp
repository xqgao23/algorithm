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

// O(n)
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
int n, w[1010], ch[1010][5], cnt[1010], d[1010];
LL ans = 1e18, sum[1010], dis[1010];
bool vis[1010];

void dfs(int x, int rt)
{
    d[x] = d[rt] + 1;
    vis[x] = 1;
    for (int i = 1; i <= cnt[x]; i++) {
        if (!vis[ch[x][i]]) {
            dfs(ch[x][i], x);
            sum[x] += sum[ch[x][i]];
        }
    }
}

void dfs(int x)
{
    vis[x] = 1;
    for (int i = 1; i <= cnt[x]; i++) {
        if (!vis[ch[x][i]]) {
            dis[ch[x][i]] = dis[x] + sum[1] - sum[ch[x][i]] - sum[ch[x][i]];
            ans = min(ans, dis[ch[x][i]]);
            dfs(ch[x][i]);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> w[i] >> x >> y;
        sum[i] = w[i];

        if (x) {
            ch[i][++cnt[i]] = x;
            ch[x][++cnt[x]] = i;
        }
        if (y) {
            ch[i][++cnt[i]] = y;
            ch[y][++cnt[y]] = i;
        }
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        dis[1] += (d[i] - 1) * w[i];
    }
    ans = dis[1];
    memset(vis, 0, sizeof vis);
    dfs(1);
    cout << ans << endl;
    return 0;
}