/**
 * Description:
 *  输入一串二叉树，输出其前序遍历。
 *
 * Input:
 *  第一行为二叉树的节点数 n。(1≤n≤26)
 *  后面 n 行，每一个字母为节点，后两个字母分别为其左右儿子。
 *  空节点用 '*' 表示
 *
 * Output:
 *  二叉树的前序遍历。
 *
 * Hints:
 *  树的根节点可能是任意字母。输入保证只有一棵二叉树。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
6
abc
bdi
cj*
d**
i**
j**
 *
 *  output:
abdicj
 *
 */

#include <iostream>
using namespace std;
const int N = 130;
int n, vis[N];
char fa[N], lc[N], rc[N];

void dfs(char x)
{
    cout << x;
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
        char a, b, c;
        cin >> a >> b >> c;
        vis[a] = 1;
        if (b != '*') {
            fa[b] = a, lc[a] = b;
        }
        if (c != '*') {
            fa[c] = a, rc[a] = c;
        }
    }
    for (int i = 'a'; i <= 'z'; i++) {
        if (fa[i] == 0 && vis[i]) {
            dfs(i);
            break;
        }
    }
    return 0;
}