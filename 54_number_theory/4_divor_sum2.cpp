/**
 * Description:
 *  记正整数 x 的约数个数为 d(x)，求F(n)=E k*d(k)
 *
 * Input:
 *  1 个正整数 n
 *
 * Output:
 *  输出答案。
 *
 * Hints:
 *  1≤n≤10<7>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4
 *
 *  output:
23
 *
 *  2):
 *  input:
10000000
 *
 *  output:
838627288460105
 *
 */

// 方法三 O(n)
#include <iostream>
using namespace std;
typedef long long LL;

int main()
{
    int n;
    cin >> n;
    LL ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += 1ll * (i + n / i * i) * (n / i) / 2;
    }
    cout << ans << endl;
    return 0;
}