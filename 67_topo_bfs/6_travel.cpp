/**
 * Description:
 *  AtCoder 国家包括编号 1∼n 的 n 个城市和编号为 1∼m 的 m 条的单向道路。
 *  通过道路 i 可以从城市 ai 移动到 bi ，但是不能通过道路 i 从都市 bi 到都市 ai 。彪马打算从某个城市为起点开始旅行，使用 0 条及以上的道路移动，最终到达某个城市作为终点。
 *  作为起点和终点的城市组合，一共有几种？
 *
 * Input:
 *  第1行，两个正整数 n,m。
 *  接下来 m 行，每行两个正整数 ai, bi。表示从城市 ai 到城市 bi 有一条单向道路。
 *
 * Output:
 *  输出一行，包含一个正整数，表示作为起点和终点的城市组合的种数。
 *
 * Hints:
 *  1≤n<2000, 1≤m≤min(2000, n(n-1)), 1≤ai,bi≤n ai != bi
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 3
1 2
2 3
3 2
 *
 *  output:
7
 *
 */

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 2010;
int n, m, vis[N], cnt, ans;
vector<int> g[N];

void dfs(int x)
{
    if (vis[x]) {
        return;
    }
    vis[x] = 1;
    cnt++;
    for (auto y : g[x]) {
        dfs(y);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof vis);
        cnt = 0;
        dfs(i);
        ans += cnt;
    }
    cout << ans << endl;
    return 0;
}