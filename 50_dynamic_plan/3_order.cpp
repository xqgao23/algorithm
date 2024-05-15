/**
 * Description:
 *  高桥来吃自助餐。店里提供N道菜，吃第i道菜需要Ai分钟，美味度是Bi。
 *  店里的规则如下：
 *      1.	每次只能点一道菜。
 *      2.	每道菜只能点一次。
 *      3.	必须把之前点的菜吃完才能点下一道菜。
 *  	4.	从进店后第𝑇分钟开始就不能点菜了，但是还可以吃之前点好的菜。
 *  求高桥可以吃的菜的最大美味度总和。假设高桥进店马上就点了他的第一道菜，忽略点菜上菜的时间。
 *
 * Input:
 *  第1行，2个正整数n,T
 *  接下来n行，每行两个正整数Ai,Bi
 *
 * Output:
 *  输出高桥可以吃到的菜的美味度总和的最大值。
 *
 * Hints:
 *  2≤N≤3000, 1≤T,Ai,Bi≤3000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 60
10 10
100 100
100 80
 *
 *  output:
110
 *
 *  2):
 *  input:
3 60
50 70
10 100
50 10
 *
 *  output:
170
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
const int N = 3e3 + 10;
int n, T, a[N], b[N], f[N][N], g[N][N], ans;

int main()
{
    cin >> n >> T;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= T - 1; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= a[i]) {
                f[i][j] = max(f[i][j], f[i - 1][j - a[i]] + b[i]);
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= T - 1; j++) {
            g[i][j] = g[i + 1][j];
            if (j >= a[i]) {
                g[i][j] = max(g[i][j], g[i + 1][j - a[i]] + b[i]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int t = 0; t <= T - 1; t++) {
            sum = max(sum, f[i - 1][t] + g[i + 1][T - 1 - t]);
        }
        ans = max(ans, sum + b[i]);
    }
    cout << ans << endl;
    return 0;
}