/**
 * Description:
 *  给定一个 n 个结点的二叉树，每个结点的序号为 [1,n] 中的互不相同的正整数，根结点的序号为 1。
 *  想象自己站在二叉树的正右侧，按照从顶部到底部的顺序，求从右侧能看到的结点。
 *
 * Input:
 *  第 1 行，一个正整数 n。
 *  接下来 n 行，第 i(1≤i≤n) 行两个整数 li,ri，表示第 i 个结点的左儿子和右儿子的编号。
 *  若某个结点在树中没有左儿子，则对应的左儿子编号为 0，右儿子缺失时同理。
 *
 * Output:
 *  输出若干行，其中第 i 行输出一个整数，表示在二叉树深度为i 的那一层中，最右侧可见的结点。
 *
 * Hints:
 *  1≤n≤10000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
7
2 3
4 0
6 7
5 0
0 0
0 0
0 0
 *
 *  output:
1
3
7
5
 *
 */

// 深搜
#include <iostream>
using namespace std;
const int N = 1e4 + 10;
int n, lc[N], rc[N], ans[N], maxd;

void dfs(int x, int d)
{
    maxd = max(maxd, d);
    ans[d] = x;
    if (lc[x]) {
        dfs(lc[x], d + 1);
    }
    if (rc[x]) {
        dfs(rc[x], d + 1);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> lc[i] >> rc[i];
    }
    dfs(1, 1);
    for (int i = 1; i <= maxd; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}