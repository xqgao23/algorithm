/**
 * Description:
 *  给出每个节点的两个儿子节点，建立一棵二叉树，如果是叶子节点，则输入"0 0"。建好树后希望知道这棵二叉树的深度。二叉树的深度是指从根节点到叶子结点时，经过的层数。
 *  最多有 10<6> 个结点。
 *
 * Input:
 *  输入文件共 n+1 行，第一行输入一个正整数n，表示二叉树的节点数。
 *  接下来的n行每行两个数，第i+1行表示编号为i的节点的左儿子与右儿子。
 *
 * Output:
 *  输出一行，共一个整数，表示这棵二叉树的深度。
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
7
2 7
3 6
4 5
0 0
0 0
0 0
0 0
 *
 *  output:
4
 *
 */

#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int n, fa[N], lc[N], rc[N], d[N];

void dfs(int x)
{
    d[x] = d[fa[x]] + 1;
    if (lc[x]) {
        dfs(lc[x]);
    }
    if (rc[x]) {
        dfs(rc[x]);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> lc[i] >> rc[i];
        if (lc[i]) {
            fa[lc[i]] = i;
        }
        if (rc[i]) {
            fa[rc[i]] = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (fa[i] == 0) {
            dfs(i);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, d[i]);
    }
    cout << ans << endl;
    return 0;
}