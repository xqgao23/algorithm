/**
 * Description:
 *  有n个物品，编号从1到n，每个物品有一个重量wi和价值vi
 *  Taro有一个背包，容量为W，他想要挑选一些物品装到背包里面，要求选择的物品重量和不能超过W。
 *  Taro想知道他能获得的最大价值是多少？
 *
 * Input:
 *  第一行两个整数n(1≤n≤100)和W(1≤W≤10<9>)。
 *  接下来n行，每行两个整数wi(1≤wi≤W≤10<9>)和vi(1≤vi≤10<3>)，表示第i个物品的重量和价值。
 *
 * Output:
 *  输出一行，包含一个整数，表示Taro能获得的最大价值。
 *
 * Hints:
 *  1≤n≤100, 1≤wi≤w≤10<9>, 1≤vi≤1000, 1≤W≤10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 8
3 30
4 50
5 60
 *
 *  output:
90
 *
 *  2):
 *  input:
1 1000000000
1000000000 10
 *
 *  output:
10
 *
 *  3):
 *  input:
6 15
6 5
5 6
6 4
6 6
3 5
7 2
 *
 *  output:
17
 *
 */

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n, m, w[110], v[110], f[100010];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 100000; j >= v[i]; j--) {
            f[j] = min(f[j], f[j - v[i]] + w[i]);
        }
    }
    for (int j = 100000; j >= 0; j--) {
        if (f[j] <= m) {
            cout << j << endl;
            return 0;
        }
    }
    return 0;
}