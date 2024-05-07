/**
 * Description:
 *  输入整数a,b,p，计算a<b>除p的余数
 *
 * Input:
 *  输入包含多组数据
 *  第1行，1个正整数T表示有T组测试数据
 *  接下来T行，每行3个整数a,b,p
 *
 * Output:
 *  输出T行，对于每组数据，输出a<b>除p的余数
 *
 * Hints:
 *  1≤T≤1000, 1≤a≤10<9>,0≤b≤10<9>,1≤p≤10<9>
 *  1≤ai,bi≤10<18>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
2
2 12 7
2 1000000000 998244355
 *
 *  output:
1
340515086
 *
 */

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
    int t;
    cin >> t;
    while (t--) {
        LL a, b, p;
        cin >> a >> b >> p;
        cout << ksm(a, b, p) << endl;
    }
    return 0;
}