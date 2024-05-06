/**
 * Description:
 *  监狱有 n 个房间，每个房间关押一个犯人，有 m 种语言，每个犯人会其中一种。如果相邻房间的犯人的语言相同，就可能发生越狱，求有多少种状态可能发生越狱。100,003 取模。
 *
 * Input:
 *  输入只有一行两个整数，分别代表语言数 m 和房间数 n。
 *
 * Output:
 *  输出一行一个整数代表答案。
 *
 * Hints:
 *  1≤m≤10<8>
 *  1≤n≤10<12>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
2 3
 *
 *  output:
6
 *
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;
LL m, n, mod = 100003;

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
    cin >> m >> n;
    int s1 = ksm(m, n, mod);
    int s2 = m * ksm(m - 1, n - 1, mod) % mod;
    cout << (s1 - s2 + mod) % mod << endl;
    return 0;
}