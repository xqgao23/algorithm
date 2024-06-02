/**
 * Description:
 *  妈妈下班回家，街坊邻居说小明被一群陌生人强行押上了警车！妈妈丰富的经验告诉她小明被带到了 t 区，而自己在 s 区。
 *  该市有 m 条大道连接 n 个区，一条大道将两个区相连接，每个大道有一个拥挤度。小明的妈妈虽然很着急，但是不愿意拥挤的人潮冲乱了她优雅的步伐。所以请你帮她规划一条从 s 至 t 的路线，使得经过道路的拥挤度最大值最小。
 *
 * Input:
 *  第一行有四个用空格隔开的 n，m，s，t，其含义见【题目描述】。
 *  接下来 m 行，每行三个整数 u,v,w，表示有一条大道连接区 u 和区 v，且拥挤度为 w。
 *  两个区之间可能存在多条大道。
 *
 * Output:
 *  输出一行一个整数，代表最大的拥挤度。
 *
 * Hints:
 *  1≤n≤10<4>, 1≤m≤2×10<4>, w≤10<4>, 1≤s,t≤n。
 *  且从 s 出发一定能到达 t 区。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 3 1 3
1 2 2
2 3 1
1 3 3
 *
 *  output:
2
 *
 */

#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 10005;
int n, m, s, t, vis[N];
struct node {
    int v, w;
};
vector<node> g[N];

bool check(int w)
{
    queue<int> q;
    memset(vis, 0, sizeof vis);
    q.push(s);
    vis[s] = 1;
    while (q.size()) {
        int x = q.front();
        q.pop();
        if (x == t) {
            return true;
        }
        for (auto y : g[x]) {
            if (!vis[y.v] && y.w <= w) {
                q.push(y.v);
                vis[y.v] = 1;
            }
        }
    }
    return false;
}

int main()
{
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        node t1 = {v, w};
        node t2 = {u, w};
        g[u].push_back(t1);
        g[v].push_back(t2);
    }
    int l = 1, r = 1e4, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;
    return 0;
}