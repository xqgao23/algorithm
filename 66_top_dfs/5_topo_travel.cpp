/**
 * Description:
 *  给出N个点，M条边的有向图，对于每个点v，求A(v)表示从点v出发，能到达的编号最大的点。
 *
 * Input:
 *  第1 行，2 个整数N,M。
 *  接下来M行，每行2个整数Ui,Vi，表示边(Ui,Vi)。点用1,2,⋯,N编号。
 *
 * Output:
 *  N 个整数A(1),A(2),⋯,A(N)。
 *
 * Hints:
 *  1≤N,M≤10<5>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4 3
1 2
2 4
4 3
 *
 *  output:
4 4 3 4
 *
 */

#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
int n, m, ans[N];
vector<int> g[N];

void dfs(int x, int u)
{
    if (ans[x]) {
        return;
    }
    ans[x] = u;
    for (int i = 0; i < g[x].size(); i++) {
        int y = g[x][i];
        dfs(y, u);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[v].push_back(u);
    }
    for (int i = n; i >= 1; i--) {
        dfs(i, i);
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}