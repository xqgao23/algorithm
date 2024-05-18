/**
 * Description:
 *  惊奇乐园有n个游乐设施，对于小猴来说，第i个设施的“快乐度”初始是ai。
 *  小猴游玩一次第i个设施后，他的“满足度”会增加第i个设施当时的“快乐度”的数值。然后，第i个设施的“快乐度”会减少1。
 *  小猴的“满足度”初始是0，他最多可以游玩k次游乐设施（不足k次也可以），那么他可以获得的“满足度”最多是多少？
 *
 * Input:
 *  第1行，2个正整数n,k
 *  第2行，n个正整数a1,a2,...,an
 *
 * Output:
 *  “满足度”的最大值
 *
 * Hints:
 *  1≤n≤2*10<5>, 1≤k≤2*10<9>
 *  1≤ai≤2*10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 5
100 50 102
 *
 *  output:
502
 *
 *  2):
 *  input:
2 2023
2 3
 *
 *  output:
9
 *
 *  3):
 *  input:
5 1000000000
1234512345 1333333333 1333333000 1234512345 1234512345
 *
 *  output:
1179900006957188639
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;
LL n, k, a[200010], ans;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    for (int i = 1; i <= n; i++) {
        LL d = a[i] - a[i + 1];
        if (k - i * d < 0) {
            int x = k % i, y = k / i;
            ans += (a[i] - y + 1 + a[i]) * y / 2 * i;
            ans += (a[i] - y) * x;
            break;
        }
        ans += (a[i + 1] + 1 + a[i]) * d / 2 * i;
        k -= i * d;
    }
    cout << ans << endl;
    return 0;
}