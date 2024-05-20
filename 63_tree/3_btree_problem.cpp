/**
 * Description:
 *  如下图所示的一棵二叉树的深度、宽度及结点间距离分别为：
 *  深度：4（二叉树节点到根的层数的最大值）
 *  宽度：4（同一层最多结点个数）
 *  结点间距离：
 *  ⑧→⑥为5 (⑧→⑤→②→①→③→⑥)
 *  ⑥→⑦为2 (⑥→③→⑦)
 *  注：结点间距离的定义：由结点向根方向（上行方向）时的边数与由根向叶结点方向（下行方向）时的边数之和。
 *  现在给定你一棵二叉树和树上两个结点u,v，请你求出树的深度、宽度和结点u到结点v的距离。
 *
 * Input:
 *  输入第一行为一个整数n(1≤n≤10<5>)，表示二叉树结点个数。
 *  接下来的n−1行，每行两个整数x,y，表示结点x与结点y有直接连边（约定根结点编号为1）。
 *  最后一行两个整数u,v。
 *
 * Output:
 *  三个数，每个数占一行，依次表示给定二叉树的深度、宽度以及结点u到结点v的距离。
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
10
1 2
1 3
2 4
2 5
3 6
3 7
5 8
5 9
6 10
8 6
 *
 *  output:
4
4
5
 *
 */

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std; const int N = 1e5 + 10;
int n, u, v, ch[N][5], cnt[N], w[N], fa[N], d[N], vis[N], maxd, maxw;

void dfs(int x, int fx)
{
    vis[x] = 1;
    fa[x] = fx;
    d[x] = d[fx] + 1;
    maxd = max(maxd, d[x]);
    maxw = max(maxw, ++w[d[x]]);
    for (int i = 1; i <= cnt[x]; i++) {
        if (!vis[ch[x][i]]) {
            dfs(ch[x][i], x);
        }
    }
}

int getdis(int x, int y)
{
    int ans = 0;
    while (x != y) {
        if (d[x] >= d[y]) {
            x = fa[x];
        } else if (d[x] < d[y]) {
            y = fa[y];
        }
        ans++;
    }
    return ans;
}

int main()
{
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        ch[u][++cnt[u]] = v;
        ch[v][++cnt[v]] = u;
    }
    cin >> u >> v;
    dfs(1, 0);
    cout << maxd << endl
         << maxw << endl;
    cout << getdis(u, v) << endl;
    return 0;
}