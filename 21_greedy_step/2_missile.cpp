/**
 * Description:
 *  某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。但是这种导弹拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。某天，雷达捕捉到敌国的导弹来袭。由于该系统还在试用阶段，所以只有一套系统，因此有可能不能拦截所有的导弹。
 *  输入导弹依次飞来的高度（雷达给出的高度数据是 <=
 * 50000的正整数），计算要拦截所有导弹，最少要配备多少套这种导弹拦截系统。
 *
 * Input:
 *  第1行一个正整数n （n≤1000）
 *  第2行n个正整数, 不超过50000, 以空格分隔
 *
 * Output:
 *  1行，表示如果要拦截所有导弹，最少要配备多少套这种导弹拦截系统。
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
8
389 207 155 300 299 170 158 65
 *
 *  output:
2
 *
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int n, a[1010], b[1010];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int minj = -1, minh = 50000;
        for (int j = 1; j <= cnt; j++) {
            if (b[j] >= a[i] && b[j] < minh) {
                minj = j;
                minh = b[j];
            }
        }
        if (minj != -1) {
            b[minj] = a[i];
        } else {
            b[++cnt] = a[i];
        }
    }
    cout << cnt << endl;
    return 0;
}