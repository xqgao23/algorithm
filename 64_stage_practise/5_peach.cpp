/**
 * Description:
 *  皮皮是一只很爱爬树的猴子，他最喜欢爬桃子树。
 *  皮皮家的桃子树被修剪成了一棵二叉树，1号点是桃子树的根结点，其中第i个结点结了ai个桃子。
 *  皮皮爬桃子树时，只会选一条树上路径，从树上任意一个结点出发（皮皮有梯子），沿着树上路径前进，最后在树上任意一个结点停下来，然后把经过的所有结点的桃子都摘下来（每个点最多经过一次）。皮皮想知道，他一次最多能摘下多少个桃子。
 *
 * Input:
 *  第一行一个整数n，表示桃子树的结点个数。
 *  第 2 到 n+1 行，第 i+1 行三个整数，ai,li,ri，表示结点 i 的桃子数量，结点 i 的左儿子，结点 i 的右儿子，如果没有对应结点则为 0。
 *
 * Output:
 *  输出一行一个整数，表示皮皮一次最多能摘多少桃子。
 *
 * Hints:
 *  1≤ai≤10<9>。n≤10<5>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
6
1 2 3
1 0 0
3 4 6
2 5 0
1 0 0
4 0 0
 *
 *  output:
10
 *
 */

#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int n, a[N], lc[N], rc[N];
long long val[N], ans;

void dfs(int x)
{
    if (lc[x]) {
        dfs(lc[x]);
    }
    if (rc[x]) {
        dfs(rc[x]);
    }
    ans = max(ans, val[lc[x]] + val[rc[x]] + a[x]);
    val[x] = max(val[lc[x]], val[rc[x]]) + a[x];
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> lc[i] >> rc[i];
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}