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

// 方法一 O(nlongn + n)
#include <iostream>
using namespace std;
typedef long long LL;
int n, cnt[10000010];

void prime(int n)
{
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            cnt[j]++;
        }
    }
}

int main()
{
    cin >> n;
    prime(n);
    LL ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += 1ll * i * cnt[i];
    }
    cout << ans << endl;
    return 0;
}