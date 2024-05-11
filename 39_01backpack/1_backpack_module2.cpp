/**
 * Description:
 *  有一个容量为 m 的背包 , 有 n 件物品可以挑选 , 每个物品有 2 个属性 , 体积及价值 .
 *  求背包能装下的最大价值是多少
 *
 * Input:
 *  第1行 2 个正整数 , n, m 代表物品个数与背包容量.
 *  接下来 n 行每行 2 个正整数 , wi 表示第 i 个物品的体积 , vi 表示第 i 个物品的价值.
 *
 * Output:
 *  输出1个整数 , 即能装下的最大价值.
 *
 * Hints:
 *  1≤n,m≤1000；1≤wi,vi≤400；
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4 6
1 4
2 6
3 12
2 7
 *
 *  output:
23
 *
 */

// 一维
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1e3 + 10;
int n, m, w[N], v[N], f[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= w[i]; j--) {
            f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    }
    cout << f[m] << endl;
    return 0;
}