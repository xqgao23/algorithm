/**
 * Description:
 *  农夫布朗的奶牛们正在进行斗争，因为它们听说麦当劳正在考虑引进一种新产品：麦乐牛块。奶牛们正在想尽一切办法让这种可怕的设想泡汤。奶牛们进行斗争的策略之一是"劣质的包装"。
 *  "看，"奶牛们说，"如果你只用一次能装3块、6块或者10块的三种包装盒包装麦香牛块，你就不可能满足一次只想买1,2,4,5,7,8,11,14,17块麦香牛块的顾客了。劣质的包装意味着劣质的产品。"
 *  你的任务是帮助这些奶牛。给出包装盒的种类数N(1≤N≤10)和N个代表不同种类包装盒容纳麦香牛块个数的正整数(1≤i≤256)，输出顾客不能用上述包装盒（每种盒子数量无限）买到麦香牛块的最大块数。如果所有购买方案都能得到满足或者不存在不能买到块数的上限，则输出0。 不能买到的最大块数（倘它存在）不超过2*10<9>
 *
 * Input:
 *  第1行，包装盒的种类数N
 *  第2∼N+1行: 每个种类包装盒容纳麦香牛块的个数
 *
 * Output:
 *  输出文件只有一行数字：顾客不能用包装盒买到麦香牛块的最大块数或0（如果所有购买方案都能得到满足或者顾客不能买到的块数没有上限）
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3
3
6
10
 *
 *  output:
17
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n, w[15], f[15][1000010];
// f[i][j] 表示前i种数字能否恰好组成j

int gcd(int a, int b)
{
    int x, y;
    if (a >= b) {
        x = a;
        y = b;
    } else {
        x = b;
        y = a;
    }

    if (y == 0) {
        return x;
    }

    while (true) {
        int t = x % y;
        if (t == 0) {
            return y;
        }
        x = y;
        y = t;
    }

    return 1;
}

int main()
{
    cin >> n;
    int g = 0;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        g = gcd(g, w[i]);
    }
    if (g != 1) {
        cout << 0 << endl;
        return 0;
    }
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 1e6; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= w[i]) {
                f[i][j] |= f[i][j - w[i]];
            }
        }
    }
    for (int i = 1e6; i >= 1; i--) {
        if (!f[n][i]) {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}