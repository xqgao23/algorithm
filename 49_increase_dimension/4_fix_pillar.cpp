/**
 * Description:
 *  小明要建造一个台子，现在还缺两根支柱，目前有高度不同的n个支柱可以选择，第i个支柱的高度为hi，华丽度为vi。多个支柱可以拼接成一根支柱，拼接后的高度等于参与拼接的支柱高度之和。
 *  小明打算从n个支柱中选若干支柱，拼成两个高度相同的支柱。他只关心支柱的华丽度，求出能拼成两根高度相同的支柱的前提下，两根支柱华丽度总和的最大值。
 *  华丽度有可能是负数，如果不论如何选，总华丽度都是负数，那么小明宁可不做支柱。
 *
 * Input:
 *  第1行，1个正整数n。
 *  第2行，n个正整数h1,h2,...,hn
 *  第3行，n个整数v1,v2,...,vn
 *
 * Output:
 *  一个非负整数，输出两根支柱华丽度总和的最大值。
 *
 * Hints:
 *  1≤n≤120, 1≤hi≤500, -10<4>≤vi≤10<4>,
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5
1 3 3 4 7
3 3 1 4 1
 *
 *  output:
10
 *
 *  2):
 *  input:
3
1 2 3
-1 -2 -3
 *
 *  output:
0
 *
 */

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int D = 30000;
int n, h[125], v[125], f[125][60010];
// f[i][j] 表示前i个支柱拼成两个支柱的高度差为j的最大华丽度

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    memset(f, -0x3f, sizeof f);
    f[0][D] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 2 * D; j++) {
            f[i][j] = f[i - 1][j];
            if (j - h[i] >= 0) {
                f[i][j] = max(f[i][j], f[i - 1][j - h[i]] + v[i]);
            }
            if (j + h[i] <= 2 * D) {
                f[i][j] = max(f[i][j], f[i - 1][j + h[i]] + v[i]);
            }
        }
    }
    cout << f[n][D] << endl;
    return 0;
}