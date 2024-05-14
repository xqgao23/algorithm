/**
 * Description:
 *  有n个包裹，第i个包裹完成分拣需要的时间是ai分钟，包裹的价值是vi。现在分拣中心有2个分拣机器同时运转，问在T分钟内，最多可以分拣多少价值的包裹。
 *
 * Input:
 *  第1行，2个正整数n,T
 *  接下来n行，每行2个正整数ai,vi
 *
 * Output:
 *  1个整数，分拣包裹总价值的最大值。
 *
 * Hints:
 *  1≤n≤60，1≤T≤1200, 1≤ai≤100, 1≤vi≤1000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5 10
3 8
5 6
6 9
7 7
10 10
 *
 *  output:
27
 *
 */

#include <iostream>
using namespace std;
int n, T, w[65], v[65], f[1210][1210];

int main()
{
    cin >> n >> T;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    for (int k = 1; k <= n; k++) {
        for (int i = T; i >= 0; i--) {
            for (int j = T; j >= 0; j--) {
                if (i >= w[k]) {
                    f[i][j] = max(f[i][j], f[i - w[k]][j] + v[k]);
                }
                if (j >= w[k]) {
                    f[i][j] = max(f[i][j], f[i][j - w[k]] + v[k]);
                }
            }
        }
    }
    cout << f[T][T] << endl;
    return 0;
}