/**
 * Description:
 *  小 K 喜欢翻看洛谷博客获取知识。每篇文章可能会有若干个（也有可能没有）参考文献的链接指向别的博客文章。小 K 求知欲旺盛，如果他看了某篇文章，那么他一定会去看这篇文章的参考文献（如果他之前已经看过这篇参考文献的话就不用再看它了）。
 *  假设洛谷博客里面一共有 n(n≤10<5>) 篇文章（编号为 1 到 n）以及 m(m≤10<6>) 条参考文献引用关系。目前小 K 已经打开了编号为 1 的一篇文章，请帮助小 K 设计一种方法，使小 K 可以不重复、不遗漏的看完所有他能看到的文章。
 *  这边是已经整理好的参考文献关系图，其中，文献 X → Y 表示文章 X 有参考文献 Y。不保证编号为 1 的文章没有被其他文章引用。
 *  请对这个图分别进行 DFS 和 BFS，并输出遍历结果。如果有很多篇文章可以参阅，请先看编号较小的那篇（因此你可能需要先排序）。
 *
 * Input:
 *  共 m+1 行，第 1 行为 2 个数，n 和 m，分别表示一共有 n(n≤10<5>) 篇文章（编号为 1 到 n）以及m(m≤10<6>) 条参考文献引用关系。
 *  接下来 m 行，每行有两个整数 X,Y 表示文章 X 有参考文献 Y。
 *
 * Output:
 *  输出两行，每行n 个空格分隔的数，表示图的 DFS 和 BFS 顺序。
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
8 9
1 2
1 3
1 4
2 5
2 6
3 7
4 7
4 8
7 8
 *
 *  output:
1 2 5 6 3 7 8 4
1 2 3 4 5 6 7 8
 *
 */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int N = 1e5 + 10;
int n, m, vis[N];
vector<int> g[N];

void dfs(int x)
{
    if (vis[x]) {
        return;
    }
    vis[x] = 1;
    cout << x << " ";
    for (auto y : g[x]) {
        dfs(y);
    }
}

void bfs(int s)
{
    queue<int> q;
    memset(vis, 0, sizeof vis);
    q.push(s);
    vis[s] = 1;
    while (q.size()) {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (auto y : g[x]) {
            if (!vis[y]) {
                q.push(y);
                vis[y] = 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
    }
    dfs(1);
    cout << endl;
    bfs(1);
    return 0;
}