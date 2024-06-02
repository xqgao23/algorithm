/**
 * Description:
 *  给定一张 n 个节点 m 条边的无向图，保证每个节点的度数 ≤10。
 *  记从任意节点回到 1 号点的不同简单路径总数为 k，请输出 min(k,10<6>)。
 *  简单路径是不经过重复结点的路径。
 *
 * Input:
 *  第 1 行，两个正整数 n,m。
 *  接下来 m 行，第 i(1≤i≤n) 行两个整数 ui,vi，表示一条边。
 *
 * Output:
 *  一行，一个整数，表示答案。
 *
 * Hints:
 *  1≤n≤2×10<s>,0≤m≤min(2×10<5>, n(n-1)/2),1≤ui, vi≤n，结点度数保证不超过 10。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4 2
1 2
2 3
 *
 *  output:
3
 *
 *  2):
 *  input:
4 6
1 2
1 3
1 4
2 3
2 4
3 4
 *
 *  output:
16
 *
 *  3):
 *  input:
8 21
2 6
1 3
5 6
3 8
3 6
4 7
4 6
3 4
1 5
2 4
1 2
2 7
1 4
3 5
2 5
2 3
4 5
3 7
6 7
5 7
2 8
 *
 *  output:
2023
 *
 */

#include <iostream>
#include <vector>
using namespace std;
const int N = 2e5 + 10;
int n, m, vis[N], cnt;
vector<int> g[N];

void dfs(int x)
{
    if (cnt >= 1e6) {
        return;
    }
    vis[x] = 1;
    cnt++;
    for (int i = 0; i < g[x].size(); i++) {
        int y = g[x][i];
        if (vis[y]) {
            continue;
        }
        dfs(y);
    }
    vis[x] = 0;
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
    dfs(1);
    cout << cnt << endl;
    return 0;
}