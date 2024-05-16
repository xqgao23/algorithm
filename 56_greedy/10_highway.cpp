/**
 * Description:
 *  小明打算开车回家，路上有n个城市，城市1是起点、城市n是终点。一共只有n−1条高速路连接这些城市，只在城市i到i+1之间有高速路，通过这条路从城市i到i+1所需时间为Li
 *  通过每条道路都需要支付过路费。第i条道路的基础费用是ai，另外还需要额外支付与通行时刻有关的附加费用。如果在时刻t从城市i出发，需要支付的过路费等于ai+ci×∣t∣元。其中∣t∣是t的绝对值。（你可以从负的时刻开始移动）
 *  计算从城市1到城市n所需的最小花费。
 *
 * Input:
 *  第 1 行，1 个正整数 n。
 *  接下来 n−1 行，每行 3 个整数 Li,ai,ci
 *
 * Output:
 *  输出从城市1到城市n所需的最小花费。
 *
 * Hints:
 *  4≤n≤10<5>, 0≤ai≤10<9>, 1≤Li≤10<6>,0≤ci≤10<5>保证答案不超过10<18>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4
2 3 4
10 1 1
4 1 3
 *
 *  output:
43
 *
 */

#include <iostream>
using namespace std;
typedef long long LL;
int n, a[100010], c[100010], L[100010];
LL s[100010], sum, ans;

int main()
{
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> L[i] >> a[i] >> c[i];
        s[i] = s[i - 1] + L[i];
        sum += c[i];
    }
    LL pos = 0, t = 0;
    for (int i = 1; i < n; i++) {
        t += c[i];
        if (t >= sum - t) {
            pos = s[i - 1];
            break;
        }
    }
    for (int i = 1; i < n; i++) {
        ans += a[i] + c[i] * abs(s[i - 1] - pos);
    }
    cout << ans << endl;
    return 0;
}