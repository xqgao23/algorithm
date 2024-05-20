/**
 * Description:
 *  给定一个 n 个结点的二叉树，每个结点的序号为 [1,n] 中的互不相同的正整数，根结点的序号为 1。
 *  求该二叉树的层次遍历。
 *
 * Input:
 *  第 1 行，一个正整数 n。
 *  接下来 n 行，第 i(1≤i≤n) 行两个整数 li,ri，表示第 i 个结点的左儿子和右儿子的编号。
 *  若某个结点在树中没有左儿子，则对应的左儿子编号为 0，右儿子缺失时同理
 *
 * Output:
 *  输出若干行，其中第 i 行应当将二叉树中深度为 i 的所有结点从左到右输出编号，用空格隔开。
 *
 * Hints:
 *  1≤n≤10<4>,0≤li,ri≤n
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5
4 5
0 0
0 0
2 0
3 0
 *
 *  output:
1
4 5
2 3
 *
 */

#include <iostream>
#include <queue>
using namespace std;
const int N = 1e4 + 10;
int n, fa[N], lc[N], rc[N], d[N];

void bfs(int r)
{
    queue<int> q;
    q.push(r);
    d[r] = 1;
    int now = 1;
    while (q.size()) {
        int x = q.front();
        q.pop();
        if (d[x] != now) {
            puts("");
        }
        now = d[x];
        cout << x << " ";
        if (lc[x]) {
            d[lc[x]] = d[x] + 1;
            q.push(lc[x]);
        }
        if (rc[x]) {
            d[rc[x]] = d[x] + 1;
            q.push(rc[x]);
        }
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
    bfs(1);
    return 0;
}