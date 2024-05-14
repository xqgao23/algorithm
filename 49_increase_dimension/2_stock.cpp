/**
 * Description:
 *  给定一支股票接下来n天的价格，设计一个算法计算出最大的利润。
 *  每天你可以进行买入或者卖出，或者不进行任何操作，但是需要遵守以下条件：
 *      . 你不能同时参与多笔交易（你必须在再次买入前卖出之前的股票）。
 *  	. 卖出股票后，你无法在第二天买入股票 (即冷冻期为1天)。
 *
 * Input:
 *  第一行一个整数n(1≤n≤10<5>)，表示一共有n天。
 *  第二行一共有n个整数ai(1≤ai≤10<9>)，表示第i天的价格。
 *
 * Output:
 *  输出一行，包含一个整数，表示最大的利润。
 *
 * Hints:
 *  1≤n≤10<5>, 1≤ai≤10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5
1 2 3 0 2
 *
 *  output:
3
 *
 */

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int n, a[100010];
long long f[100010][3];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(f, -0x3f, sizeof f);
    f[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        f[i][0] = max(f[i - 1][0], f[i - 1][1] - a[i]);
        f[i][1] = max(f[i - 1][1], f[i - 1][2]);
        f[i][2] = f[i - 1][0] + a[i];
    }
    cout << max(f[n][1], f[n][2]) << endl;
    return 0;
}