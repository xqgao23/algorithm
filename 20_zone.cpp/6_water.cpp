/**
 * Description:
 *  长L米，宽W米的草坪里装有n个浇灌喷头。每个喷头都装在草坪中心线上（离两边各W/2米）。我们知道每个喷头的位置（离草坪中心线左端的距离），以及它能覆盖到的浇灌范围。
 *  请问：如果要同时浇灌整块草坪，最少需要打开多少个喷头？
 *
 * Input:
 *  输入包含若干组测试数据。
 *  第一行一个整数T表示数据组数；
 *  每组数据的第一行是整数n, L和W；
 *  接下来的n行，每行包含两个整数，给出一个喷头的位置和浇灌半径（上面的示意图是样例输入第一组数据所描述的情况）。
 *
 * Output:
 *  输出n行，每行表示要开多少个喷头，-1表示无法覆盖
 *
 * Hints:
 *  n≤15000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3
8 20 2
5 3
4 1
1 2
7 2
10 2
13 3
16 2
19 4
3 10 1
3 5
9 3
6 1
3 10 1
5 3
1 1
9 1
 *
 *  output:
6
2
-1
 *
 */

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
int t, n, L, w;
struct node {
    double a, b;
} p[15010];

bool cmp(node x, node y) { return x.a < y.a; }

int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> L >> w;
        int m = 0;
        for (int i = 1; i <= n; i++) {
            double x, r;
            cin >> x >> r;
            if (r <= w / 2) {
                continue; // 当前整个圆不成立，但是这里残留的上一个圆可能符合要求，所有最好使用数组光标保存每次成立的圆或者每次清空p
            }
            p[++m].a = x - sqrt(r * r - w * w / 4.0);
            p[m].b = x + sqrt(r * r - w * w / 4.0);
        }
        sort(p + 1, p + m + 1, cmp);
        int ans = 0;
        double maxb = -1e9, S = 0;
        p[m + 1].a = 1e9;
        for (int i = 1; i <= m + 1; i++) {
            if (S >= L) {
                break;
            }
            if (p[i].a <= S) {
                maxb = max(maxb, p[i].b);
            } else {
                ans++;
                S = maxb;
                if (S < p[i].a) {
                    break;
                }
                maxb = p[i].b;
            }
        }
        if (S >= L) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}