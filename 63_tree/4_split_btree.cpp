/**
 * Description:
 *  给定一个 n 个结点的二叉树，每个结点的序号为 [1,n] 中的互不相同的正整数，根结点的序号为 1，每个结点具有权值。
 *  如果在二叉树中删除一条边，则二叉树会分裂成两棵子树，定义子树和为两棵子树各自结点的权值之和。求分裂后两棵子树和的乘积的最大值。
 *
 * Input:
 *  第 1 行，一个正整数 n。
 *  第 2 行，n 个正整数 ai，表示结点 i 的权值。
 *  接下来 n 行，第 i(1≤i≤n) 行两个整数 li,ri，表示第 i 个结点的左儿子和右儿子的编号。
 *  若某个结点在树中没有左儿子，则对应的左儿子编号为 0，右儿子缺失时同理。
 *
 * Output:
 *  一行，一个整数，表示结果。
 *
 * Hints:
 *  2≤n≤5×10<4>,0≤li,ri≤n,1≤ai≤10<4>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
6
1 2 3 4 5 6
2 3
4 5
6 0
0 0
0 0
0 0
 *
 *  output:
110
 *
 *  2):
 *  input:
6
1 2 3 4 5 6
0 2
3 4
0 0
5 6
0 0
0 0
 *
 *  output:
90
 *
 */

#include <iostream>
using namespace std;
const int N = 5e4 + 10;
int n, w[N], fa[N], lc[N], rc[N], s[N], sum;

int dfs(int x)
{
    s[x] = w[x];
    if (lc[x]) {
        s[x] += dfs(lc[x]);
    }
    if (rc[x]) {
        s[x] += dfs(rc[x]);
    }
    return s[x];
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        sum += w[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> lc[i] >> rc[i];
        if (lc[i]) {
            fa[lc[i]] = i;
        }
        if (rc[i]) {
            fa[rc[i]] = i;
        }
    }
    dfs(1);
    long long ans = 0;
    for (int i = 2; i <= n; i++) {
        ans = max(ans, 1ll * s[i] * (sum - s[i]));
    }
    cout << ans << endl;
    return 0;
}