/**
 * Description:
 *  输入整数 a,b,p，计算 a<b> 除以 p 的余数
 *
 * Input:
 *  a, b, p
 *
 * Output:
 *  a<b> 除以 p 的余数
 *
 * Hints:
 *  1≤a,p≤10<9>
 *  0≤b≤10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
2 12 7
 *
 *  output:
1
 *
 *  2):
 *  input:
2 1000000000 998244355
 *
 *  output:
340515086
 *
 */

#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;
typedef long long LL;

LL ksm(LL a, LL b, LL p)
{
    LL ans = 1 % p;
    while (b) {
        if (b & 1) {
            ans = ans * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

int main()
{
    int a, b, p;
    cin >> a >> b >> p;
    cout << ksm(a, b, p) << endl;
    return 0;
}