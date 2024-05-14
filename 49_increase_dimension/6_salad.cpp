/**
 * Description:
 *  冰箱中有n个水果，每个水果都有两种参数：味道值和卡路里值。
 *  Inna决定做一个水果沙拉，所以她想从冰箱中拿出一些水果来做。
 *  Inna在选择水果时遵循一定的原则，所选的水果的味道值之和与卡路里值之和的比值必须等于k。换句话说，E<aj>/E<bj> = k是第j个被选择的水果的味道值，bj是第j个被选择的水果的卡路里值。
 *  Inna还没有选好水果，她在想：如果严格按照自己的原则，选出来的水果的味道值之和最大是多少？
 *  一个水果沙拉至少需要选择一个水果。
 *
 * Input:
 *  第一行包含两个整数n(1≤n≤100)和k(1≤k≤10)。
 *  第二行包含n个整数a1,a2,…,an(1≤ai≤100)，表示第i种水果的味道值。
 *  第三行包含n个整数b1,b2,…,bn(1≤bi≤100)，表示第i种水果的卡路里值。
 *
 * Output:
 *  输出一行，包含一个整数，表示Inna能做的水果沙拉的可能的味道值之和。
 *  如果Inna无法选择水果，即无法完成任何水果沙拉，输出−1。
 *
 * Hints:
 *  1≤n≤100, 1≤k≤10, 1≤ai, bi≤100
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 2
10 8 1
2 7 1
 *
 *  output:
18
 *
 *  2):
 *  input:
5 3
4 4 4 4 4
2 2 2 2 2
 *
 *  output:
-1
 *
 */

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int D = 1e4;
int n, k, a[110], b[110], f[110][2 * D + 10];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        b[i] = a[i] - k * b[i];
    }
    memset(f, -0x3f, sizeof f);
    f[0][0 + D] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 2 * D; j++) {
            f[i][j] = f[i - 1][j];
            if (j - b[i] >= 0 && j - b[i] <= 2 * D) {
                f[i][j] = max(f[i][j], f[i - 1][j - b[i]] + a[i]);
            }
        }
    }
    if (f[n][D] <= 0) {
        cout << -1 << endl;
    } else {
        cout << f[n][D] << endl;
    }
    return 0;
}