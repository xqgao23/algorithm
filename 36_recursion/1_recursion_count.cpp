/**
 * Description:
 *  小猴要上一个n级的台阶, 他一次可以上1级台阶, 也可以一次上2级台阶. 问他上n级台阶有多少种方法?
 *
 * Input:
 *  一个整数n
 *
 * Output:
 *  输出上n级台阶的方法数
 *
 * Hints:
 *  1≤n≤30
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3
 *
 *  output:
3
 *
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
int f[50]; // f[n]表示上n级台阶的方法数

int main()
{
    int n;
    cin >> n;
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    cout << f[n] << endl;
    return 0;
}