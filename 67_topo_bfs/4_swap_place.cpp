/**
 * Description:
 *  有一个简单的无向图，它有 N 个顶点和 M 条边，顶点从 1 到 N 编号，边从 1 到 M 编号。边 i 连接顶点 ui 和顶点 vi。
 *  此外，每个顶点都被涂成红色或蓝色。顶点 i 的颜色由 Ci 表示，如果 Ci 为 0，则顶点 i 被涂成红色；如果 Ci 为 1，则顶点 i 被涂成蓝色。
 *  现在，高桥君在顶点 1，青木君在顶点 N。
 *  两人将重复以下动作任意次数，可以是零次或更多次：
 *  	•	两人同时移动到他们当前所在顶点的相邻顶点之一。但是，高桥君移动到的顶点的颜色和青木君移动到的顶点的颜色必须不同。
 *  重复上述动作，是否可能出现高桥君能到达顶点 N，同时青木君到达顶点 1 ？如果可能，请回答所需的最少动作次数。如果不可能，请输出 -1。
 *  输入的开始会给出一个 T，请你解决 T 个测试案例。
 *
 * Input:
 *  第 1 行，一个正整数 T。
 *  接下来有 T 组数据，每组数据：
 *  第 1 行，两个正整数 n,m；
 *  第 2 行，n 个整数 Ci，表示第 i 个点的颜色；
 *  接下来 m 行，每行两个正整数 ui,vi，表示一条边。
 *
 * Output:
 *  共 T 行，依次表示每组数据的答案
 *
 * Hints:
 *  1≤T<1000, 2≤n≤2000, 1≤m≤min(N(N-1)/2, 2000), 0≤Ci≤1.所有数据的n,m 总和分别不超过 2000。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3
4 4
0 1 0 1
1 2
2 3
1 3
2 4
3 3
0 1 0
1 2
2 3
1 3
6 6
0 0 1 1 0 1
1 2
2 6
3 6
4 6
4 5
2 4
 *
 *  output:
3
-1
3
 *
 */

#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 2010;
struct node {
    int x, y;
};
int t, n, m, c[N], dis[N][N];
vector<int> g[N];

void bfs()
{
    queue<node> q;
    memset(dis, -1, sizeof dis);
    node t1 = {1, n};
    q.push(t1);
    dis[1][n] = 0;
    while (q.size()) {
        node t = q.front();
        q.pop();
        for (auto u : g[t.x]) {
            for (auto v : g[t.y]) {
                if (c[u] == c[v] || dis[u][v] != -1) {
                    continue;
                }
                node t2 = {u, v};
                q.push(t2);
                dis[u][v] = dis[t.x][t.y] + 1;
            }
        }
    }
}

int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            cin >> c[i];
        }
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        bfs();
        cout << dis[n][1] << endl;
    }
    return 0;
}
