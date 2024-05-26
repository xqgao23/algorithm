/**
 * Description:
 *  输入一个n个结点的无向图以及某个结点k，结点1代表消防站，结点k代表着火的街区。
 *  按照字典序从小到大顺序输出从结点1到结点k的所有路径，要求结点不能重复经过。
 *
 * Input:
 *  第1行，3个正整数n,k,m
 *  接下来m行，每行两个正整数a,b，表示结点a和b之间有一条道路。
 *
 * Output:
 *  输出若干行，每行输出一条从结点1到结点k的路径，每条路径要求将中途经过的结点按顺序输出，结点编号之间用空格分隔（起点1和终点k也要输出）。
 *  最后一行，输出一个整数，表示所有可以到达结点k的不同路径数
 *
 * Hints:
 *  1≤k≤n≤20,1≤m≤n(n+1)/2,保证从结点1能够通过若干条道路到达结点k
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
6 6 8
1 2
1 3
3 4
3 5
4 6
5 6
2 3
2 4
 *
 *  output:
1 2 3 4 6
1 2 3 5 6
1 2 4 3 5 6
1 2 4 6
1 3 2 4 6
1 3 4 6
1 3 5 6
7
 *
 */

#include <iostream>
using namespace std;
int n, k, m, g[25][25], p[25], vis[25], ans;

void dfs(int x, int c)
{
    p[c] = x;
    if (x == k) {
        ans++;
        for (int i = 1; i <= c; i++) {
            cout << p[i] << " ";
        }
        cout << endl;
        return;
    }
    vis[x] = 1;
    for (int i = 1; i <= n; i++) {
        if (g[x][i] && !vis[i]) {
            dfs(i, c + 1);
        }
    }
    vis[x] = 0;
}

int main()
{
    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x][y] = g[y][x] = 1;
    }
    dfs(1, 1);
    cout << ans << endl;
    return 0;
}