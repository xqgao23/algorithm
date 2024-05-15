/**
 * Description:
 *  在 2202 年的某一天，小明得到了一个高端 U 盘。
 *  但是小明发现这个 U 盘有一些问题：
 *  这个 U 盘的传输接口大小是 L，只能传输大小不超过 L 的文件。
 *  这个 U 盘容量是 S，一共只能装不超过 S 的文件。
 *  但是他要备份的资料却有很多，你只能备份其中的一部分。
 *  共有 n 个文件，第 i 个文件的大小和价值为 wi,vi。小明很快发现他不可能把所有文件装进优盘，好在这是一个高端的 U 盘，他可以花钱升级接口大小、或者升级容量。每花 1 元可以将接口大小增加 1，每花 1 元可以将 U 盘容量增加 1。
 *  注意：你的文件不能被分割（你只能把一个文件整个的传输进去，并储存在U盘中）, 你放在 U 盘中文件的总大小不能超过 U 盘容量。
 *  现在问题来了：小明只有 m 元，他想知道，他最多可能将多大价值的文件放入 U 盘中。
 *
 * Input:
 *  第1行，4个正整数 n,m,L,S。
 *  第2行，n 个正整数 w1,w2,...,2n.
 *  第3行，n 个正整数v1,v2,...,vn.
 *
 * Output:
 *  1个整数，最多可以放入 U 盘的文件总价值。
 *
 * Hints:
 *  1≤n≤500, 1≤S,m≤10000, 1≤wi,L≤1000, 1≤vi≤10000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5 9 4 4
6 9 9 5 6
8 7 9 1 5
 *
 *  output:
9
 *
 *  2):
 *  input:
5 9 8 9
7 6 5 5 1
4 2 6 4 2
 *
 *  output:
16
 *
 *  3):
 *  input:
8 13 7 17
8 10 9 12 5 13 6 11
1 4 12 2 2 4 15 2
 *
 *  output:
31
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
struct node {
    int w, v;
} a[510];
int n, m, L, S, f[510][20010];

bool cmp(node x, node y)
{
    return x.w < y.w;
}

int main()
{
    cin >> n >> m >> L >> S;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].w;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i].v;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= S + m; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= a[i].w) {
                f[i][j] = max(f[i][j], f[i - 1][j - a[i].w] + a[i].v);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int c = max(a[i].w - L, 0);
        if (c > m) {
            break;
        }
        ans = max(ans, f[i][S + m - c]);
    }
    cout << ans << endl;
    return 0;
}