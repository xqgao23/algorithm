/**
 * Description:
 *  树的凹入表示法主要用于树的屏幕或打印输出，其表示的基本思想是兄弟间等长，一个结点的长度要不小于其子结点的长度。二叉树也可以这样表示，假设叶结点的长度为1，一个非叶结点的长度等于它的左右子树的长度之和。
 *  一棵二叉树的一个结点用一个字母表示（无重复），输出时从根结点开始：
 *  每行输出若干个结点字符（相同字符的个数等于该结点长度），
 *  如果该结点有左子树就递归输出左子树；
 *  如果该结点有右子树就递归输出右子树。
 *  假定一棵二叉树一个结点用一个字符描述，现在给出先序和中序遍历的字符串，用树的凹入表示法输出该二叉树
 *
 * Input:
 *  两行，每行是由字母组成的字符串（一行的每个字符都是唯一的），分别表示二叉树的先序遍历和中序遍历的序列。
 *
 * Output:
 *  行数等于该树的结点数，每行的字母相同。
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
ABCDEFG
CBDAFEG
 *
 *  output:
AAAA
BB
C
D
EE
F
G
 *
 */

#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int f[N];

int dfs(string a, string b)
{
    if (a == "") {
        return 0;
    }
    if (a.size() == 1) {
        return f[a[0]] = 1;
    }
    char ch = a[0];
    int k = b.find(ch);
    f[ch] += dfs(a.substr(1, k), b.substr(0, k));
    f[ch] += dfs(a.substr(k + 1), b.substr(k + 1));
    return f[ch];
}

int main()
{
    string a, b;
    cin >> a >> b;
    dfs(a, b);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 1; j <= f[a[i]]; j++) {
            cout << a[i];
        }
        cout << endl;
    }
    return 0;
}