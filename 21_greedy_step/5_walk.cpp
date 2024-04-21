/**
 * Description:
 *  小 A
 * 准备在接下来的 m 天中锻炼，由于他不能走得太多以至于累死（怎么可能呢），所以他这 m 天最多一共只能走 n 步。
 *  这个运动软件为了激励小 A
 * 走路，推出了 k 种激励措施，每种激励措施都形如"如果你第 p 天走完了 q 步，那么第 p 天中接下来的每一步都会给你加 1 积分"。
 * 激励措施可以叠加，即走一步你可能可以获得多于 1 积分。 现在小 A
 * 想知道，他最多可以获取多少积分呢？
 *
 * Input:
 *  第一行三个整数 n,m,k，意义如上。
 *  接下来 k 行，每行两个整数 p,q，表示一个激励措施，意义如上。
 *
 * Output:
 *  一行 1 个整数，表示 m 天后最多可以获得的积分。
 *
 * Hints:
 *  1≤n≤10<12>, 1≤m,k≤10<5>, 1≤p≤m，0≤q≤n。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5 1 3
1 0
1 2
1 4
 *
 *  output:
9
 *
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
long long n, m, k, ans, s[100010];

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        long long p, q;
        cin >> p >> q;
        s[p] += n - q;
    }
    for (int i = 1; i <= m; i++) {
        ans = max(ans, s[i]);
    }
    cout << ans << endl;
    return 0;
}