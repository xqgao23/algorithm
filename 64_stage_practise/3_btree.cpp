/**
 * Description:
 *  二叉树有先序、中序、后序、按层遍历等遍历顺序，给定中序和其它一种遍历的序列就可以确定一棵二叉树的结构。
 *  假定一棵二叉树一个结点用一个字符描述，现在给出中序和按层遍历的字符串，求该树的先序遍历字符串。
 *
 * Input:
 *  两行，每行是由字母组成的字符串（同一行的每个字符都只出现一次，并且两行字符种类完全相同），分别表示二叉树的中序遍历和按层遍历的序列，保证代表的是一棵正确的二叉树。
 *
 * Output:
 *  一行，表示二叉树的先序序列。
 *
 * Hints:
 *  1≤n,m≤10000。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
DBEAC
ABCDE
 *
 *  output:
ABDEC
 *
 */

#include <iostream>
using namespace std;

void dfs(string s, string t)
{
    if (s == "") {
        return;
    }
    int k;
    for (int i = 0; i < t.size(); i++) {
        k = s.find(t[i]);
        if (k != -1) {
            break;
        }
    }
    cout << s[k];
    dfs(s.substr(0, k), t);
    dfs(s.substr(k + 1), t);
}

int main()
{
    string s, t;
    cin >> s >> t;
    dfs(s, t);
    return 0;
}