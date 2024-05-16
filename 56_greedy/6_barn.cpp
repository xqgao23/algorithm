/**
 * Description:
 *  在一条数轴上有 N 家商店，它们的坐标分别为A1到An现在需要在数轴上建立一家货仓，每天清晨，从货仓到每家商店都要运送一车商品。
 *  为了提高效率，求把货仓建在何处，可以使得货仓到每家商店的距离之和最小。
 *
 * Input:
 *  第一行输入整数N。
 *  第二行N个整数A1-An
 *
 * Output:
 *  输出一个整数，表示距离之和的最小值。
 *
 * Hints:
 *  1≤N≤1000000,0≤Ai≤1000000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4
6 2 9 1
 *
 *  output:
12
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n, a[100010];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    long long ans = 0, pos = a[(n + 1) >> 1];
    for (int i = 1; i <= n; i++) {
        ans += abs(a[i] - pos);
    }
    cout << ans << endl;
    return 0;
}