/**
 * Description:
 *  小明打算从 A 地运若干货物到 B 地卖掉。他有 n 个货物，第 i 个货物的重量是 wi 千克、如果运到 B 地变卖可以获得 vi 个金币。
 *  小明打算用一艘船运走这些货物，船的承重有限，目前船舱里只能装下总重不超过 S0 的货物。于是他想请一个魔法师帮他增加货船的承重。小明一共找到了 m 名魔法师，雇佣第 i 名魔法师需要 ci 个金币，他的魔法可以令船的承重变成 Si。
 *  小明在 n 个货物中选择若干个购买装船，运输到 B 地后将所有货物变卖，卖得的金币减去雇佣魔法师花掉的金币就是他的获利。那么他最多可以获利多少个金币？
 *  小明在 A 地时就有足够的本金，所以他可以雇佣任何他想雇佣的魔法师，也可以不雇佣任何魔法师。
 *
 * Input:
 *  第 1 行，3 个正整数 n,m,S0
 *  第 2 行，n 个正整数w1,w2,...,wn
 *  第 3 行，n 个正整数v1,v2,...,vn.
 *  第 4 行，m 个正整数S1,S2,...,Sm
 *  第 5 行，m 个正整数c1,c2,...,cm.
 *
 * Output:
 *  输出小明最多可以获利的金币数量。
 *
 * Hints:
 *  1≤n,m≤100, 1≤S0≤10000, 1≤Si≤10000, 1≤wi,vi≤1000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5 3 2
1 6 6 4 4
9 3 3 7 9
18 7 16
9 8 3
 *
 *  output:
25
 *
 *  2):
 *  input:
5 3 15
5 8 4 2 2
2 9 9 2 3
30 23 19
15 23 23
 *
 *  output:
21
 *
 *  3):
 *  input:
5 5 14
8 9 4 5 7
4 8 2 5 1
37 23 25 16 17
26 38 3 1 27
 *
 *  output:
14
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
const int N = 110;
int n, m, w[N], v[N], s[N], c[N], f[10010], ans;
int main()
{
    cin >> n >> m >> s[0];
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 10000; j >= w[i]; j--) {
            f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    }
    for (int i = 0; i <= m; i++) {
        ans = max(ans, f[s[i]] - c[i]);
    }
    cout << ans << endl;
    return 0;
}