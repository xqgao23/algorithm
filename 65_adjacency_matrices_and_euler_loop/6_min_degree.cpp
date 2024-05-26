/**
 * Description:
 *  给定一个 n 个点 m 条边的无向图。求所有连通三元组中度数的最小值，如果图中没有连通三元组，则输出 -1。
 *  连通三元组指的是三个结点组成的集合，且满足三个点之间两两有边。
 *  连通三元组的度数是所有满足以下条件的边的数目：
 *  	•	一个顶点在这个三元组内；
 *  	•	另一个顶点不在这个三元组内。
 *
 * Input:
 *  第 1 行，两个正整数 n,m。
 *  接下来 m 行，每行两个整数 u,v，表示一条边。
 *
 * Output:
 *  一行，一个整数，表示答案。
 *
 * Hints:
 *  1≤n≤400,1≤m≤n(n-1)/2,1≤u,v≤n, 保证图中不存在重边和自环。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
6 6
1 2
1 3
3 2
4 1
5 2
3 6
 *
 *  output:
3
 *
 *  2):
 *  input:
7 8
1 3
4 1
4 3
2 5
5 6
6 7
7 5
2 6
 *
 *  output:
0
 *
 */

#include <iostream>
using namespace std;
int n, m, g[410][410], d[410], ans = 1e9;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u][v] = g[v][u] = 1;
        d[u]++;
        d[v]++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                if (g[i][j] && g[i][k] && g[j][k]) {
                    ans = min(ans, d[i] + d[j] + d[k] - 6);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}