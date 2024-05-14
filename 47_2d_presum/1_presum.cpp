/**
 * Description:
 *  输入一个长度为n的整数序列。
 *  接下来输入m 个操作，每个操作包含三个整数l,r,c，表示将序列中[l,r]之间的每个数加上c。
 *  请你输出进行完所有操作后的序列。
 *
 * Input:
 *  第一行两个整数n和m
 *  第二行包含n个整数ai，表示整数序列
 *  接下来m行，每行三个整数l,r,c，表示一个操作
 *
 * Output:
 *  共一行，包括n个整数，表示最终的序列
 *
 * Hints:
 *  1≤n,m≤1000000, 1≤l≤r≤n, -1000≤c,ai≤1000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
6 3
1 2 2 1 2 1
1 3 1
3 5 1
1 6 1
 *
 *  output:
3 4 5 3 4 2
 *
 */

#include <iostream>
using namespace std;
int n, m, a[100010], d[100010];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = a[i] - a[i - 1];
    }
    while (m--) {
        int l, r, c;
        cin >> l >> r >> c;
        d[l] += c;
        d[r + 1] -= c;
    }
    for (int i = 1; i <= n; i++) {
        d[i] += d[i - 1];
        cout << d[i] << " ";
    }
    return 0;
}