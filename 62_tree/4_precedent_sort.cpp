/**
 * Description:
 *  给出一棵二叉树的中序与后序排列。求出它的先序排列。（约定树结点用不同的大写字母表示，长度≤26）。
 *
 * Input:
 *  2行，均为大写字母组成的字符串，表示一棵二叉树的中序与后序排列。
 *
 * Output:
 *  1行，表示一棵二叉树的先序。
 *
 * Hints:
 *  树的根节点可能是任意字母。输入保证只有一棵二叉树。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
BADC
BDCA
 *
 *  output:
ABCD
 *
 */

#include <iostream>
using namespace std;

void dfs(string a, string b)
{
    if (a == "") {
        return;
    }
    char ch = b[b.size() - 1];
    cout << ch;
    int k = a.find(ch);
    dfs(a.substr(0, k), b.substr(0, k));
    dfs(a.substr(k + 1), b.substr(k, b.size() - k - 1));
}

int main()
{
    string a, b;
    cin >> a >> b;
    dfs(a, b);
    return 0;
}