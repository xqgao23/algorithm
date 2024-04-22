/**
 * Description:
 *  一个由N个整数构成的集合{a1,a2,…,aN}
 *  在这里，我们定义集合的"大小"为集合中最大元素和集合中最小元素的差。例如，集合{1,7,4}的最大值7最小值1，所以这个集合的大小为7−1=6
 *  现在想要把这个N个数的集合划分成K个集合，使得K个集合的"大小"的总和最小。
 *
 * Input:
 *  第1行，2个正整数N,K
 *  第2行，N个整数{a1,a2,...,aN}
 *
 * Output:
 *  K个集合的"大小"的最小总和
 *
 * Hints:
 *  1≤K≤N≤5×10<4>
 *  0≤ai≤10<12>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5 2
1 10 11 2 9
 *
 *  output:
3
 *
 *  2):
 *  input:
4 2
0 7 3 13
 *
 *  output:
7
 *
 *  3):
 *  input:
3 3
1 10 100
 *
 *  output:
0
 *
 *  4):
 *  input:
10 3
1 12 19 23 28 3 32 36 41 7
 *
 *  output:
28
 *
 */

#include <algorithm>
#include <iostream>

using namespace std;
typedef long long LL;
int n, k;
LL a[50010], b[50010];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; i++) {
        b[i] = a[i + 1] - a[i];
    }
    sort(b + 1, b + n, greater<LL>());
    LL ans = a[n] - a[1];
    for (int i = 1; i < k; i++) {
        ans -= b[i];
    }
    cout << ans << endl;
    return 0;
}