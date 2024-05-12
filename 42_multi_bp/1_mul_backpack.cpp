/**
 * Description:
 *  有一个容量为W的背包，有N种物品可以挑选，第i件物品的体积是wi，价值是vi。 且第i种物品只有mi个
 *  选择若干个物品装入背包，求背包能装下的最大价值是多少？
 *
 * Input:
 *  第一行为一个整数 n 和 W，分别表示宝物种数和采集车的最大载重。
 *  接下来 n 行每行三个整数vi,wi,mi
 *
 * Output:
 *  输出仅一个整数，表示背包能装下的最大价值。
 *
 * Hints:
 *  n≤∑mi≤10<3>, 0≤W≤10<3>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4 20
3 9 3
5 9 1
9 4 2
8 1 3
 *
 *  output:
47
 *
 */

#include<iostream>
#include<algorithm>

using namespace std;

int W, N, w[10010], v[10010], m[10010], f[1010];

int main()
{
    cin >> N >> W;

    for (int i = 1; i <= N; i++) {
        cin >> v[i] >> w[i] >> m[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int k = 1; k <= m[i]; k++) {
            for (int j = W; j >= w[i]; j--) {
                f[j] = max(f[j], f[j - w[i]] + v[i]);
            }
        }
    }
    
    cout << f[W] << endl;
    
    return 0;
}
