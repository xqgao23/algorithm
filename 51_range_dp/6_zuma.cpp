/**
 * Description:
 *  Genos最近在他的手机上下载了祖玛游戏。在祖玛游戏里，存在n个排成一行的宝石，第i个宝石的颜色是Ci 。这个游戏的目标是尽快的消除一行中所有的宝石。 在一秒钟，Genos能很快的挑选出这些有颜色的宝石中的一个回文的，连续的子串，并将这个子串消除。每当一个子串被消除后，剩余的宝石将连接在一起，形成一个新的串。你的任务是：求出把整个宝石串都移除的最短时间。
 *  如果一个串正着读或倒着读都一样，那么这个串（或子串）叫回文串。在我们这道题中，"回文"指这个子串中的第一个珠子的颜色等于最后一个珠子的颜色，第二个珠子的颜色等于倒数第二个珠子的颜色，等等。
 *
 * Input:
 *  第1行包含1个整数n ，表示宝石串的长度。
 *  第2行包含n个被空格分开的整数，第i个数ci表示第i个珠子的颜色
 *
 * Output:
 *  输出一个整数，把这行珠子消除的最短时间。
 *
 * Hints:
 *  1≤n≤500。1≤ci≤n。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3
1 2 1
 *
 *  output:
1
 *
 *  2):
 *  input:
3
1 2 3
 *
 *  output:
3
 *
 *  3):
 *  input:
7
1 4 4 2 3 2 1
 *
 *  output:
2
 *
 */

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n, a[510], f[510][510];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(f, 0x3f, sizeof f);
    for (int i = 1; i <= n; i++) {
        f[i][i] = 1;
    }
    for (int i = 1; i < n; i++) {
        f[i][i + 1] = 1 + (a[i] != a[i + 1]);
    }
    for (int l = 3; l <= n; l++) {
        for (int i = 1; i + l - 1 <= n; i++) {
            int j = i + l - 1;
            if (a[i] == a[j]) {
                f[i][j] = f[i + 1][j - 1];
            }
            for (int k = i; k < j; k++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
            }
        }
    }
    cout << f[1][n] << endl;
    return 0;
}