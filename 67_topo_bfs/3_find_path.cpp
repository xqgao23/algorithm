/**
 * Description:
 *  在有向图 G 中，每条边的长度均为 1，现给定起点和终点，请你在图中找一条从起点到终点的路径，该路径满足以下条件：
 *  1. 路径上的所有点的出边所指向的点都直接或间接与终点连通。2. 在满足条件1的情况下使路径最短。
 *  注意：图 G 中可能存在重边和自环，题目保证终点没有出边。
 *  请你输出符合条件的路径的长度。
 *
 * Input:
 *  第一行有两个用一个空格隔开的整数 n 和 m，表示图有 n 个点和 m 条边。
 *  接下来的 m 行每行 2 个整数 x,y，之间用一个空格隔开，表示有一条边从点 x 指向点y。
 *  最后一行有两个用一个空格隔开的整数 s,t，表示起点为 s，终点为 t。
 *
 * Output:
 *  输出只有一行，包含一个整数，表示满足题目描述的最短路径的长度。如果这样的路径不存在，输出−1。
 *
 * Hints:
 *  0<n<10<4>, 0<m≤2×10<5>, 0<x,y,s,t≤n,x, s!=t。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 2
1 2
2 1
1 3
 *
 *  output:
-1
 *
 *  2):
 *  input:
6 6
1 2
1 3
2 6
2 5
4 5
3 4
1 5
 *
 *  output:
3
 *
 */

#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int N = 1e4 + 10;
int n, m, s, t, vis1[N], vis2[N], dis[N];
vector<int> g[N];

void dfs(int x)
{
    if (vis1[x]) {
        return;
    }
    vis1[x] = vis2[x] = 1;
    for (auto y : g[x]) {
        if (!vis1[y]) {
            dfs(y);
        }
    }
}

void bfs(int s)
{
    queue<int> q;
    memset(dis, -1, sizeof dis);
    q.push(s);
    dis[s] = 0;
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (auto y : g[x]) {
            if (dis[y] == -1 && vis2[y]) {
                q.push(y);
                dis[y] = dis[x] + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[y].push_back(x);
    }
    cin >> s >> t;
    dfs(t);
    for (int i = 1; i <= n; i++) {
        if (!vis1[i]) {
            for (auto j : g[i]) {
                vis2[j] = 0;
            }
        }
    }
    bfs(t);
    cout << dis[s] << endl;
    return 0;
}