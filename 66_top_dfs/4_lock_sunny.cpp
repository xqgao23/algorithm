/**
 * Description:
 *  老曹爱刷街，暑假期间，他每天都欢快地在阳光大学的校园里刷街。河蟹看到欢快的曹，感到不爽。河蟹决定封锁阳光大学，不让曹刷街。
 *  阳光大学的校园是一张由 n 个点构成的无向图，n 个点之间由 m 条道路连接。每只河蟹可以对一个点进行封锁，当某个点被封锁后，与这个点相连的道路就被封锁了，曹就无法在这些道路上刷街了。非常悲剧的一点是，河蟹是一种不和谐的生物，当两只河蟹封锁了相邻的两个点时，他们会发生冲突。
 *  询问：最少需要多少只河蟹，可以封锁所有道路并且不发生冲突。
 *
 * Input:
 *  第一行两个正整数，表示节点数和边数。接下来 m 行，每行两个整数 u,v，表示点 u 到点 v 之间有道路相连。
 *
 * Output:
 *  仅一行如果河蟹无法封锁所有道路，则输出 `Impossible`，否则输出一个整数，表示最少需要多少只河蟹。
 *
 * Hints:
 *  1≤n≤10<4>，1≤m≤10<5>，保证没有重边。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 3
1 2
1 3
2 3
 *
 *  output:
Impossible
 *
 *  2):
 *  input:
3 2
1 2
2 3
 *
 *  output:
1
 *
 */

#include <iostream>
#include <vector>
using namespace std;
const int N = 1e4 + 10;
int n, m, vis[N], cnt[5], ans;
vector<int> g[N];

bool dfs(int x, int k)
{
    if (vis[x]) {
        return vis[x] == k;
    }
    vis[x] = k;
    cnt[k]++;
    for (int i = 0; i < g[x].size(); i++) {
        int y = g[x][i];
        if (!dfs(y, 3 - k)) {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            continue;
        }
        cnt[1] = cnt[2] = 0;
        if (!dfs(i, 1)) {
            cout << "Impossible" << endl;
            return 0;
        }
        ans += min(cnt[1], cnt[2]);
    }
    cout << ans << endl;
    return 0;
}