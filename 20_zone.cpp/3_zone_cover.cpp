/**
 * Description:
 *  数轴上有n个闭区间[ai,bi],选择尽量少的区间覆盖一条指定线段[s,t].
 *
 * Input:
 *  第一行是三个整数n,s,t,代表区间数和需要覆盖的区间的左右端点
 *  接下来n行，每行是两个整数ai,bi表示每个区间的左右端点
 *
 * Output:
 *  一个整数, 覆盖区间[s,t]所需的最少区间数量。
 *  如果无法覆盖，输出"impossible"。
 *
 * Hints:
 *  ≤n≤200000,1≤s<t≤10<9>, 1≤ai<=bi≤10<9>
 */

/**
 *  Samples:
 *  1):
 *  input:
4 2 9
1 4
4 6
8 9
3 10
 *
 *  output:
2
 *
 *  2):
 *  input:
2 9 9999
1 4
4 6
 *
 *  output:
impossible
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n, s, t;
struct node {
    int a, b;
} p[200010];

bool cmp(node x, node y) { return x.a < y.a; }

int main()
{
    cin >> n >> s >> t;

    for (int i = 1; i <= n; i++) {
        cin >> p[i].a >> p[i].b;
    }

    sort(p + 1, p + n + 1, cmp);

    int maxb = -1e9, ans = 0;

    for (int i = 1; i <= n; i++) {
        if (s >= t) {
            break;
        }

        if (p[i].a <= s) {
            maxb = max(maxb, p[i].b);
        } else {
            ans++;
            s = maxb;
            if (s <= p[i].a) {
                break;
            }
            // if (s < p[i].a) // 不能这样去写，因为加了一个左端点为2e9的区间，一定满足这种情况，而当枚举到这种情况的时候，有可能恰好是第n个区间把把t 才覆盖到，这时就不能输出impossible。
            // {
            // cout << "impossible" << endl; // return 0;
            // }
            maxb = p[i].b;
        }
    }

    if (maxb > s && maxb > t) {
        s = t;
        ans++;
    }

    if (s >= t) {
        cout << ans << endl;
    } else {
        cout << "impossible" << endl;
    }

    return 0;
}