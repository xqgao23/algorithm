/**
 * Description:
 *  BSNY在学等差数列和等比数列，当已知前三项时，就可以知道是等差数列还是等比数列。现在给你数列的前三项，已知这个数列要么是等差数列，要么是等比数列。请你求出第
 * k 项的值，输出对200907取模后的结果。
 *
 * Input:
 *  输入包含多组数据
 *  第1行，1个正整数T表示有T组测试数据
 *  接下来T行，每行4个整数a,b,c,k, 表示数列前三项依次为 a,b,c，要求第 k 项
 *
 * Output:
 *  输出T行，对于每组数据，输出数列第 k 项对200907取模后的结果
 *
 * Hints:
 *  1≤T≤100, 1≤a≤b≤c≤10<9>, 0<k≤10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
2
1 2 3 5
1 2 4 5
 *
 *  output:
5
16
 *
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;
LL t, a, b, c, k, mod = 200907;

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
        cin >> a >> b >> c >> k;
        if (b - a == c - b) {
            cout << (a + (k - 1) * (b - a)) % mod << endl;
        } else {
            cout << a * ksm(b / a, k - 1, mod) % mod << endl;
        }
    }
    return 0;
}