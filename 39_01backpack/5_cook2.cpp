/**
 * Description:
 *  由于你的帮助，火星只遭受了最小的损失。但gw懒得重建家园了，就造了一艘飞船飞向遥远的earth星。不过飞船飞到一半，gw发现了一个很严重的问题：肚子饿了~
 *  gw还是会做饭的，于是拿出了储藏的食物准备填饱肚子。gw希望能在T时间内做出最美味的食物，但是这些食物美味程度的计算方式比较奇葩，于是绝望的gw只好求助于你了。
 *  一共有n件食材，每件食材有三个属性，ai,bi和ci，如果在t时刻完成第i样食材则得到ai−t×bi的美味指数，用第i件食材做饭要花去ci的时间。
 *  众所周知，gw的厨艺不怎么样，所以他需要你设计烹调方案使得美味指数最大
 *
 * Input:
 *  第一行是两个正整数T和n，表示到达地球所需时间和食材个数。
 *  下面一行n个正整数，a1,a2,...,an
 *  下面一行n个正整数，b1,b2,...,bn
 *  下面一行n个正整数，c1,c2,...,cn
 *
 * Output:
 *  输出最大美味指数
 *
 * Hints:
 *  1≤n≤50，所有数字均小于100,000。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
74 1
502
2
47
 *
 *  output:
408
 *
 */

// 一维
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
struct node {
    int a, b, c;
} p[N];

int t, n, f[N];

bool cmp(node x, node y)
{
    return 1ll * x.c * y.b < 1ll * y.c * x.b;
}

int main()
{
    cin >> t >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].a;
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i].b;
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i].c;
    }
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        for (int j = t; j >= p[i].c; j--) {
            f[j] = max(1ll * f[j], f[j - p[i].c] + p[i].a - 1ll * j * p[i].b);
        }
    }
    int res = 0;
    for (int i = 1; i <= t; i++) {
        res = max(res, f[i]);
    }
    cout << res << endl;
    return 0;
}