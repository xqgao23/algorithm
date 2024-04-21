/**
 * Description:
 *  暴雨过后，FJ的农场到镇上的公路上有一些泥泞路，他有若干块长度为L的木板可以铺在这些泥泞路上，问他至少需要多少块木板，才能把所有的泥泞路覆盖住。
 *
 * Input:
 *  第一行为正整数n和L，分别表示有多少段泥泞路和木板的长度；
 *  接下来n行，每一行两个整数s和e，表示每一段泥泞路的起点和终点。
 *
 * Output:
 *  仅一个正整数，表示木板数。
 *
 * Hints:
 *  n≤10000, L<=10000, s<=e<=10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 3
1 6
13 17
8 12
 *
 *  output:
5
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n, L;
struct node {
    int s, e;
} p[10010];

bool cmp(node x, node y) { return x.s < y.s; }

int main()
{
    cin >> n >> L;

    for (int i = 1; i <= n; i++) {
        cin >> p[i].s >> p[i].e;
    }

    sort(p + 1, p + n + 1, cmp);

    int ans = 0, last = -1e9;

    for (int i = 1; i <= n; i++) {
        int len = 0;
        if (p[i].s <= last) {
            len = p[i].e - last;
        } else {
            len = p[i].e - p[i].s;
        }
        int cnt = (len + L - 1) / L;
        ans += max(0, cnt);
        last = max(last, p[i].s) + cnt * L;
    }

    cout << ans << endl;

    return 0;
}