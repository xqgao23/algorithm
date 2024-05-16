/**
 * Description:
 *  在一条数轴上有 n 家商店，它们的坐标分别为 a1 到 an现在需要在数轴上建立一家货仓，每天清晨，从货仓到每家商店都要运送一车商品。根据运送的距离和商品的重量，所需的运费也不一样。向距离 d 公里的地方运送 W 公斤的商品所需的运费是 W×d。
 *  运送到第 i 家商店的商品的重量是 wi。
 *  为了提高效率，求把货仓建在何处，可以使得运送所有商品所需运费之和最小。
 *
 * Input:
 *  第一行输入整数 n。
 *  第二行n 个整数a1 - an.
 *  第3行n 个整数w1 - wn
 *
 * Output:
 *  输出一个整数，表示运费之和的最小值。
 *
 * Hints:
 *  1≤N≤1000000,1≤ai, wi≤1000000,
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4
6 2 9 1
1 2 3 4
 *
 *  output:
29
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
struct node {
    int a, w;
} p[100010];
long long n, pos, sum, s, ans;

bool cmp(node x, node y)
{
    return x.a < y.a;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].a;
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i].w;
        sum += p[i].w;
    }
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        s += p[i].w;
        if (s >= sum - s) {
            pos = p[i].a;
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        ans += 1ll * abs(p[i].a - pos) * p[i].w;
    }
    cout << ans << endl;
    return 0;
}