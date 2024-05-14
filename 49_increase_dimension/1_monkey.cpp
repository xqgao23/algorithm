/**
 * Description:
 *  小猴面前有 n 个糖果排成一行，从左到右第 i 个糖的价值是 ai。
 *  小猴打算拿走一些糖，但是他不愿意拿走两个相邻的糖。
 *  你要求出，在不同时拿走任意相邻的糖的前提下，小猴最多能拿走多少价值的糖？
 *
 * Input:
 *  第一行一个整数T，表示有T(1≤T≤50)组数据。
 *  接下来的每组数据，第一行是一个整数N(1≤n≤10<5>)，表示一共有n个糖。
 *  第二行是n个被空格分开的正整数，表示每个糖的价值，不超过1000。
 *  输入量较大，请使用scanf或者cin关闭流同步。
 *
 * Output:
 *  对于每组数据，输出一行。
 *  该行包括一个整数，表示在不同时拿走任意相邻的糖的前提下，最多能拿走的糖的价值。
 *
 * Hints:
 *  1≤T≤50, 1≤N≤10<5>, 每个糖的价值不超过1000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
2
3
1 8 2
4
10 7 6 14
 *
 *  output:
8
24
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int t, n, a[100010], f[100010][2];

int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            f[i][1] = f[i - 1][0] + a[i];
        }
        cout << max(f[n][0], f[n][1]) << endl;
    }
    return 0;
}