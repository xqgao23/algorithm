/**
 * Description:
 *  FJ要建一个奶酪塔，高度最大为T。他有N种奶酪。第i种奶酪的高度为Hi（一定是5的倍数），价值为Vi。一块高度Hi≥K的奶酪被称为大奶酪，一个奶酪如果在它上方有大奶酪（如果有多块就只算一次），它的高度Hi就会变成原来的4/5。 FJ想让他的奶酪塔价值和最大。请你求出这个最大值。
 *
 * Input:
 *  第一行三个数N,T,K，意义如上所述。
 *  接下来N行，每行两个数Vi,Hi（注意顺序）
 *
 * Output:
 *  奶酪塔的最大价值
 *
 * Hints:
 *  1≤T≤1000; 1≤N≤100;1≤Vi≤1,000,000; 5≤Hi≤T; 1≤K≤T
 *  Hi一定是5的倍数。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 53 25
100 25
20 5
40 10
 *
 *  output:
240
 *
 */

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n, t, k, f[110][1010], v[110], h[110];
// f[i][j] 表示前i种奶酪搭建高度为j的奶酪塔的最大价值

int main()
{
    cin >> n >> t >> k;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> h[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= t; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= h[i]) {
                f[i][j] = max(f[i][j], f[i][j - h[i]] + v[i]);
            }
        }
    }
    int ans = f[n][t];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= t; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= h[i] * 4 / 5) {
                f[i][j] = max(f[i][j], f[i][j - h[i] * 4 / 5] + v[i]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (h[i] >= k) {
            ans = max(ans, f[n][t - h[i]] + v[i]);
        }
    }
    cout << ans << endl;
    return 0;
}