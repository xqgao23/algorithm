/**
 * Description:
 *  在 xy 坐标平面上，小明一开始在 (0,0)。
 *  他每次可以向上下左右跳跃 d 单位距离。例如他目前在点 (x,y)，向右跳一次后就跳到点 (x+d,y)。（这里认为x轴正方向是右，y轴正方向是上）
 *  如果他跳了 n 次后，恰好停在点 (a,b)，那么问他的可能的跳跃路线有多少种？输出路线数除以 10<9>+7 的余数。
 *
 * Input:
 *  1行，四个正整数n,d,a,b
 *
 * Output:
 *  输出路线数除以 10<9>+7 的余数。
 *
 * Hints:
 *  1≤n≤2000,1≤d≤10<9>,-10<9>≤a,b≤10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
2 10 10 10
 *
 *  output:
2
 *
 *  2):
 *  input:
1000 2 3 6
 *
 *  output:
0
 *
 *  3):
 *  input:
11 753 2259 -1506
 *
 *  output:
76230
 *
 */

#include <iostream>
using namespace std;
typedef long long LL;
int n, d, a, b;
LL C[2010][2010], ans, mod = 1e9 + 7;

void init()
{
    C[0][0] = 1;
    for (int i = 1; i <= 2000; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
        }
    }
}

int main()
{
    cin >> n >> d >> a >> b;
    if (a < 0) {
        a = -a;
    }
    if (b < 0) {
        b = -b;
    }
    if (a % d || b % d || n < a / d + b / d) {
        cout << 0 << endl;
        return 0;
    }
    init();
    a /= d, b /= d;
    for (int x1 = a; x1 <= n; x1++) {
        int x2 = x1 - a, y = n - x1 - x2 - b;
        if (y & 1 || y < 0) {
            continue;
        }
        ans = (ans + C[n][x1] * C[n - x1][x2] % mod * C[n - x1 - x2][y / 2] % mod) % mod;
    }
    cout << ans << endl;
    return 0;
}