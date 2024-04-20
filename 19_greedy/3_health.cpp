/**
 * Description:
 *  Mr.L 正在完成自己的增肥计划。
 *  为了增肥，Mr.L
 * 希望吃到更多的脂肪。然而也不能只吃高脂肪食品，那样的话就会导致缺少其他营养。
 *  Mr.L
 * 通过研究发现：真正的营养膳食规定某类食品不宜一次性吃超过若干份。比如就一顿饭来说，肉类不宜吃超过 1 份，鱼类不宜吃超过 1 份，蛋类不宜吃超过 1 份，蔬菜类不宜吃超过 2 份。
 *  Mr.L 想要在营养膳食的情况下吃到更多的脂肪，当然 Mr.L 的食量也是有限的。
 *
 * Input:
 *  第一行包含三个正整数 n,m 和 k。表示 Mr.L
 * 每顿饭最多可以吃 m 份食品，同时有 n 种食品供 Mr.L
 * 选择，而这 n 种食品分为 k 类。
 *  第二行包含 k 个不超过 10 的正整数，表示可以吃 1 到 k 类食品的最大份数。
 *  接下来 n 行每行包括 2 个正整数，分别表示该食品的脂肪指数 ai 和所属的类别 bi
 *
 * Output:
 *  包括一个数字即 Mr.L 可以吃到的最大脂肪指数和。
 *
 * Hints:
 *  1≤n≤200，1≤m≤100，1≤k≤100, 1<=ai<=100, 1<=bi<=k
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
6 6 3
3 3 2
15 1
15 2
10 2
15 2
10 2
5 3
 *
 *  output:
60
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
struct node {
    int a, b;
} p[210];

int n, m, k, c[110];
bool cmp(node x, node y) { return x.a > y.a; }

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i].a >> p[i].b;
    }
    sort(p + 1, p + n + 1, cmp);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (m == 0) {
            break;
        }
        if (c[p[i].b] > 0) {
            ans += p[i].a;
            m--;
            c[p[i].b]--;
        }
    }
    cout << ans << endl;
    return 0;
}