/**
 * Description:
 *  面包师Lavrenty准备用馅料做一些面包，然后卖掉。
 *  Lavrenty有n克面团和m种不同的馅料，馅料编号从1到m，第i(1≤i≤m)种馅料有ai克。
 *  每种面包需要使用一种馅料来制作，用第i种馅料制作面包，需要bi克第i种馅料和ci克面团，能卖出di元。
 *  Lavrenty也可以做没有馅料的面包，每个这样的面包需要c0克面团，能卖出d0元。
 *  Lavrenty想知道他该如何制作面包，以获得最高的收益。
 *
 * Input:
 *  第一行包含四个整数n,m和c0,d0(1≤c0,d0≤100)，表示有n(1≤n≤1000)克面团，m(1≤m≤10)种馅料，以及c0,d0。
 *  接下来m行，每行包含四个整数ai,bi,ci,di(1≤ai,bi,ci,di≤100)，表示第i种馅料的剩余数量，制作第i种面包需要消耗bi克馅料和ci克面团，能卖出di元。
 *
 * Output:
 *  输出一行，包含一个整数，表示Lavrenty的最高收益。
 *
 * Hints:
 *  1≤n≤1000，1≤m≤10, 1≤c0,d0≤100，1≤ai,bi,ci,di≤100
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
10 2 2 1
7 3 2 100
12 3 1 10
 *
 *  output:
241
 *
 *  2):
 *  input:
100 1 25 50
15 5 20 10
 *
 *  output:
200
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n, m, cnt, w[2010], v[2010], f[1010];

int main()
{
    cin >> n >> m >> w[0] >> v[0];
    for (int i = 1; i <= n / w[0]; i++) {
        w[++cnt] = w[0];
        v[cnt] = v[0];
    }
    for (int i = 1; i <= m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int j = 1; j <= a / b; j++) {
            w[++cnt] = c;
            v[cnt] = d;
        }
    }
    for (int i = 1; i <= cnt; i++) {
        for (int j = n; j >= w[i]; j--) {
            f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    }
    cout << f[n] << endl;
    return 0;
}