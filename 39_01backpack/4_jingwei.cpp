/**
 * Description:
 *  精卫终于快把东海填平了！只剩下了最后的一小片区域了。同时，西山上的木石也已经不多了。精卫能把东海填平吗？
 *  事实上，东海未填平的区域还需要至少体积为v的木石才可以填平，而西山上的木石还剩下n块，第i块的体积为ki，把它衔到东海需要的体力为mi。精卫已经填海填了这么长时间了，她也很累了，她还剩下的体力为c。
 *
 * Input:
 *  输入文件的第一行是三个正整数：v,n,c.
 *  从第二行到第n+1行，每行两个正整数ki,mi，分别为每块木石的体积和把它衔到东海需要的体力。
 *
 * Output:
 *  输出文件只有一行，如果精卫能把东海填平，则输出她把东海填平后剩下的最大的体力，否则输出"Impossible"（不带引号）。
 *
 * Hints:
 *  0<n≤10000，所有读入的数均不超过10000，最后结果≤c。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
100 2 10
50 5
50 5
 *
 *  output:
0
 *
 *  2):
 *  input:
10 2 1
50 5
10 2
 *
 *  output:
Impossible
 *
 */

// 二维
#include <algorithm>
#include <iostream>
using namespace std;
int v, n, c, k[10010], m[10010], f[1010][10010];

int main()
{
    cin >> v >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> k[i] >> m[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= c; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= m[i]) {
                f[i][j] = max(f[i][j], f[i - 1][j - m[i]] + k[i]);
            }
        }
    }
    for (int j = 1; j <= c; j++) {
        if (f[n][j] >= v) {
            cout << c - j << endl;
            return 0;
        }
    }
    cout << "Impossible" << endl;
    return 0;
}