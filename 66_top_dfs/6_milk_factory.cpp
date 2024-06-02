/**
 * Description:
 *  牛奶生意正红红火火！Farmer John 的牛奶加工厂内有 N 个加工站，编号为 1…N（1≤N≤100），以及 N−1 条通道，每条连接某两个加工站。（通道建设很昂贵，所以 Farmer John 选择使用了最小数量的通道，使得从每个加工站出发都可以到达所有其他加工站）。
 *  为了创新和提升效率，Farmer John 在每条通道上安装了传送带。不幸的是，当他意识到传送带是单向的已经太晚了，现在每条通道只能沿着一个方向通行了！所以现在的情况不再是从每个加工站出发都能够到达其他加工站了。
 *  然而，Farmer John 认为事情可能还不算完全失败，只要至少还存在一个加工站 i 满足从其他每个加工站出发都可以到达加工站 i。注意从其他任意一个加工站 j 前往加工站 i 可能会经过 i 和 j 之间的一些中间站点。请帮助 Farmer John 求出是否存在这样的加工站 i。
 *
 * Input:
 *  输入的第一行包含一个整数 N，为加工站的数量。以下 N−1 行每行包含两个空格分隔的整数 ai 和 bi，满足 1≤ai,bi≤N 以及ai≠bi。这表示有一条从加工站 ai 向加工站 bi 移动的传送带，仅允许沿从 ai 到 bi 的方向移动。
 *
 * Output:
 *  如果存在加工站 i 满足可以从任意其他加工站出发都可以到达加工站 i，输出最小的满足条件的 i。否则，输出 −1。
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3
1 2
3 2
 *
 *  output:
2
 *
 */

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int N = 110;
int n, vis[110], cnt;
vector<int> g[110];

void dfs(int x)
{
    vis[x] = 1;
    cnt++;
    for (int i = 0; i < g[x].size(); i++) {
        int y = g[x][i];
        if (vis[y]) {
            continue;
        }
        dfs(y);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof vis);
        cnt = 0;
        dfs(i);
        if (cnt == n) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}