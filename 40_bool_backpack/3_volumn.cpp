/**
 * Description:
 *  一个吉他手准备参加一场演出。他不喜欢在演出时始终使用同一个音量，所以他决定每一首歌之前他都需要改变一次音量。在演出开始之前，他已经做好一个列表，里面写着每首歌开始之前他想要改变的音量是多少。每一次改变音量，他可以选择调高也可以调低。
 *  音量用一个整数描述。输入文件中整数 beginLevel，代表吉他刚开始的音量，整数 maxLevel，代表吉他的最大音量。音量不能小于 0 也不能大于 maxLevel。输入中还给定了 n 个整数 c1,c2,…,cn，表示在第 i 首歌开始之前吉他手想要改变的音量是多少。
 *  吉他手想以最大的音量演奏最后一首歌，你的任务是找到这个最大音量是多少。
 *
 * Input:
 *  第一行依次为三个整数 n, beginLevel 和 maxLevel。
 *  第二行依次为 n 个整数c1,c2,...,cn
 *
 * Output:
 *  输出演奏最后一首歌的最大音量。如果吉他手无法避免音量低于 0 或者高于 maxLevel，输出 -1。
 *
 * Hints:
 *  1≤n≤50，1≤ci≤maxLevel，1≤maxLevel≤1000，0≤beginLevel≤maxLevel。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 5 10
5 3 7
 *
 *  output:
10
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n, b, m, c[55];
bool f[55][1005];
// f[i][j] 表示第i首歌结束时，音量能否巧好达到j

int main()
{
    cin >> n >> b >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    f[0][b] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (j >= c[i]) {
                f[i][j] |= f[i - 1][j - c[i]];
            }
            if (j + c[i] <= m) {
                f[i][j] |= f[i - 1][j + c[i]];
            }
        }
    }
    for (int j = m; j >= 0; j--) {
        if (f[n][j]) {
            cout << j << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}