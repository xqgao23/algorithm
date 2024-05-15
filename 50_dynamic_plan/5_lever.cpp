/**
 * Description:
 *  小猴一直在利用一个杠杆翘起各种重物，杠杆左右臂的长度都是L，小猴在右臂施加的力量为F，根据杠杆原理右边的力矩为L×F。力矩越大，就能翘起越重的东西。现在小猴想要购买强化道具来改造这个杠杆，使得它能翘起更重的东西。
 *  可以用于改造杠杆的强化道具有两种：延长杆可以增加右臂的长度；增幅器可以增加在右臂施加的力量。
 *  有n个延长杆，第i个延长杆可以将右臂长度增加ai，售价bi元。有m个增幅器，第j个增幅器可以将力量增加cj，售价dj元。
 *  小猴一共只有W元，他要从这些强化道具中选择一些购买（总售价不超过W），使得改造后的力矩最大。
 *  力矩的计算方式：设购买到的延长杆总长度为suma，增幅器总力量为sumc，那么力矩等于(L+suma)×(F+sumc)，小猴想要让这个式子值最大。
 *
 * Input:
 *  第1行，3个整数L,F,W，分别表示初始右臂长度、初始力量、小猴的资金。
 *  第2行，1个整数n，表示延长杆的个数。
 *  接下来n行，每行两个正整数ai,bi、表示第i个延长杆的长度和售价。
 *  第n+3行，1个整数m，表示增幅器的个数。
 *  接下来m行，每行两个正整数cj,dj、表示第j个增幅器的力量和售价。
 *
 * Output:
 *  1个正整数，可以得到的最大力矩。
 *
 * Hints:
 *  0≤n,m≤5000, 1≤L,F,ai,cj≤10000, 1≤bi,dj≤5000, 0≤W≤5000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
10 3 39
3
7 2
1 3
10 10
3
5 13
5 10
6 10
 *
 *  output:
392
 *
 *  2):
 *  input:
4 2 31
4
3 7
1 6
9 10
8 5
4
2 9
7 3
8 2
5 9
 *
 *  output:
462
 *
 *  3):
 *  input:
4 9 20
0
5
8 7
4 6
6 10
5 3
10 8
 *
 *  output:
128
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
const int N = 5010;
int L, F, W, n, m, a[N], b[N], c[N], d[N], f[N], g[N];

int main()
{
    cin >> L >> F >> W >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> c[i] >> d[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = W; j >= b[i]; j--) {
            f[j] = max(f[j], f[j - b[i]] + a[i]);
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = W; j >= d[i]; j--) {
            g[j] = max(g[j], g[j - d[i]] + c[i]);
        }
    }
    long long ans = 0;
    for (int i = 0; i <= W; i++) {
        ans = max(ans, 1ll * (L + f[i]) * (F + g[W - i]));
    }
    cout << ans << endl;
    return 0;
}