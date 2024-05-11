/**
 * Description:
 *  现有数列A1,A2,…,AN修改最少的数字（可以修改成小数），使得数列严格单调递增。
 *
 * Input:
 *  第 1 行, 1 个整数N
 *  第 2 行, N个整数A1,A2,…,AN
 *
 * Output:
 *  1 个整数，表示最小修改的数字个数
 *
 * Hints:
 *  1≤N≤10<5>；1≤Ai≤10<9>；
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3
1 3 2
 *
 *  output:
1
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n, a[100010], f[100010], len;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] > f[len]) {
            f[++len] = a[i];
        } else {
            int p = lower_bound(f + 1, f + len + 1, a[i]) - f;
            f[p] = a[i];
        }
    }
    cout << n - len << endl;
    return 0;
}