/**
 * Description:
 *  给定一个 n 个结点的树，结点编号从 1 到 n，树的根结点为 1 号结点。
 *  由于树中结点需要施工，因此一些结点通行受限。用 ai 来表示每个结点能否通行，ai=1 表示可以通过，ai=0 表示无法通过。
 *  在不通过受限结点的前提下，求从根结点 1 出发，最多能够到达多少结点。保证根结点 1 不会受限。
 *
 * Input:
 *  第 1 行，两个正整数 n。
 *  第 2 行，n 个正整数 ai
 *  接下来 n−1 行，第 i(1≤i≤n) 行两个整数 u,v，表示树中的一条边。
 *
 * Output:
 *  一行，一个整数，表示答案。
 *
 * Hints:
 *  1≤n≤1000, 1≤u,v≤n, 0≤ai≤1,
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
7
1 1 1 1 0 0 1
1 2
2 3
4 2
5 1
1 6
6 7
 *
 *  output:
4
 *
 *  2):
 *  input:
7
1 0 0 1 0 1 1
1 2
1 3
1 6
1 5
4 3
7 6
 *
 *  output:
3
 *
 */

#include <iostream>
using namespace std;
int n, a[1010], ch[1010][1010], cnt[1010], vis[1010], ans;

void dfs(int x)
{
    ans++;
    vis[x] = 1;
    for (int i = 1; i <= cnt[x]; i++) {
        if (!vis[ch[x][i]] && a[ch[x][i]]) {
            dfs(ch[x][i]);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        ch[u][++cnt[u]] = v;
        ch[v][++cnt[v]] = u;
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}