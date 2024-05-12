/**
 * Description:
 *  农夫John想到镇上买些补给。为了高效地完成任务，他想使硬币的转手次数最少。即使他交付的硬 币数与找零得到的的硬币数最少。
 *  John想要买价值为T(1≤T≤10000)的东西。有N(1≤n≤100)种货币参与流通，面值分别为V1,V2,…,Vn(1≤Vi≤120)。John有Ci个面值为Vi的硬币(0≤Ci≤10000)。
 *  我们假设店主有无限多的硬币，并总按最优方案找零。注意无解输出-1。
 *
 * Input:
 *  第一行，2个整数 N, T；
 *  第2行，n个整数V1,V2,...,Vn
 *  第3行，n个整数C1,C2,...,Cn
 *
 * Output:
 *  输出付钱和找零总共需要用到的最少的硬币数。 无解输出-1
 *
 * Hints:
 *  1≤N≤400, 1≤hi≤100, 1≤ci≤10, 1≤ai≤4*10<4>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 70
5 25 50
5 2 1
 *
 *  output:
3
 *
 */

#include<iostream>
#include<cstring>

using namespace std;

int t, n, cnt, v[110], wt[2010], vt[2010], f[100010], g[100010];

int main()
{
    cin >> n >> t;
    
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    
    for (int i = 1; i <= n; i++) {
        int c, s = 1;
        cin >> c;

        while (s <= c) {
            vt[++cnt] = v[i] * s;
            wt[cnt] = s;
            c -= s;
            s *= 2;
        }
        if (c > 0) {
            vt[++cnt] = v[i] * c;
            wt[cnt] = c;
        }
    }
    
    memset(f, 0x3f, sizeof f);
    memset(g, 0x3f, sizeof g);
    f[0] = g[0] = 0;
    
    for (int i = 1; i <= cnt; i++) {
        for (int j = 100000; j >= vt[i]; j--) {
            f[j] = min(f[j], f[j - vt[i]] + wt[i]);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = v[i]; j <= 100000; j++) {
            g[j] = min(g[j], g[j - v[i]] + 1);
        }
    }
    
    int ans = 1e9;
    
    for (int i = t; i <= 100000; i++) {
        ans = min(ans, f[i] + g[i - t]);
    }

    if (ans == 1e9) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    
    return 0;
}