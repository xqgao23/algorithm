/**
 * Description:
 *  有一个长度为 n 的序列 a1,a2,…,an，请你按顺序处理一系列指令。指令共有两种类型：
 *  1）Q  i  j  k，表示一个询问指令，请你在ai, ai+1,ai+2, … aj中找到其中第k小的数（1≤i≤j≤n，1≤k≤j−i+1）；
 *  2）C  i  t，表示一个修改指令，请你将ai 的值修改为 t（1≤i≤n，0≤t≤10<9>）
 *
 * Input:
 *  第一行有两个正整数n,m，分别表示序列的长度和指令的个数。
 *  第二行有n个数，表示a1,a2,…,an，这些数的绝对值都小于10<9>
 *  接下来的m行描述每条指令Q  i  j  k 或者 C  i  t。
 *
 * Output:
 *  对于每一次询问，你都需要输出他的答案，每一个输出占单独的一行。
 *
 * Hints:
 *  1≤n,m≤10000。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5 3
3 2 1 4 7
Q 1 4 3
C 2 6
Q 2 5 3
 *
 *  output:
3
6
 *
 */

#include <iostream>
using namespace std;
int n, m, a[10010], b[10010];

int find_kth(int a[], int l, int r, int k)
{
    if (l >= r) {
        return a[l];
    }
    int i = l - 1, j = r + 1, x = a[(l + r) >> 1];
    while (i < j) {
        while (a[++i] < x)
            ;
        while (a[--j] > x)
            ;
        if (i < j) {
            swap(a[i], a[j]);
        }
    }
    if (j - l + 1 >= k) {
        return find_kth(a, l, j, k);
    }
    return find_kth(a, j + 1, r, k - (j - l + 1));
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    while (m--) {
        char op;
        int i, j, t, k;
        cin >> op;
        if (op == 'Q') {
            cin >> i >> j >> k;
            for (int x = i; x <= j; x++) {
                b[x] = a[x];
            }
            cout << find_kth(b, i, j, k) << endl;
        } else {
            cin >> i >> t;
            a[i] = t;
        }
    }
    return 0;
}