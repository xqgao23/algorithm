/**
 * Description:
 *  勤奋又善于思考的小L接触了信息学竞赛，开始的学习十分顺利。但是，小L卡在了二叉树上。
 *  在计算机科学中，二叉树是每个结点最多有两个子结点的有序树。通常子结点被称作"左孩子"和"右孩子"。
 *  二叉搜索树首先是一棵二叉树。
 *  设key[p]表示结点p上的数值，对于其中的每个结点p，若其存在左孩子lch，则key[p]≥key[lch]；若其存在右孩子rch，则key[p]≤key[rch]；
 *  注意，本题中的二叉搜索树应满足对于所有结点，其左子树中的key小于等于当前结点的key，其右子树中的key大于等于当前结点的key。
 *  可是善于思考的小L不甘于只学习这些基础的东西。他思考了这样一个问题：现在给定一棵二叉树，可以任意修改结点的数值。修改一个结点的数值算作一次修改，且这个结点不能再被修改。若要将其变成一棵二叉搜索树，且任意时刻结点的数值必须是整数（可以是负整数或0），所要的最少修改次数。
 *
 * Input:
 *  第一行一个正整数n表示二叉树节点数。
 *  第二行n个正整数用空格分隔开，第i个数ai表示结点i的原始数值。
 *  此后n−1行每行两个非负整数fa,ch，第i+2行描述结点i+1的父亲编号fa，以及父子关系ch，(ch=0 表示i+1为左儿子，ch=1表示i+1为右儿子)。
 *  为了让你稍微减轻些负担，小L规定：结点1一定是二叉树的根哦！
 *
 * Output:
 *  一个整数，表示最少的修改次数。
 *
 * Hints:
 *  N≤100000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3
2 2 2
1 0
1 1
 *
 *  output:
0
 *
 *  2):
 *  input:
5
3 2 1 4 5
4 0
2 0
1 0
4 1
 *
 *  output:
1
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int n, lc[N], rc[N], a[N], b[N], m;

void dfs(int x)
{
    if (lc[x]) {
        dfs(lc[x]);
    }
    b[++m] = a[x];
    if (rc[x]) {
        dfs(rc[x]);
    }
}

int LIS()
{
    int len = 0;
    for (int i = 1; i <= n; i++) {
        if (b[i] >= a[len]) {
            a[++len] = b[i];
        } else {
            int p = upper_bound(a + 1, a + len + 1, b[i]) - a;
            a[p] = b[i];
        }
    }
    return n - len;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++) {
        int fa, ch;
        cin >> fa >> ch;
        if (ch) {
            rc[fa] = i;
        } else {
            lc[fa] = i;
        }
    }
    dfs(1);
    cout << LIS() << endl;
    return 0;
}