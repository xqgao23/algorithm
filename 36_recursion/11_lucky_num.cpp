/**
 * Description:
 *  据说，每个人都有自己的幸运数字，小D也不例外。小D认为，如果某个非负整数恰好包含偶数个 1（包括 0 个），那么这个数字就是他的幸运数字。现在，小D想知道，在长度为 N 的非负整数中，一共有多少个属于他的幸运数字。 你能帮他计算一下吗？
 *  注意：本题中长度为 N 的非负整数，指长度为 N 但不包含多余前导 0 的非负整数，例如长度为 2 的非负整数共有 90 个，数值范围 10∼99。
 *
 * Input:
 *  只有一行，包括一个整数 N，表示幸运数字的长度。
 *
 * Output:
 *  只有一行，包括一个整数，表示长度为 N 的非负整数中恰好包含偶数个 1 的数字个数除以10<9>+7的余数。
 *
 * Hints:
 *  1≤N≤10000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
2
 *
 *  output:
73
 *
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
LL x[10010], y[10010], mod = 1e9 + 7;
// x[n]表示包含偶数个1的n位数的个数
// y[n]表示包含奇数个1的n位数的个数

int main()
{
    int n;
    cin >> n;
    x[1] = 8;
    y[1] = 1;
    for (int i = 2; i <= n; i++) {
        x[i] = (x[i - 1] * 9 + y[i - 1]) % mod;
        y[i] = (x[i - 1] + y[i - 1] * 9) % mod;
    }
    x[1] = 9;
    cout << x[n] << endl;
    return 0;
}