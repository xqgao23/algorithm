/**
 * Description:
 *  ABC蛋糕店出售N种不同的蛋糕。每种蛋糕都有"外观值"，"美味值"，"人气值"三种属性，第i种蛋糕的外观值为xi，美味值为yi，人气值为zi。（这些值可能小于0）。
 *  苹果君想要吃M种蛋糕，每种1个。他想要吃到的蛋糕的（外观值总和的绝对值）+（美味值总和的绝对值）+（人气值总和的绝对值）最大。输出这个最大值。
 *
 * Input:
 *  第1行，2个整数N,M。
 *  接下来N行，每行三个整数xi,yi,zi.
 *
 * Output:
 *  输出最大总和。
 *
 * Hints:
 *  1≤N≤1000
 *  0≤M≤N
 *  -10<10> <= xi,yi,zi <= 10<10>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5 3
3 1 4
1 5 9
2 6 5
3 5 8
9 7 9
 *
 *  output:
56
 *
 *  2):
 *  input:
5 3
1 -2 3
-4 5 -6
7 -8 -9
-10 11 -12
13 -14 15
 *
 *  output:
54
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;
int n, m;
LL x[1010], y[1010], z[1010], s[1010], ans;

LL cal(int a, int b, int c)
{
    for (int i = 1; i <= n; i++) {
        s[i] = a * x[i] + b * y[i] + c * z[i];
    }
    sort(s + 1, s + n + 1, greater<LL>());
    LL ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += s[i];
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> z[i];
    }
    for (int i = -1; i <= 1; i += 2) {
        for (int j = -1; j <= 1; j += 2) {
            for (int k = -1; k <= 1; k += 2) {
                ans = max(ans, cal(i, j, k));
            }
        }
    }
    cout << ans << endl;
    return 0;
}