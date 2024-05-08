/**
 * Description:
 *  考虑只由数码1,3,4组成的正整数, 在这样的正整数中, 数码和恰好为n的有多少个?
 *
 * Input:
 *  一个整数n
 *
 * Output:
 *  输出个数
 *
 * Hints:
 *  1≤n≤30
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4
 *
 *  output:
4
 *
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
int f[50]; // f[n]表示只由1,3,4组成的数码和为n的数的个数

int main()
{
    int n;
    cin >> n;
    f[1] = 1;
    f[2] = 1;
    f[3] = 2;
    f[4] = 4;
    for (int i = 5; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 3] + f[i - 4];
    }
    cout << f[n] << endl;
    return 0;
}