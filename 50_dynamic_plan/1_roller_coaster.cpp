/**
 * Description:
 *  游乐园的老板要改造他的过山车，小明接到任务，要对过山车的高度进行改造。过山车分为n小段，第i段由一个高度为hi的支柱支撑。改造的方法很简单，拆除原来的支柱，重新安装一种高度可伸缩的支柱。
 *  游乐园老板想要将过山车高改成先上升在下降的形式，也就是修改后的高度要满足存在一个 hi（2≤i≤n−1），使得 hi1<h2<⋯<hi>hi+1>⋯>hn。修改后的高度可以是小数。
 *  问小明最少需要重新安装多少支柱？
 *
 * Input:
 *  第1行，1个正整数n。
 *  第2行，n个正整数h1,h2,...,hn
 *
 * Output:
 *  1个整数，输出最少需要重新安装的支柱数量。
 *
 * Hints:
 *  1≤n≤10<5>, 1≤hi≤10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5
1 3 2 2 1
 *
 *  output:
1
 *
 *  2):
 *  input:
5
1 3 1 3 1
 *
 *  output:
1
 *
 *  3):
 *  input:
5
1 2 3 2 1
 *
 *  output:
0
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int n, h[N], f[N], g[N], k[N], l[N], r[N], ans;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    int len = 0;
    for (int i = 1; i <= n; i++) {
        if (h[i] > k[len]) {
            k[++len] = h[i];
            l[i] = len;
        } else {
            int p = lower_bound(k + 1, k + len + 1, h[i]) - k;
            k[p] = h[i];
            l[i] = p;
        }
        f[i] = len;
    }
    len = 0;
    for (int i = n; i >= 1; i--) {
        if (h[i] > k[len]) {
            k[++len] = h[i];
            r[i] = len;
        } else {
            int p = lower_bound(k + 1, k + len + 1, h[i]) - k;
            k[p] = h[i];
            r[i] = p;
        }
        g[i] = len;
    }
    for (int i = 2; i < n; i++) {
        ans = max(ans, f[i - 1] + g[i + 1]);
        ans = max(ans, l[i] + r[i] - 1);
    }
    cout << n - ans << endl;
    return 0;
}