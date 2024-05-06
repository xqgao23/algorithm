/**
 * Description:
 *  给出正整数a,b，计算分数a/b化成十进制小数后，小数点后第k位的数码。
 *
 * Input:
 *  输入包含多组数据
 *  第1行，1个正整数T表示有T组测试数据
 *  接下来T行，每行3个整数a,b,k
 *
 * Output:
 *  输出T行，对于每组数据，输出a/b小数点后第k位
 *
 * Hints:
 *  1≤T≤1000, 1≤a,b≤10<9>, 1≤k≤10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4
1 7 2
1 65536 5
7 91 200
1 998244353 998244352
 *
 *  output:
4
1
7
3
 *
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;
int t, a, b, k;

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
    cin >> t;
    while (t--) {
        cin >> a >> b >> k;
        cout << a * ksm(10, k - 1, b) % b * 10 / b << endl;
    }
    return 0;
}